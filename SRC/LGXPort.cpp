//## begin module%3902D5DE0218.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5DE0218.cm

//## begin module%3902D5DE0218.cp preserve=no
//## end module%3902D5DE0218.cp

//## Module: LGXPort%3902D5DE0218; Package body
//## Subsystem: Port%3902D580003C
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXPort.cpp

//## begin module%3902D5DE0218.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3902D5DE0218.additionalIncludes

//## begin module%3902D5DE0218.includes preserve=yes
//## end module%3902D5DE0218.includes

// ILGXHandler
#include "ILGXHndl.h"
// LGXPort
#include "LGXPort.h"


//## begin module%3902D5DE0218.declarations preserve=no
//## end module%3902D5DE0218.declarations

//## begin module%3902D5DE0218.additionalDeclarations preserve=yes
//## end module%3902D5DE0218.additionalDeclarations


// Class CLGXPort 







CLGXPort::CLGXPort()
  //## begin CLGXPort::CLGXPort%.hasinit preserve=no
      : m_nPCHostID(-1), m_nHostID(-1), m_nPortID(-1)
  //## end CLGXPort::CLGXPort%.hasinit
  //## begin CLGXPort::CLGXPort%.initialization preserve=yes
  //## end CLGXPort::CLGXPort%.initialization
{
  //## begin CLGXPort::CLGXPort%.body preserve=yes
  //## end CLGXPort::CLGXPort%.body
}


CLGXPort::~CLGXPort()
{
  //## begin CLGXPort::~CLGXPort%.body preserve=yes
	m_HandlersMap.clear();	
  //## end CLGXPort::~CLGXPort%.body
}



//## Other Operations (implementation)
bool CLGXPort::Init (THOSTID nPCHostID, THOSTID nHostID, TPORTID nPortID, CLGXTowerMgr *pTowerMgr)
{
  //## begin CLGXPort::Init%956487432.body preserve=yes
	m_nPCHostID = nPCHostID;
	m_nHostID = nHostID;
	m_nPortID = nPortID;	
	m_pTowerMgr = pTowerMgr;
	return true;
  //## end CLGXPort::Init%956487432.body
}

bool CLGXPort::Send (TPORTID nSrcPortID, unsigned char nLength, unsigned char *pData)
{
  //## begin CLGXPort::Send%956487433.body preserve=yes
  	bool bResult = false;

	CLGXLNPAddressedFrame frame;
	frame.Build(m_nHostID,
	            m_nPortID,
				m_nPCHostID,
				nSrcPortID,
	            nLength, 
	            pData);

	if (m_pTowerMgr != NULL)	
	{
		bResult = m_pTowerMgr->Send(frame.GetFrameLength(), frame.GetFrame());
	}	

	return true;
  //## end CLGXPort::Send%956487433.body
}

bool CLGXPort::Dispatch (CLGXLNPAddressedFrame *pFrame)
{
  //## begin CLGXPort::Dispatch%956487434.body preserve=yes
	bool bResult = true;

	m_CS.Lock();
	THandlersMap::iterator iter = m_HandlersMap.find(pFrame->GetDestPortID());
	if (iter != m_HandlersMap.end())
	{
		ILGXHandler *pHandler = (*iter).second;
		if (pHandler != NULL)  
		{
			bResult = pHandler->TreatData(pFrame);
		}
	}
	m_CS.Unlock();

	return bResult;
  //## end CLGXPort::Dispatch%956487434.body
}

TPORTID CLGXPort::GetPortID ()
{
  //## begin CLGXPort::GetPortID%956487435.body preserve=yes
  	return m_nPortID;
  //## end CLGXPort::GetPortID%956487435.body
}

THOSTID CLGXPort::GetHostID ()
{
  //## begin CLGXPort::GetHostID%956487436.body preserve=yes
  	return m_nHostID;  
  //## end CLGXPort::GetHostID%956487436.body
}

void CLGXPort::RegisterHandler (TPORTID nSessionID, ILGXHandler *pHandler)
{
  //## begin CLGXPort::RegisterHandler%956487437.body preserve=yes
	m_CS.Lock();
	m_HandlersMap.insert(THandlersMap::value_type(nSessionID, pHandler));
	m_CS.Unlock();
  //## end CLGXPort::RegisterHandler%956487437.body
}

void CLGXPort::UnregisterHandler (ILGXHandler *pHandler)
{
  //## begin CLGXPort::UnregisterHandler%956487438.body preserve=yes
	m_CS.Lock();
	THandlersMap::iterator iter = m_HandlersMap.find(pHandler->GetSessionID());
	if (iter != m_HandlersMap.end())
	{
		m_HandlersMap.erase(iter);
	}
	m_CS.Unlock();
  //## end CLGXPort::UnregisterHandler%956487438.body
}

// Additional Declarations
  //## begin CLGXPort%3902C589019D.declarations preserve=yes
  //## end CLGXPort%3902C589019D.declarations

// Class ILGXHandler 

ILGXHandler::~ILGXHandler()
{
  //## begin ILGXHandler::~ILGXHandler%.body preserve=yes
  //## end ILGXHandler::~ILGXHandler%.body
}


// Additional Declarations
  //## begin ILGXHandler%3902D01003A1.declarations preserve=yes
  //## end ILGXHandler%3902D01003A1.declarations

//## begin module%3902D5DE0218.epilog preserve=yes
//## end module%3902D5DE0218.epilog
