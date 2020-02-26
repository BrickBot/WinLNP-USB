//## begin module%3902D5C401FC.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3902D5C401FC.cm

//## begin module%3902D5C401FC.cp preserve=no
//## end module%3902D5C401FC.cp

//## Module: LGXHost%3902D5C401FC; Package body
//## Subsystem: Host%3902D5720367
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXHost.cpp

//## begin module%3902D5C401FC.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3902D5C401FC.additionalIncludes

//## begin module%3902D5C401FC.includes preserve=yes
//## end module%3902D5C401FC.includes

// LGXPort
#include "LGXPort.h"
// LGXHost
#include "LGXHost.h"


//## begin module%3902D5C401FC.declarations preserve=no
//## end module%3902D5C401FC.declarations

//## begin module%3902D5C401FC.additionalDeclarations preserve=yes
#define NB_PROGRAMS	8
//## end module%3902D5C401FC.additionalDeclarations


// Class CLGXHost 





CLGXHost::CLGXHost()
  //## begin CLGXHost::CLGXHost%.hasinit preserve=no
      : m_nPCHostID(-1), m_nHostID(-1)
  //## end CLGXHost::CLGXHost%.hasinit
  //## begin CLGXHost::CLGXHost%.initialization preserve=yes
  //## end CLGXHost::CLGXHost%.initialization
{
  //## begin CLGXHost::CLGXHost%.body preserve=yes
  //## end CLGXHost::CLGXHost%.body
}


CLGXHost::~CLGXHost()
{
  //## begin CLGXHost::~CLGXHost%.body preserve=yes
	TPortsMap::iterator iter = m_PortsMap.begin();

	for (; iter != m_PortsMap.end(); iter++)
	{
		CLGXPort *pPort = (*iter).second;
		delete pPort;
	}

	m_PortsMap.clear();
  //## end CLGXHost::~CLGXHost%.body
}



//## Other Operations (implementation)
bool CLGXHost::Init (THOSTID nPCHostID, THOSTID nHostID, CLGXTowerMgr *pTowerMgr)
{
  //## begin CLGXHost::Init%956487414.body preserve=yes
	m_nPCHostID = nPCHostID;
	m_nHostID = nHostID;
	m_pTowerMgr = pTowerMgr;
	return true;
  //## end CLGXHost::Init%956487414.body
}

CLGXPort * CLGXHost::GetPort (TPORTID nPortID)
{
  //## begin CLGXHost::GetPort%956487415.body preserve=yes
	CLGXPort *pPort = NULL;

	TPortsMap::iterator iter = m_PortsMap.find(nPortID);
 
	if (iter != m_PortsMap.end())
	{
		pPort = (*iter).second;
	}
	else
	{
		pPort = new CLGXPort;
		if (pPort != NULL)
		{
			pPort->Init(m_nPCHostID, m_nHostID, nPortID, m_pTowerMgr);
			m_PortsMap.insert(TPortsMap::value_type(nPortID, pPort));			
		}
	}

	return pPort;
  //## end CLGXHost::GetPort%956487415.body
}

bool CLGXHost::Dispatch (CLGXLNPAddressedFrame *pFrame)
{
  //## begin CLGXHost::Dispatch%956487418.body preserve=yes
	bool bResult = true;

	TPORTID nPortID = pFrame->GetDestPortID();

	TPortsMap::iterator iter = m_PortsMap.find(nPortID);

	if (iter != m_PortsMap.end())
	{
		CLGXPort *pPort = (*iter).second;
		if (pPort != NULL)  
		{
			bResult = pPort->Dispatch(pFrame);
		}
	}
	return bResult;
  //## end CLGXHost::Dispatch%956487418.body
}

THOSTID CLGXHost::GetHostID ()
{
  //## begin CLGXHost::GetHostID%956487419.body preserve=yes
	return m_nHostID;
  //## end CLGXHost::GetHostID%956487419.body
}

// Additional Declarations
  //## begin CLGXHost%3902C57E00D9.declarations preserve=yes
  //## end CLGXHost%3902C57E00D9.declarations

//## begin module%3902D5C401FC.epilog preserve=yes
//## end module%3902D5C401FC.epilog


// Detached code regions:
// WARNING: this code will be lost if code is regenerated.
#if 0
//## begin CLGXHost::GetProgram%956487417.body preserve=no
	if (nProgramID >= NB_PROGRAMS)
	{
		return NULL;
	}

	return &m_aPrograms[nProgramID];
//## end CLGXHost::GetProgram%956487417.body

#endif
