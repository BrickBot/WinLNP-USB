//## begin module%3902D62E0186.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D62E0186.cm

//## begin module%3902D62E0186.cp preserve=no
//## end module%3902D62E0186.cp

//## Module: LGXTower%3902D62E0186; Package body
//## Subsystem: Tower%3902D5790122
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXTower.cpp

//## begin module%3902D62E0186.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3902D62E0186.additionalIncludes

//## begin module%3902D62E0186.includes preserve=yes
//## end module%3902D62E0186.includes

// LGXSystem
#include "LGXSystm.h"
// LGXTower
#include "LGXTower.h"

//## begin module%3902D62E0186.declarations preserve=no
//## end module%3902D62E0186.declarations

//## begin module%3902D62E0186.additionalDeclarations preserve=yes
#define TOWER_KEEP_ALIVE_CHAR	0xFF
#define TOWER_KEEP_ALIVE_DELAY	2000	// ms
//## end module%3902D62E0186.additionalDeclarations


// Class CLGXTowerMgr 

// modified for USB support by Alexander Cech, based on Jin Satos modifications to legOS



// added by Alexander Cech (based upon Jin Sato's modification to legOS)
#define LNP_BYTE_TIME  	5					 //!< time to transmit a byte
#define REPLY_TIMEOUT	750000 				 //!< timeout for reply [microseconds (usec)]
#define BYTE_TIME		(1000*LNP_BYTE_TIME) //!< time to transmit a byte. [microseconds (usec)]
int	USBReadFile( HANDLE h , unsigned char *pBuffer,	int nBufferSize, LPDWORD pReadSize, LPVOID pX )
{
	// we use MILLIseconds here
	int		nRet = 0;
	DWORD	count = 0;
	DWORD	startticks,nowticks;
	unsigned long total,elapsed;

	total=(REPLY_TIMEOUT+nBufferSize*BYTE_TIME + 500) / 1000;

	startticks = GetTickCount();
	while ( count == 0 ) {
		nRet = ReadFile( h, pBuffer, nBufferSize, &count , (LPOVERLAPPED)pX );

		nowticks = GetTickCount();
		if (nowticks < startticks) startticks = nowticks; // in case system timer has just wrapped around [~after 50 days continues run]...
		elapsed = (nowticks - startticks);
		if  ( elapsed > total ) break;
	}
	*pReadSize = count;
	return nRet;
}




CLGXTowerMgr::CLGXTowerMgr()
  //## begin CLGXTowerMgr::CLGXTowerMgr%.hasinit preserve=no
      : m_hComm(INVALID_HANDLE_VALUE), m_hKeepAliveThread(NULL), m_bIsKeepAliveRunning(false), m_pSystem(NULL), m_bUseUSB(false)
	  // m_bUseUSB added by Alexander Cech
  //## end CLGXTowerMgr::CLGXTowerMgr%.hasinit
  //## begin CLGXTowerMgr::CLGXTowerMgr%.initialization preserve=yes
  //## end CLGXTowerMgr::CLGXTowerMgr%.initialization
{
  //## begin CLGXTowerMgr::CLGXTowerMgr%.body preserve=yes
  //## end CLGXTowerMgr::CLGXTowerMgr%.body
}


CLGXTowerMgr::~CLGXTowerMgr()
{
  //## begin CLGXTowerMgr::~CLGXTowerMgr%.body preserve=yes
	CloseHandle(m_hKeepAliveThread);
  //## end CLGXTowerMgr::~CLGXTowerMgr%.body
}



//## Other Operations (implementation)
bool CLGXTowerMgr::Init (unsigned char nComPort, unsigned long nParity, CLGXSystem *pSystem)
{
  //## begin CLGXTowerMgr::Init%956487426.body preserve=yes
	bool bResult = false;

	m_pSystem = NULL;

	if (pSystem != NULL)
	{
		m_pSystem = pSystem;
		m_bUseUSB = nComPort > 100; // added by Alexander Cech
		bResult = InitComm(nComPort, nParity) && InitThreads();
	}

	return bResult;
  
  //## end CLGXTowerMgr::Init%956487426.body
}

void CLGXTowerMgr::Close ()
{
  //## begin CLGXTowerMgr::Close%956487448.body preserve=yes
	if (m_hComm != INVALID_HANDLE_VALUE)
	{
		CloseHandle(m_hComm);
		m_hComm = INVALID_HANDLE_VALUE;
	}
  //## end CLGXTowerMgr::Close%956487448.body
}

void CLGXTowerMgr::Sleep ()
{
  //## begin CLGXTowerMgr::Sleep%956487427.body preserve=yes
	m_CS.Lock();
	if (m_bIsKeepAliveRunning)
	{
		SuspendThread(m_hKeepAliveThread);
		m_bIsKeepAliveRunning = false;
	}
	m_CS.Unlock();
  //## end CLGXTowerMgr::Sleep%956487427.body
}

void CLGXTowerMgr::WakeUp ()
{
  //## begin CLGXTowerMgr::WakeUp%956487428.body preserve=yes
	m_CS.Lock();
	if (!m_bIsKeepAliveRunning)
	{
		ResumeThread(m_hKeepAliveThread);
		m_bIsKeepAliveRunning = true;
	}
	m_CS.Unlock();
  //## end CLGXTowerMgr::WakeUp%956487428.body
}

bool CLGXTowerMgr::IsRunning ()
{
  //## begin CLGXTowerMgr::IsRunning%958908577.body preserve=yes
	bool bResult;

	m_CS.Lock();
	bResult = m_bIsKeepAliveRunning;
	m_CS.Unlock();

	return bResult;
  //## end CLGXTowerMgr::IsRunning%958908577.body
}

bool CLGXTowerMgr::Send (unsigned short nLength, unsigned char *pData)
{
  //## begin CLGXTowerMgr::Send%956487429.body preserve=yes
	bool bResult;
  	unsigned long nSend;  	

	m_CS.Lock();

#ifdef WATCH_BYTES
	for (int i=0; i<nLength;i++)
	{
		ATLTRACE("0x%x ", pData[i]);
	}	
#endif

	bResult = (WriteFile(m_hComm, pData, nLength, &nSend, NULL) && (nSend == nLength));
	m_CS.Unlock();

	return bResult;
  //## end CLGXTowerMgr::Send%956487429.body
}

unsigned long CLGXTowerMgr::RCXSend (unsigned char *pOutData, unsigned short nOutLength, unsigned char *pInData, unsigned short &nInLength)
{
  //## begin CLGXTowerMgr::RCXSend%956494586.body preserve=yes
	return 0;
  //## end CLGXTowerMgr::RCXSend%956494586.body
}


bool CLGXTowerMgr::InitComm (unsigned char nComPort, unsigned long nParity)
{
	//## begin CLGXTowerMgr::InitComm%956494578.body preserve=yes
	if ((nComPort > 9 || nComPort < 0) && (!m_bUseUSB)) // modified by Alexander Cech
	{
		return false;
	}

	Close();
	
	// char szPortName[] = "COMX";
	char szPortName[32]; // modified by Alexander Cech

	if (m_bUseUSB) {
		sprintf(szPortName, "%s%d", "\\\\.\\legotower", nComPort-100); // 101 would read: \\.\legotower1
	} else {
		strcpy(szPortName, "COMX");
		szPortName[3] = '0' + (unsigned char)nComPort;	
		szPortName[4] = 0;	
	}

	m_hComm = CreateFile(szPortName,  
	                     GENERIC_READ | GENERIC_WRITE, 
	                     0, 
	                     0, 
	                     OPEN_EXISTING,
	                     0,
	                     0);

	if (m_hComm == INVALID_HANDLE_VALUE)
	{
		return false;
	}
   
	if (! m_bUseUSB) {	// added by Alexander Cech
		DCB dcb;
		FillMemory(&dcb, sizeof(dcb), 0);
		if (!GetCommState(m_hComm, &dcb)) 
		{
			// Error in GetCommState
			return false;
		}

		// 2400 bps, 8 datat bits + 1 stop bit, parity ODD
		dcb.BaudRate = CBR_2400;
		dcb.ByteSize = 8;
		dcb.Parity = (unsigned char)nParity;
		dcb.StopBits = ONESTOPBIT;

		// Set new state.
		if (!SetCommState(m_hComm, &dcb))
		{
			return false;
		}
		
		if (!SetCommMask(m_hComm, EV_RXCHAR))   
		{
			return false;
		}

		COMMTIMEOUTS timeouts;
		timeouts.ReadIntervalTimeout = 0; 
		timeouts.ReadTotalTimeoutMultiplier = 0;
		timeouts.ReadTotalTimeoutConstant = 20;
		timeouts.WriteTotalTimeoutMultiplier = 0;
		timeouts.WriteTotalTimeoutConstant = 1000;

		return (SetCommTimeouts(m_hComm, &timeouts) != FALSE);
	} else {
		return true;
	}
  //## end CLGXTowerMgr::InitComm%956494578.body
}

bool CLGXTowerMgr::InitThreads ()
{
  //## begin CLGXTowerMgr::InitThreads%956494579.body preserve=yes
	bool bResult = false;

	DWORD dwThreadID;

	CreateThread(NULL,
	             0,
	             CLGXTowerMgr::StartWatcher,
	             (LPVOID) this,
	             0,
				 &dwThreadID);
 
	m_hKeepAliveThread = CreateThread(NULL,
	                     0,
	                     CLGXTowerMgr::StartKeepAlive,
	                     (LPVOID) this,
	                     0,
	                     &dwThreadID);	
	m_bIsKeepAliveRunning = true;

	return bResult;
  //## end CLGXTowerMgr::InitThreads%956494579.body
}

void CLGXTowerMgr::LineWatcher ()
{
  //## begin CLGXTowerMgr::LineWatcher%956487430.body preserve=yes
	unsigned char b;
	DWORD dwRead;	

	if (m_pSystem == NULL)
	{
		return;
	}
	
	while (1)
	{
		::Sleep(50);
		int res; // modified by Alexander Cech
		if (m_bUseUSB) {
			res = USBReadFile(m_hComm, &b, 1, &dwRead, NULL);
		} else {
			res = ReadFile(m_hComm, &b, 1, &dwRead, NULL);
		}
		if (res && (dwRead == 1))
		{
			m_pSystem->HandleByte(b);
		}		
	}

  //## end CLGXTowerMgr::LineWatcher%956487430.body
}

void CLGXTowerMgr::KeepAliveRoutine ()
{
  //## begin CLGXTowerMgr::KeepAliveRoutine%956487431.body preserve=yes
	unsigned char cKeepAliveByte = TOWER_KEEP_ALIVE_CHAR;

	while (1)
	{		
		Send(1, &cKeepAliveByte);
		::Sleep(TOWER_KEEP_ALIVE_DELAY);
	}
  //## end CLGXTowerMgr::KeepAliveRoutine%956487431.body
}

DWORD WINAPI CLGXTowerMgr::StartWatcher (LPVOID pData)
{
  //## begin CLGXTowerMgr::StartWatcher%956494580.body preserve=yes
	if (pData != NULL)
	{
		((CLGXTowerMgr*)pData)->LineWatcher();
	}
	return 0;
  //## end CLGXTowerMgr::StartWatcher%956494580.body
}

DWORD WINAPI CLGXTowerMgr::StartKeepAlive (LPVOID pData)
{
  //## begin CLGXTowerMgr::StartKeepAlive%956494581.body preserve=yes
	if (pData != NULL)
	{
		((CLGXTowerMgr*)pData)->KeepAliveRoutine();
	}
	return 0;
  //## end CLGXTowerMgr::StartKeepAlive%956494581.body
}

// Additional Declarations
  //## begin CLGXTowerMgr%3902C571022F.declarations preserve=yes
  //## end CLGXTowerMgr%3902C571022F.declarations

//## begin module%3902D62E0186.epilog preserve=yes
//## end module%3902D62E0186.epilog
