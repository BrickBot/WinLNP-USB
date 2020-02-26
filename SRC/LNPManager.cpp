// LNPManager.cpp : Implementation of CLNPManager
#include "stdafx.h"
#include "WinLNP.h"
#include "LNPManager.h"

#include "comdef.h"

#include "LGXSystm.h"
#include "LGXTower.h"
CLGXSystem g_LGXSytem;

/////////////////////////////////////////////////////////////////////////////
// CLNPManager

// modified for USB support by Alexander Cech, based on Jin Satos modifications to legOS

CLNPManager::CLNPManager()
{
	HKEY hKey;
	DWORD dwType = REG_DWORD;
	DWORD dwDataSize = sizeof(DWORD);
	DWORD dwValue;

	BYTE nHostMask = 0xF0; 
	m_nPCHostID = 2;
	m_nCommPort = 2;

	// Open WinLNP registry key
	LONG nRetVal = RegOpenKeyEx(HKEY_LOCAL_MACHINE,  
	                            "Software\\LegOS\\WinLNP",
	                            NULL,
	                            KEY_QUERY_VALUE,
	                            &hKey);
	if (nRetVal == ERROR_SUCCESS) 
	{		
		// Get host mask
		nRetVal = RegQueryValueEx(hKey,
		                          "HostMask",
		                          NULL,
		                          &dwType,
		                          (LPBYTE)&dwValue,
		                          &dwDataSize);		

		if (nRetVal != ERROR_SUCCESS)
		{
			dwValue = 0xF0;
		}	
		nHostMask = (BYTE)dwValue;

		// Get host ID
		nRetVal = RegQueryValueEx(hKey,
								  "HostID",
								  NULL,
								  &dwType,
								  (LPBYTE)&dwValue,
								  &dwDataSize);

		if (nRetVal != ERROR_SUCCESS)
		{
			dwValue = 2;
		}
		m_nPCHostID = (BYTE)dwValue;

		// Get the comm port number
		nRetVal = RegQueryValueEx(hKey,
								  "CommPortNb",
								  NULL,
								  &dwType,
								  (LPBYTE)&dwValue,
								  &dwDataSize);

		if (nRetVal != ERROR_SUCCESS)
		{
			dwValue = 1;
		}
		m_nCommPort = (BYTE)dwValue;

		// (added by Alexander Cech)
		// Special comm port numbers > 100 are used for USB towers 
		// 101 = USB tower 1, 102 = USB tower 2, etc.

	}

	// Init opened session flags
	InitSessionIndicators(nHostMask);

	// Init comm port and tower
	g_LGXSytem.Init(m_nCommPort, m_nMaxSession, m_nPCHostID);
}

CLNPManager::~CLNPManager()
{
	if (m_abSessionFlags != NULL)
	{
		delete [] m_abSessionFlags;
	}
}


STDMETHODIMP CLNPManager::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ILNPManager
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (::ATL::InlineIsEqualGUID(*arr[i],riid)) // ::ATL:: added by Alexander Cech (see MS KB Q243298)
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CLNPManager::NotifyDeathOfSession(BYTE nSessionID)
{
	Lock();
	ClearSessionFlag(nSessionID);
	Unlock();
	return S_OK;
}

STDMETHODIMP CLNPManager::GetNbMaxSession(BYTE *pnMaxSession)
{
	HRESULT hRes = E_POINTER;

	if (pnMaxSession != NULL)
	{
		*pnMaxSession = m_nMaxSession;
		hRes = S_OK;
	}	

	return hRes;
}

STDMETHODIMP CLNPManager::GetPCHostID(BYTE *pnPCHostID)
{
	HRESULT hRes = E_POINTER;

	if (pnPCHostID != NULL)
	{
		*pnPCHostID = m_nPCHostID;
		hRes = S_OK;
	}	

	return hRes;
}

STDMETHODIMP CLNPManager::CreateNewSession(IDispatch **ppSession)
{
	BYTE nSessionID;
	if (!GetNewSessionID(nSessionID))
	{
		// All LNP ports used !		
		return E_FAIL;	// TODO: Give some more informations !!!
	}

	return CreateSessionOnPort(nSessionID, ppSession);
}

STDMETHODIMP CLNPManager::CreateSessionOnPort(BYTE nPortID, IDispatch **ppSession)
{
	if (GetSessionFlag(nPortID))
	{
		return E_FAIL;
	}

	CLSID clsid;
	HRESULT hRes = CLSIDFromString(L"WinLNP.LNPSession", &clsid);

	if (SUCCEEDED(hRes))
	{ 
		hRes = CoCreateInstance(clsid, 
	                            NULL, 
	                            CLSCTX_ALL, 
	                            __uuidof(IDispatch), 
	                            (LPVOID*)ppSession);
		if (SUCCEEDED(hRes))
		{
			CComQIPtr<ILNPSessionPrivate> pSessionPrivate;	
			pSessionPrivate = *ppSession;
			if (pSessionPrivate != NULL)
			{
				pSessionPrivate->Init(m_nPCHostID, 
									  nPortID, 
									  GetUnknown());
				SetSessionFlag(nPortID);
			}
		}
	}

	return hRes;
}

STDMETHODIMP CLNPManager::DownloadProgram(BYTE nHostID, BYTE nPrgID, VARIANT vFileName)
{	
	HRESULT hRes = E_FAIL;
	char *szFileName;

	if (vFileName.vt = VT_BSTR)
	{
		_bstr_t bstr(vFileName.bstrVal);
		szFileName = bstr;	

		CLGXProgramMgr &rPrgMgr = g_LGXSytem.GetProgramMgr();
		if (rPrgMgr.Download(nHostID, nPrgID, szFileName))
		{
			hRes = S_OK;
		}
	}

	return hRes;
}

STDMETHODIMP CLNPManager::DeleteProgram(BYTE nHostID, BYTE nPrgID)
{
	HRESULT hRes = E_FAIL;

	CLGXProgramMgr &rPrgMgr = g_LGXSytem.GetProgramMgr();
	if (rPrgMgr.Delete(nHostID, nPrgID))
	{
		hRes = S_OK;
	}

	return hRes;
}

STDMETHODIMP CLNPManager::RunProgram(BYTE nHostID, BYTE nPrgID)
{
	HRESULT hRes = E_FAIL;
	
	CLGXProgramMgr &rPrgMgr = g_LGXSytem.GetProgramMgr();
	if (rPrgMgr.Run(nHostID, nPrgID))
	{
		hRes = S_OK;
	}

	return hRes;
}

STDMETHODIMP CLNPManager::RunKeepAlive(BOOL bRun)
{
	CLGXTowerMgr &rTower = g_LGXSytem.GetTowerMgr();
	
	if (bRun)
	{
		rTower.WakeUp();
	}
	else
	{
		rTower.Sleep();
	}

	return S_OK;
}

STDMETHODIMP CLNPManager::IsKeepAliveRunning(BOOL *pbRun)
{
	HRESULT hRes = E_POINTER;

	if (pbRun != NULL)
	{
		CLGXTowerMgr &rTower = g_LGXSytem.GetTowerMgr();
		*pbRun = rTower.IsRunning();
		hRes = S_OK;
	}

	return hRes;
}


///////////////////////////////////////////////////////////////////////////////
//
// Helpers
//
///////////////////////////////////////////////////////////////////////////////

void CLNPManager::InitSessionIndicators(BYTE nHostMask)
{
	m_nMaxSession = 0;
	m_abSessionFlags = NULL;	

	DWORD dwPos = 1;	

	// Look for the first '1' of the mask	
	while (m_nMaxSession == 0 && dwPos < 0x100)
	{
		if (nHostMask & dwPos)
		{
			m_nMaxSession = dwPos-1;
		}
		dwPos = dwPos << 1;		
	}

	Lock();
	if (m_nMaxSession > 0)
	{
		m_abSessionFlags = new bool[m_nMaxSession];

		if (m_abSessionFlags != NULL)
		{
			for (int i=0; i<m_nMaxSession; i++)
			{
				m_abSessionFlags[i] = false;
			}
		}
	}
	Unlock();
}

bool CLNPManager::GetNewSessionID(BYTE &nSessionID)
{	
	for (nSessionID=1; nSessionID<m_nMaxSession; nSessionID++)
	{
		Lock();
		bool bAlreadyOpen = m_abSessionFlags[nSessionID];
		Unlock();
		if (!bAlreadyOpen)
		{
			return true;
		}
	}
	
	return false;
}	

void CLNPManager::SetSessionFlag(BYTE nSessionID)
{
	if (nSessionID < m_nMaxSession)
	{
		Lock();
		m_abSessionFlags[nSessionID] = true;
		Unlock();
	}
}

bool CLNPManager::GetSessionFlag(BYTE nSessionID)
{
	bool bResult = true;

	if (nSessionID < m_nMaxSession)
	{
		Lock();
		bResult = m_abSessionFlags[nSessionID];
		Unlock();
	}

	return bResult;
}

void CLNPManager::ClearSessionFlag(BYTE nSessionID)
{
	if (nSessionID < m_nMaxSession)
	{
		Lock();
		m_abSessionFlags[nSessionID] = false;
		Unlock();
	}
}

