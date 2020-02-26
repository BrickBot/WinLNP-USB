// LNPSession.cpp : Implementation of CLNPSession
#include "stdafx.h"
#include "WinLNP.h"
#include "LNPSession.h"

#include "LGXSystm.h"
#include "LGXHost.h"
extern CLGXSystem g_LGXSytem;

/////////////////////////////////////////////////////////////////////////////
// CLNPSession

CLNPSession::CLNPSession()
{
}

CLNPSession::~CLNPSession()
{
	if (m_pManager != NULL)
	{
		m_pManager->NotifyDeathOfSession(m_nSessionID);
	}
}

STDMETHODIMP CLNPSession::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ILNPSession
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (::ATL::InlineIsEqualGUID(*arr[i],riid)) // ::ATL:: added by Alexander Cech (see MS KB Q243298)
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CLNPSession::Init(BYTE nPCHostID, BYTE nSessionID, IUnknown *pManager)
{
	HRESULT hRes = E_POINTER;

	m_pManager = pManager;	// Implicite QueryInterface for ILNPManagerPrivate !
	if (m_pManager != NULL)
	{
		m_nPCHostID = nPCHostID;
		m_nSessionID = nSessionID;		
		hRes = S_OK;
	}

	return S_OK;
}

STDMETHODIMP CLNPSession::NotifyDeathOfPort(BYTE nHostID, BYTE nPortID)
{
	WORD key = MAKEWORD(nHostID, nPortID);	
	TPortIndicatorsMap::iterator iter = m_PortIndicators.find(key);
	if (iter != m_PortIndicators.end())
	{
		(*iter).second = false;
	}	
	return S_OK;
}

STDMETHODIMP CLNPSession::GetSessionID(BYTE *pnSessionID)
{
	HRESULT hRes = E_POINTER;

	if (pnSessionID != NULL)
	{
		*pnSessionID = m_nSessionID;
		hRes = S_OK;
	}

	return hRes;
}

STDMETHODIMP CLNPSession::OpenPort(BYTE nHostID, BYTE nPortID, IDispatch **ppPort)
{
	WORD key = MAKEWORD(nHostID, nPortID);
	TPortIndicatorsMap::iterator iter = m_PortIndicators.find(key);
	if (iter != m_PortIndicators.end() && (*iter).second)
	{
		return E_FAIL;
	}	
	
	CLSID clsid;
	HRESULT hRes = CLSIDFromString(L"WinLNP.LNPPort", &clsid);
	
	if (SUCCEEDED(hRes))
	{ 
		hRes = CoCreateInstance(clsid, 
	                            NULL, 
	                            CLSCTX_ALL, 
	                            __uuidof(IDispatch), 
	                            (LPVOID*)ppPort);
		if (SUCCEEDED(hRes))
		{
			CComQIPtr<ILNPPortPrivate> pPortPrivate;	
			pPortPrivate = *ppPort;
			if (pPortPrivate != NULL)
			{
				pPortPrivate->Init(m_nSessionID,
				                   nHostID,
				                   nPortID,
				                   GetUnknown());
				
				m_PortIndicators.insert(TPortIndicatorsMap::value_type(key, true));
			}
		}
	}

	return hRes;
}

