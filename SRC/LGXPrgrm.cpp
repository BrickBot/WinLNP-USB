//## begin module%3902D5CD00DD.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5CD00DD.cm

//## begin module%3902D5CD00DD.cp preserve=no
//## end module%3902D5CD00DD.cp

//## Module: LGXProgram%3902D5CD00DD; Package body
//## Subsystem: Host%3902D5720367
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXPrgrm.cpp

//## begin module%3902D5CD00DD.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3902D5CD00DD.additionalIncludes

//## begin module%3902D5CD00DD.includes preserve=yes
//## end module%3902D5CD00DD.includes

// LGXHost
#include "LGXHost.h"
// LGXSystem
#include "LGXSystm.h"
// LGXPort
#include "LGXPort.h"
// LGXProgram
#include "LGXPrgrm.h"


//## begin module%3902D5CD00DD.declarations preserve=no
//## end module%3902D5CD00DD.declarations

//## begin module%3902D5CD00DD.additionalDeclarations preserve=yes
#define WAIT_FOR_ACK_TIMEOUT	5000
#define MAX_DATA_CHUNK 0xf8   	  //!< maximum data bytes/packet for boot protocol

#define DEFAULT_DEST  	0
#define DEFAULT_PROGRAM	0
#define DEFAULT_SRCPORT 0
#define DEFAULT_PRIORITY 10

typedef enum 
{
  CMDacknowledge,     	//!< 1:
  CMDdelete, 	      	//!< 1+ 1: b[nr]
  CMDcreate, 	      	//!< 1+12: b[nr] s[textsize] s[datasize] s[bsssize] s[stacksize] s[start] b[prio]
  CMDoffsets, 	      	//!< 1+ 7: b[nr] s[text] s[data] s[bss]
  CMDdata,   	      	//!< 1+>3: b[nr] s[offset] array[data]
  CMDrun,     	      	//!< 1+ 1: b[nr]
  CMDlast     	      	//!< ?
} packet_cmd_t;

unsigned short nthos(unsigned short n)
{
	unsigned char val[2];
	val[0] = ((unsigned char*)&n)[1];
	val[1] = ((unsigned char*)&n)[0];
	return *((unsigned short*)&val);
}
//## end module%3902D5CD00DD.additionalDeclarations


// Class CLGXProgramMgr 






CLGXProgramMgr::CLGXProgramMgr()
  //## begin CLGXProgramMgr::CLGXProgramMgr%.hasinit preserve=no
      : m_pAckFrame(NULL), m_hAckEvent(NULL), m_pLGXSystem(NULL)
  //## end CLGXProgramMgr::CLGXProgramMgr%.hasinit
  //## begin CLGXProgramMgr::CLGXProgramMgr%.initialization preserve=yes
  //## end CLGXProgramMgr::CLGXProgramMgr%.initialization
{
  //## begin CLGXProgramMgr::CLGXProgramMgr%.body preserve=yes
  //## end CLGXProgramMgr::CLGXProgramMgr%.body
}


CLGXProgramMgr::~CLGXProgramMgr()
{
  //## begin CLGXProgramMgr::~CLGXProgramMgr%.body preserve=yes
	if (m_hAckEvent != NULL)
	{
		CloseHandle(m_hAckEvent);
	}
  //## end CLGXProgramMgr::~CLGXProgramMgr%.body
}



//## Other Operations (implementation)
bool CLGXProgramMgr::Init (CLGXSystem *pLGXSystem)
{
  //## begin CLGXProgramMgr::Init%956494572.body preserve=yes
	m_pLGXSystem = pLGXSystem;
	m_hAckEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	return (m_pLGXSystem != NULL && m_hAckEvent != NULL);
  //## end CLGXProgramMgr::Init%956494572.body
}

bool CLGXProgramMgr::Delete (THOSTID nHostID, BYTE nPrgID)
{
  //## begin CLGXProgramMgr::Delete%956487420.body preserve=yes
	bool bResult = false;
	
	CLGXPort *pPort = GetSystemPort(nHostID);
	if (pPort != NULL)
	{
		m_CS.Lock();
		bResult = DeleteImpl(pPort, nPrgID);
		m_CS.Unlock();
		pPort->UnregisterHandler(this);
	}

	return bResult;
  //## end CLGXProgramMgr::Delete%956487420.body
}

bool CLGXProgramMgr::Run (THOSTID nHostID, BYTE nPrgID)
{
  //## begin CLGXProgramMgr::Run%956487421.body preserve=yes
	bool bResult = false;
	
	CLGXPort *pPort = GetSystemPort(nHostID);
	if (pPort != NULL)
	{
		unsigned char msg[2];		
		msg[0] = CMDrun;
		msg[1] = nPrgID;
		
		m_CS.Lock();
		if (pPort->Send(0, 2, msg))
		{
			bResult = WaitForAck();		
		}
		m_CS.Unlock();

		pPort->UnregisterHandler(this);
	}

	return bResult;
  //## end CLGXProgramMgr::Run%956487421.body
}

bool CLGXProgramMgr::Download (THOSTID nHostID, BYTE nPrgID, char *szFileName)
{
  //## begin CLGXProgramMgr::Download%956487423.body preserve=yes
	bool bResult = false;
	lx_t lx;

	CLGXPort *pPort = GetSystemPort(nHostID);
	if (pPort != NULL)
	{
		if (ReadLXFile(&lx, szFileName))
		{
			m_CS.Lock();
			if (DeleteImpl(pPort, nPrgID))
			{
				unsigned char buffer[13];
				buffer[ 0]=CMDcreate;
				buffer[ 1]=nPrgID; 
				buffer[ 2]=lx.text_size>>8;
				buffer[ 3]=lx.text_size & 0xff;
				buffer[ 4]=lx.data_size>>8;
				buffer[ 5]=lx.data_size & 0xff;
				buffer[ 6]=lx.bss_size>>8;
				buffer[ 7]=lx.bss_size & 0xff;
				buffer[ 8]=lx.stack_size>>8;
				buffer[ 9]=lx.stack_size & 0xff;
				buffer[10]=lx.offset >> 8;  	// start offset from text segment
				buffer[11]=lx.offset & 0xff; 
				buffer[12]=DEFAULT_PRIORITY;

  				if (pPort->Send(0, 13, buffer))
				{
					if (WaitForAck())
					{
						if (m_pAckFrame != NULL &&
							m_pAckFrame->GetDataLength() == 8)
						{
							unsigned char *pAckData = m_pAckFrame->GetData();						
							unsigned short nReloc = (pAckData[2]<<8)|pAckData[3];

							Relocate(&lx, nReloc);
							bResult = DownloadText(pPort, nPrgID, &lx);
						}
					}
				}
			}
			m_CS.Unlock();
		}

		pPort->UnregisterHandler(this);
	}

	return bResult;
  //## end CLGXProgramMgr::Download%956487423.body
}

bool CLGXProgramMgr::TreatData (CLGXLNPFrame *pFrame)
{
  //## begin CLGXProgramMgr::TreatData%956487424.body preserve=yes
	unsigned char *pData = pFrame->GetData();

	if (pData[0] == 0x00)
	{
		m_pAckFrame = pFrame;
		SetEvent(m_hAckEvent);
		return false;
	}	

	return true;
  //## end CLGXProgramMgr::TreatData%956487424.body
}

TPORTID CLGXProgramMgr::GetSessionID ()
{
  //## begin CLGXProgramMgr::GetSessionID%958835228.body preserve=yes
	return 0;
  //## end CLGXProgramMgr::GetSessionID%958835228.body
}

void CLGXProgramMgr::Relocate (lx_t *lx, unsigned short base)
{
  //## begin CLGXProgramMgr::Relocate%956494575.body preserve=yes
	unsigned short diff=base-lx->base;
	int i;
  
	for(i=0; i<lx->num_relocs; i++) 
	{
		unsigned char *ptr=lx->text+lx->reloc[i];
		unsigned short off =(ptr[0]<<8) | ptr[1];		
    
		off+=diff;
		ptr[0]=off >> 8;
		ptr[1]=off & 0xff;
	}
  
	lx->base=base;
  //## end CLGXProgramMgr::Relocate%956494575.body
}

bool CLGXProgramMgr::ReadLXFile (lx_t *lx, const CString &szFileName)
{
  //## begin CLGXProgramMgr::ReadLXFile%956494576.body preserve=yes
	int i;	
	unsigned char buffer[6];
	unsigned short tmp;
    
	FILE *file = fopen(szFileName,"r");
	if(file<0)
	{
		return false;
	}
	  
	// check ID
	fread((void*)buffer, 6, 1,file);
	if(strcmp((char*)buffer,"legOS")) 
	{
		fclose(file);
		return false;
	}
  
	// read header data in MSB
	for(i=0; i<HEADER_FIELDS; i++) 
	{
		fread((void*)&tmp, 2, 1,file);		
		((unsigned short*)lx)[i]= nthos(tmp);
	}
  	
	lx->text = (unsigned char*) malloc(lx->text_size + lx->data_size);
	if (lx->text == NULL) 
	{
		fclose(file);		
		return false;
	}

	// read program text (is MSB, because H8 is MSB)
	fread((void*)lx->text, lx->text_size + lx->data_size, 1,file);
	
	// read relocation data in MSB
	if (lx->num_relocs) 
	{
		lx->reloc = (unsigned short*) malloc(sizeof(unsigned short)*lx->num_relocs);
		if (lx->reloc == NULL) 
		{
			fclose(file);
			free(lx->text);
			return false;
		}

		for (i=0; i<lx->num_relocs; i++) 
		{
			fread((void*)&tmp, 2, 1,file);
			lx->reloc[i] = nthos(tmp);
		}
	}
	
	return true;
  //## end CLGXProgramMgr::ReadLXFile%956494576.body
}

bool CLGXProgramMgr::DownloadText (CLGXPort *pPort, BYTE nPrgID, lx_t *lx)
{
  //## begin CLGXProgramMgr::DownloadText%956494577.body preserve=yes
	unsigned char buffer[256+3];
	size_t i;
	size_t chunkSize;
	size_t totalSize = lx->text_size + lx->data_size;

	buffer[0] = CMDdata;
	buffer[1] = nPrgID;

	for (i=0; i<totalSize; i+=chunkSize) 
	{
		chunkSize=totalSize-i;
		if (chunkSize>MAX_DATA_CHUNK)
		{
			chunkSize=MAX_DATA_CHUNK;
		}

		buffer[2]= i >> 8;
		buffer[3]= i &  0xff;
		memcpy(buffer+4,lx->text + i,chunkSize);
		if (!pPort->Send(0, chunkSize+4, buffer))
		{	
			return false;
		}
	}							

	return true;
  //## end CLGXProgramMgr::DownloadText%956494577.body
}

bool CLGXProgramMgr::WaitForAck ()
{
  //## begin CLGXProgramMgr::WaitForAck%956572846.body preserve=yes
	return (WaitForSingleObject(m_hAckEvent, WAIT_FOR_ACK_TIMEOUT) == WAIT_OBJECT_0);
  //## end CLGXProgramMgr::WaitForAck%956572846.body
}

CLGXPort * CLGXProgramMgr::GetSystemPort (THOSTID nHostID)
{
  //## begin CLGXProgramMgr::GetSystemPort%958835229.body preserve=yes
	CLGXPort *pPort = NULL;

	if (m_pLGXSystem != NULL)
	{
		CLGXHost *pHost = m_pLGXSystem->GetHost(nHostID);
		if (pHost != NULL)
		{
			pPort = pHost->GetPort(0);
			if (pPort != NULL)
			{				
				pPort->RegisterHandler(0, this);
			}
		}
	}

	return pPort;
  //## end CLGXProgramMgr::GetSystemPort%958835229.body
}

bool CLGXProgramMgr::DeleteImpl (CLGXPort *pPort, BYTE nPrgID)
{
  //## begin CLGXProgramMgr::DeleteImpl%958835231.body preserve=yes
	bool bResult = false;

	unsigned char msg[2];		
	msg[0] = CMDdelete;
	msg[1] = nPrgID;
	if (pPort->Send(0, 2, msg))
	{
		bResult = WaitForAck();
	}

	return bResult;
  //## end CLGXProgramMgr::DeleteImpl%958835231.body
}

// Additional Declarations
  //## begin CLGXProgramMgr%3902C5A700EC.declarations preserve=yes
  //## end CLGXProgramMgr%3902C5A700EC.declarations

//## begin module%3902D5CD00DD.epilog preserve=yes
//## end module%3902D5CD00DD.epilog
