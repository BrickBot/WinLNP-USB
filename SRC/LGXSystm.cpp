//## begin module%3921965A0364.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module%3921965A0364.cm

//## begin module%3921965A0364.cp preserve=no
//## end module%3921965A0364.cp

//## Module: LGXSystem%3921965A0364; Package body
//## Subsystem: System%3902D56B01EA
//## Source file: c:\projects\legos\legos-0.2.3\winlnp\src\LGXSystm.cpp

//## begin module%3921965A0364.additionalIncludes preserve=no
#include "stdafx.h"
//## end module%3921965A0364.additionalIncludes

//## begin module%3921965A0364.includes preserve=yes
//## end module%3921965A0364.includes

// LGXHost
#include "LGXHost.h"
// LGXSystem
#include "LGXSystm.h"


//## begin module%3921965A0364.declarations preserve=no
//## end module%3921965A0364.declarations

//## begin module%3921965A0364.additionalDeclarations preserve=yes
//## end module%3921965A0364.additionalDeclarations


// Class CLGXSystem 










CLGXSystem::CLGXSystem()
  //## begin CLGXSystem::CLGXSystem%.hasinit preserve=no
      : m_nComPort(0), m_pFile(NULL), m_nPCHostID(0), m_nMaxSession(0)
  //## end CLGXSystem::CLGXSystem%.hasinit
  //## begin CLGXSystem::CLGXSystem%.initialization preserve=yes
  //## end CLGXSystem::CLGXSystem%.initialization
{
  //## begin CLGXSystem::CLGXSystem%.body preserve=yes
  //## end CLGXSystem::CLGXSystem%.body
}


CLGXSystem::~CLGXSystem()
{
  //## begin CLGXSystem::~CLGXSystem%.body preserve=yes
	THostsMap::iterator iter = m_HostsMap.begin();

	for (; iter != m_HostsMap.end(); iter++)
	{
		CLGXHost *pHost = (*iter).second;
		delete pHost;
	}

	m_HostsMap.clear();
  //## end CLGXSystem::~CLGXSystem%.body
}



//## Other Operations (implementation)
bool CLGXSystem::Init (BYTE nComPort, BYTE nMaxSession, THOSTID nPCHostID)
{
  //## begin CLGXSystem::Init%956487400.body preserve=yes
	m_nComPort = nComPort;
	m_nMaxSession = nMaxSession;
	m_nPCHostID = nPCHostID;

	m_LGXProgramMgr.Init(this);
	
	return m_LGXTowerMgr.Init(m_nComPort, NOPARITY, this);
  //## end CLGXSystem::Init%956487400.body
}

bool CLGXSystem::InstallLegOS (const CString &szFileName)
{
  //## begin CLGXSystem::InstallLegOS%956487401.body preserve=yes
	bool bResult = false;
	
	// Close current connection
	m_LGXTowerMgr.Close();	

	// Open a new one with odd parity 
	if (m_LGXTowerMgr.Init(m_nComPort, ODDPARITY, this))
	{			
/*
		g_pFile = fopen(szFileName, "r");
		
		bResult = ((g_pFile != NULL) &&
			       BuildImage() &&
			       DeleteFirmware() &&
			       SendLegOS() &&
			       UnlockFirmware()); 			
*/
	}

	// Reopen connection with no parity		
	m_LGXTowerMgr.Close();	
	m_LGXTowerMgr.Init(m_nComPort, NOPARITY, this);

	return bResult;
  //## end CLGXSystem::InstallLegOS%956487401.body
}

CLGXHost * CLGXSystem::GetHost (THOSTID nHostID)
{
  //## begin CLGXSystem::GetHost%956487402.body preserve=yes
	CLGXHost *pHost = NULL;

	THostsMap::iterator iter = m_HostsMap.find(nHostID);

	// Already created ?
	if (iter != m_HostsMap.end())
	{
		pHost = (*iter).second;
	}
	else
	{
		pHost = new CLGXHost;
		if (pHost != NULL)
		{
			pHost->Init(m_nPCHostID, nHostID, &m_LGXTowerMgr);
			m_HostsMap.insert(THostsMap::value_type(nHostID, pHost));			
		}
	}

	return pHost;
  //## end CLGXSystem::GetHost%956487402.body
}

void CLGXSystem::HandleByte (unsigned char  b)
{
  //## begin CLGXSystem::HandleByte%956487404.body preserve=yes
	if (m_LNPStateMachine.HandleByte(b))
	{
		bool bDeleteFrame = true;
		CLGXLNPFrame *pFrame = m_LNPStateMachine.GetFrame();
		if (pFrame != NULL)
		{
			if (pFrame->CheckFrame())
			{
				switch (pFrame->GetFrameType())
				{
					case CLGXLNPFrame::ELNP_BROADCAST_FRAME:
						// TODO: Handle broadcast frames
						break;

					case CLGXLNPFrame::ELNP_ADDRESSED_FRAME:
					{			
						CLGXLNPAddressedFrame *pAddressedFrame = (CLGXLNPAddressedFrame*) pFrame;

						if (m_nPCHostID == pAddressedFrame->GetDestHostID())
						{
							THostsMap::iterator iter = m_HostsMap.find(pAddressedFrame->GetSrcHostID()); 
							if (iter != m_HostsMap.end())
							{
								CLGXHost *pHost = (*iter).second;
								if (pHost != NULL)
								{
									bDeleteFrame = pHost->Dispatch(pAddressedFrame);
								}
							}
						}	
					}
					
					default:
						break;
				}
			}

			if (bDeleteFrame)
			{
				delete pFrame;
			}	
		}
	}  
  //## end CLGXSystem::HandleByte%956487404.body
}

CLGXProgramMgr & CLGXSystem::GetProgramMgr ()
{
  //## begin CLGXSystem::GetProgramMgr%958835230.body preserve=yes
	return m_LGXProgramMgr;
  //## end CLGXSystem::GetProgramMgr%958835230.body
}

CLGXTowerMgr & CLGXSystem::GetTowerMgr ()
{
  //## begin CLGXSystem::GetTowerMgr%958908576.body preserve=yes
	return m_LGXTowerMgr;
  //## end CLGXSystem::GetTowerMgr%958908576.body
}

// Additional Declarations
  //## begin CLGXSystem%3902C6A00271.declarations preserve=yes
  //## end CLGXSystem%3902C6A00271.declarations

//## begin module%3921965A0364.epilog preserve=yes
//## end module%3921965A0364.epilog
