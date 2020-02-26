//## begin module%3902D5F0030E.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5F0030E.cm

//## begin module%3902D5F0030E.cp preserve=no
//## end module%3902D5F0030E.cp

//## Module: LGXLNPHelper%3902D5F0030E; Package body
//## Subsystem: Channel%3902D580003C
//## Source file: c:\projects\legos\legos-0.2.3\legox\src\LGXLNPHl.cpp

//## begin module%3902D5F0030E.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3902D5F0030E.additionalIncludes

//## begin module%3902D5F0030E.includes preserve=yes
//## end module%3902D5F0030E.includes

// LGXLNPHelper
#include "LGXLNPHl.h"
//## begin module%3902D5F0030E.declarations preserve=no
//## end module%3902D5F0030E.declarations

//## begin module%3902D5F0030E.additionalDeclarations preserve=yes

#ifdef _DEBUG
#define WATCH_BYTES	1
#endif

#define LNP_HOST_MASK		0xF0
#define LNP_HOST_SHIFT		4

typedef enum {
  LNPwaitHeader,
  LNPwaitLength,
  LNPwaitData,
  LNPwaitCRC
} lnp_integrity_state_t;
//## end module%3902D5F0030E.additionalDeclarations


// Class CLGXLNPStateMachine 






CLGXLNPStateMachine::CLGXLNPStateMachine()
  //## begin CLGXLNPStateMachine::CLGXLNPStateMachine%.hasinit preserve=no
  //## end CLGXLNPStateMachine::CLGXLNPStateMachine%.hasinit
  //## begin CLGXLNPStateMachine::CLGXLNPStateMachine%.initialization preserve=yes
  //## end CLGXLNPStateMachine::CLGXLNPStateMachine%.initialization
{
  //## begin CLGXLNPStateMachine::CLGXLNPStateMachine%.body preserve=yes
	Reset();
  //## end CLGXLNPStateMachine::CLGXLNPStateMachine%.body
}


CLGXLNPStateMachine::~CLGXLNPStateMachine()
{
  //## begin CLGXLNPStateMachine::~CLGXLNPStateMachine%.body preserve=yes
  //## end CLGXLNPStateMachine::~CLGXLNPStateMachine%.body
}



//## Other Operations (implementation)
bool CLGXLNPStateMachine::HandleByte (unsigned char b)
{
  //## begin CLGXLNPStateMachine::HandleByte%956572842.body preserve=yes
	bool bFrameReady = false;

	if ((m_nBytesRead >= LNP_MAX_BUFFER_SIZE) ||	// Got too many bytes
	    (m_nState == LNPwaitHeader))				// Restart
	{
		Reset();		
	}

	m_pData[m_nBytesRead++] = b;

#ifdef WATCH_BYTES
	ATLTRACE("0x%x ", b);
#endif

	switch (m_nState) 
	{
	case LNPwaitHeader:
		// valid headers are 0xf0 .. 0xf7
		if ((b & (unsigned char) 0xf8) == (unsigned char) 0xf0) 
		{
			m_nState++;
		}
		break;
	
	case LNPwaitLength:
		m_nEndOfData = b+2;
		m_nState++;
		break;

	case LNPwaitData:
		if (m_nBytesRead == m_nEndOfData)
		{
			m_nState++;
		}
		break;

	case LNPwaitCRC:
		bFrameReady = true;
		m_nState = LNPwaitHeader;

#ifdef WATCH_BYTES
		ATLTRACE("\n");
#endif
	}

	return bFrameReady;
  //## end CLGXLNPStateMachine::HandleByte%956572842.body
}

CLGXLNPFrame * CLGXLNPStateMachine::GetFrame ()
{
  //## begin CLGXLNPStateMachine::GetFrame%956572843.body preserve=yes
	CLGXLNPFrame *pFrame = NULL;
	
	switch (m_pData[0])
	{
		case CLGXLNPFrame::ELNP_ADDRESSED_FRAME:
			pFrame = new CLGXLNPAddressedFrame(m_pData, m_nBytesRead);
			break;

		case CLGXLNPFrame::ELNP_BROADCAST_FRAME:
			pFrame = new CLGXLNPBroadcastFrame(m_pData, m_nBytesRead);
			break;

		default:
			break;
	}

	return pFrame;
  //## end CLGXLNPStateMachine::GetFrame%956572843.body
}

void CLGXLNPStateMachine::Reset ()
{
  //## begin CLGXLNPStateMachine::Reset%956572845.body preserve=yes
	m_nState = LNPwaitHeader;
	m_nBytesRead = 0;

#ifdef WATCH_BYTES
	ATLTRACE("CLGXLNPStateMachine::Reset\n");
#endif
  //## end CLGXLNPStateMachine::Reset%956572845.body
}

// Additional Declarations
  //## begin CLGXLNPStateMachine%390423830080.declarations preserve=yes
  //## end CLGXLNPStateMachine%390423830080.declarations

// Class CLGXLNPFrame 


CLGXLNPFrame::CLGXLNPFrame()
  //## begin CLGXLNPFrame::CLGXLNPFrame%.hasinit preserve=no
      : m_pBuffer(NULL)
  //## end CLGXLNPFrame::CLGXLNPFrame%.hasinit
  //## begin CLGXLNPFrame::CLGXLNPFrame%.initialization preserve=yes
  //## end CLGXLNPFrame::CLGXLNPFrame%.initialization
{
  //## begin CLGXLNPFrame::CLGXLNPFrame%.body preserve=yes
  //## end CLGXLNPFrame::CLGXLNPFrame%.body
}

CLGXLNPFrame::CLGXLNPFrame (unsigned char* pFrame, unsigned char nLength)
  //## begin CLGXLNPFrame::CLGXLNPFrame%956588848.hasinit preserve=no
      : m_pBuffer(NULL)
  //## end CLGXLNPFrame::CLGXLNPFrame%956588848.hasinit
  //## begin CLGXLNPFrame::CLGXLNPFrame%956588848.initialization preserve=yes
  //## end CLGXLNPFrame::CLGXLNPFrame%956588848.initialization
{
  //## begin CLGXLNPFrame::CLGXLNPFrame%956588848.body preserve=yes
	if (pFrame != NULL)
	{
		if (nLength == pFrame[1]+3)
		{		
			m_pBuffer = new unsigned char[nLength];
			if (m_pBuffer != NULL)
			{
				memcpy(m_pBuffer, pFrame, nLength);
			}
		}
	}
  //## end CLGXLNPFrame::CLGXLNPFrame%956588848.body
}


CLGXLNPFrame::~CLGXLNPFrame()
{
  //## begin CLGXLNPFrame::~CLGXLNPFrame%.body preserve=yes
	Free();  
  //## end CLGXLNPFrame::~CLGXLNPFrame%.body
}



//## Other Operations (implementation)
bool CLGXLNPFrame::CheckFrame ()
{
  //## begin CLGXLNPFrame::CheckFrame%956487408.body preserve=yes
	bool bResult = false;

	if (m_pBuffer != NULL)
	{
		bResult = (GetCRC() == ComputeChecksum());
	}

	return bResult;
  //## end CLGXLNPFrame::CheckFrame%956487408.body
}

unsigned char * CLGXLNPFrame::GetData ()
{
  //## begin CLGXLNPFrame::GetData%956487441.body preserve=yes
	return NULL;
  //## end CLGXLNPFrame::GetData%956487441.body
}

unsigned char CLGXLNPFrame::GetDataLength ()
{
  //## begin CLGXLNPFrame::GetDataLength%956494573.body preserve=yes
	return 0;
  //## end CLGXLNPFrame::GetDataLength%956494573.body
}

unsigned char CLGXLNPFrame::GetCRC ()
{
  //## begin CLGXLNPFrame::GetCRC%956487439.body preserve=yes
	unsigned char nCRC = 0;

	if (m_pBuffer != NULL)
	{
		nCRC = m_pBuffer[GetFrameLength()-1];
	}

	return nCRC;
  //## end CLGXLNPFrame::GetCRC%956487439.body
}

unsigned char * CLGXLNPFrame::GetFrame ()
{
  //## begin CLGXLNPFrame::GetFrame%956588841.body preserve=yes
	return m_pBuffer;
  //## end CLGXLNPFrame::GetFrame%956588841.body
}

unsigned short CLGXLNPFrame::GetFrameLength ()
{
  //## begin CLGXLNPFrame::GetFrameLength%956588842.body preserve=yes
	unsigned char nLength = 0;

	if (m_pBuffer != NULL)
	{
		nLength = m_pBuffer[1] + 3;		// header + length + CRC = 3 bytes
	}

	return nLength;
  //## end CLGXLNPFrame::GetFrameLength%956588842.body
}

CLGXLNPFrame::ELNP_FRAME_TYPE CLGXLNPFrame::GetFrameType ()
{
  //## begin CLGXLNPFrame::GetFrameType%956588843.body preserve=yes
	ELNP_FRAME_TYPE eResult = ELNP_UNKNOWN_TYPE;

	if (m_pBuffer != NULL)
	{
		eResult = (ELNP_FRAME_TYPE) m_pBuffer[0];
	}

	return eResult;
  //## end CLGXLNPFrame::GetFrameType%956588843.body
}

unsigned char CLGXLNPFrame::ComputeChecksum ()
{
  //## begin CLGXLNPFrame::ComputeChecksum%956588844.body preserve=yes
	unsigned short nLength = GetFrameLength()-1;
	unsigned char *pData = m_pBuffer;
	unsigned char a = 0xff;
	unsigned char b = 0xff;

	while (nLength > 0) 
	{
		a = a + *pData;
		b = b + a;
		pData++;
		nLength--;
	}

	return (unsigned char) (a + (b << 8));
  //## end CLGXLNPFrame::ComputeChecksum%956588844.body
}

void CLGXLNPFrame::Free ()
{
  //## begin CLGXLNPFrame::Free%956588852.body preserve=yes
	if (m_pBuffer != NULL)
	{
		delete [] m_pBuffer;
	}
	m_pBuffer = NULL;
  //## end CLGXLNPFrame::Free%956588852.body
}

// Additional Declarations
  //## begin CLGXLNPFrame%3902E00900BC.declarations preserve=yes
  //## end CLGXLNPFrame%3902E00900BC.declarations

// Class CLGXLNPAddressedFrame 

CLGXLNPAddressedFrame::CLGXLNPAddressedFrame()
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.hasinit preserve=no
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.hasinit
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.initialization preserve=yes
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.initialization
{
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.body preserve=yes
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%.body
}

CLGXLNPAddressedFrame::CLGXLNPAddressedFrame (unsigned char* pFrame, unsigned char nLength)
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.hasinit preserve=no
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.hasinit
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.initialization preserve=yes
  : CLGXLNPFrame(pFrame, nLength)
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.initialization
{
  //## begin CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.body preserve=yes
  //## end CLGXLNPAddressedFrame::CLGXLNPAddressedFrame%956588857.body
}


CLGXLNPAddressedFrame::~CLGXLNPAddressedFrame()
{
  //## begin CLGXLNPAddressedFrame::~CLGXLNPAddressedFrame%.body preserve=yes
  //## end CLGXLNPAddressedFrame::~CLGXLNPAddressedFrame%.body
}



//## Other Operations (implementation)
bool CLGXLNPAddressedFrame::Build (THOSTID nDestHostID, TPORTID nDestPortID, THOSTID nSrcHostID, TPORTID nSrcPortID, unsigned char nLength, unsigned char* pData)
{
  //## begin CLGXLNPAddressedFrame::Build%956588845.body preserve=yes
	Free();

	m_pBuffer = new unsigned char[nLength + 5];	// Header + Length + DEST + SRC + CRC = 5bytes

	bool bResult = (m_pBuffer != NULL);
	if (bResult)
	{
		m_pBuffer[0] = ELNP_ADDRESSED_FRAME;
		m_pBuffer[1] = nLength+2;		// DEST + SRC = 2bytes
		m_pBuffer[2] = ((nDestHostID << LNP_HOST_SHIFT) & LNP_HOST_MASK) + nDestPortID;					
		m_pBuffer[3] = ((nSrcHostID << LNP_HOST_SHIFT) & LNP_HOST_MASK) + nSrcPortID;						
		memcpy(GetData(), pData, nLength);
		m_pBuffer[GetFrameLength()-1] = ComputeChecksum();
	}

	return bResult;
  //## end CLGXLNPAddressedFrame::Build%956588845.body
}

unsigned char * CLGXLNPAddressedFrame::GetData ()
{
  //## begin CLGXLNPAddressedFrame::GetData%956487445.body preserve=yes
	unsigned char *pFrame = NULL;

	if (m_pBuffer != NULL)
	{
		pFrame = m_pBuffer + 4; // Data are after Header, length, DEST and SRC
	}

	return pFrame;  
  //## end CLGXLNPAddressedFrame::GetData%956487445.body
}

unsigned char CLGXLNPAddressedFrame::GetDataLength ()
{
  //## begin CLGXLNPAddressedFrame::GetDataLength%956494574.body preserve=yes
	unsigned char nLength = 0;

	if (m_pBuffer != NULL)
	{
		nLength = GetFrameLength() - 5; // Header + Length + DEST + SRC + CRC = 5 bytes		
	}

	return nLength;
  //## end CLGXLNPAddressedFrame::GetDataLength%956494574.body
}

THOSTID CLGXLNPAddressedFrame::GetDestHostID ()
{
  //## begin CLGXLNPAddressedFrame::GetDestHostID%956588853.body preserve=yes
	THOSTID nHostID = 0;

	if (m_pBuffer != NULL)
	{
		nHostID = (m_pBuffer[2] & LNP_HOST_MASK) >> LNP_HOST_SHIFT;		
	}

	return nHostID;
  //## end CLGXLNPAddressedFrame::GetDestHostID%956588853.body
}

TPORTID CLGXLNPAddressedFrame::GetDestPortID ()
{
  //## begin CLGXLNPAddressedFrame::GetDestPortID%956588854.body preserve=yes
	TPORTID nPortID = 0;

	if (m_pBuffer != NULL)
	{
		nPortID = m_pBuffer[2] & ~LNP_HOST_MASK; // modified by Alexander Cech (changed ! to ~)
	}

	return nPortID;
  //## end CLGXLNPAddressedFrame::GetDestPortID%956588854.body
}

THOSTID CLGXLNPAddressedFrame::GetSrcHostID ()
{
  //## begin CLGXLNPAddressedFrame::GetSrcHostID%956588855.body preserve=yes
	THOSTID nHostID = 0;

	if (m_pBuffer != NULL)
	{
		nHostID = (m_pBuffer[3] & LNP_HOST_MASK) >> LNP_HOST_SHIFT;
	}

	return nHostID;
  //## end CLGXLNPAddressedFrame::GetSrcHostID%956588855.body
}

TPORTID CLGXLNPAddressedFrame::GetSrcPortID ()
{
  //## begin CLGXLNPAddressedFrame::GetSrcPortID%956588856.body preserve=yes
	TPORTID nPortID = 0;

	if (m_pBuffer != NULL)
	{
		nPortID = m_pBuffer[3] & ~LNP_HOST_MASK; // modified by Alexander Cech (changed ! to ~)
	}

	return nPortID;
  //## end CLGXLNPAddressedFrame::GetSrcPortID%956588856.body
}

// Additional Declarations
  //## begin CLGXLNPAddressedFrame%3902E0940347.declarations preserve=yes
  //## end CLGXLNPAddressedFrame%3902E0940347.declarations

// Class CLGXLNPBroadcastFrame 

CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame()
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.hasinit preserve=no
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.hasinit
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.initialization preserve=yes
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.initialization
{
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.body preserve=yes
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%.body
}

CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame (unsigned char* pFrame, unsigned char nLength)
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.hasinit preserve=no
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.hasinit
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.initialization preserve=yes
	: CLGXLNPFrame(pFrame, nLength)
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.initialization
{
  //## begin CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.body preserve=yes
  //## end CLGXLNPBroadcastFrame::CLGXLNPBroadcastFrame%956588858.body
}


CLGXLNPBroadcastFrame::~CLGXLNPBroadcastFrame()
{
  //## begin CLGXLNPBroadcastFrame::~CLGXLNPBroadcastFrame%.body preserve=yes
  //## end CLGXLNPBroadcastFrame::~CLGXLNPBroadcastFrame%.body
}



//## Other Operations (implementation)
bool CLGXLNPBroadcastFrame::Build (unsigned char nLength, unsigned char* pData)
{
  //## begin CLGXLNPBroadcastFrame::Build%956588847.body preserve=yes
	Free();

	m_pBuffer = new unsigned char[nLength + 3];	// Header + Length + CRC = 3bytes

	bool bResult = (m_pBuffer != NULL);
	if (bResult)
	{
		m_pBuffer[0] = ELNP_BROADCAST_FRAME;
		m_pBuffer[1] = nLength;		
		memcpy(GetData(), pData, nLength);
		m_pBuffer[GetFrameLength()-1] = ComputeChecksum();
	}

	return bResult;
  //## end CLGXLNPBroadcastFrame::Build%956588847.body
}

unsigned char * CLGXLNPBroadcastFrame::GetData ()
{
  //## begin CLGXLNPBroadcastFrame::GetData%956588849.body preserve=yes
	unsigned char *pFrame = NULL;

	if (m_pBuffer != NULL)
	{
		pFrame = m_pBuffer + 2; // Data are after Header and length
	}

	return pFrame;  
  //## end CLGXLNPBroadcastFrame::GetData%956588849.body
}

unsigned char CLGXLNPBroadcastFrame::GetDataLength ()
{
  //## begin CLGXLNPBroadcastFrame::GetDataLength%956588851.body preserve=yes
	unsigned char nLength = 0;

	if (m_pBuffer != NULL)
	{
		nLength = GetFrameLength() - 3; // Header + Length + CRC = 3 bytes		
	}

	return nLength;
  //## end CLGXLNPBroadcastFrame::GetDataLength%956588851.body
}

// Additional Declarations
  //## begin CLGXLNPBroadcastFrame%390443D80096.declarations preserve=yes
  //## end CLGXLNPBroadcastFrame%390443D80096.declarations

//## begin module%3902D5F0030E.epilog preserve=yes
//## end module%3902D5F0030E.epilog
