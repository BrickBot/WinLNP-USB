// LNPPort.cpp : Implementation of CLNPPort
#include "stdafx.h"
#include "WinLNP.h"
#include "LNPPort.h"

#include "comdef.h"

#include "LGXSystm.h"
extern CLGXSystem g_LGXSytem;

/////////////////////////////////////////////////////////////////////////////
// CLNPPort

CLNPPort::CLNPPort()
{
	m_nMode = 0;
	m_pLGXHost = NULL;
	m_pLGXPort = NULL;
	m_eDataFormat = BSTR_ArrayOfByte;
}

CLNPPort::~CLNPPort()
{
	if (m_pSession != NULL)
	{
		BYTE nHostID;
		BYTE nPortID;
		
		HRESULT hRes1 = GetHostID(&nHostID);
		HRESULT hRes2 = GetPortID(&nPortID);

		if (SUCCEEDED(hRes1) && SUCCEEDED(hRes2))
		{
			m_pSession->NotifyDeathOfPort(nHostID, nPortID);
		}
	}

	if (m_pLGXPort != NULL)
	{
		m_pLGXPort->UnregisterHandler(this);
	}
}

STDMETHODIMP CLNPPort::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_ILNPPort
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (::ATL::InlineIsEqualGUID(*arr[i],riid)) // ::ATL:: added by Alexander Cech (see MS KB Q243298)
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CLNPPort::Init(/*[in]*/ BYTE nSessionID, 
                            /*[in]*/ BYTE nHostID, 
                            /*[in]*/ BYTE nPortID, 
                            /*[in]*/ IUnknown *pSession)
{
	HRESULT hRes = E_POINTER;

	m_pSession = pSession;	// Implicite QueryInterface for ILNPSessionPrivate !
	if (m_pSession != NULL)
	{
		m_nSessionID = nSessionID;

		m_pLGXHost = g_LGXSytem.GetHost(nHostID);
		if (m_pLGXHost != NULL)
		{
			m_pLGXPort = m_pLGXHost->GetPort(nPortID);
			if (m_pLGXPort != NULL)
			{
				m_pLGXPort->RegisterHandler(m_nSessionID, this);
				hRes = S_OK;
			}
		}		
	}

	return hRes;
}

STDMETHODIMP CLNPPort::Send(VARIANT acData)
{
	HRESULT hRes = E_FAIL;
	
	if (m_pLGXPort != NULL)
	{
		ULONG nLength;
		BYTE data[256];		

		if (GetDataFromVariant(acData, nLength, data))	
		{
			m_pLGXPort->Send(m_nSessionID, nLength, data);
			hRes = S_OK;
		}
	}

	return hRes;
}

STDMETHODIMP CLNPPort::GetHostID(BYTE *pnHostID)
{
	HRESULT hRes = E_POINTER;

	if (pnHostID != NULL)
	{
		if (m_pLGXPort != NULL)
		{		
			*pnHostID = m_pLGXPort->GetHostID();
			hRes = S_OK;
		}
		else
		{
			hRes = E_FAIL;
		}
	}

	return hRes;
}

STDMETHODIMP CLNPPort::GetPortID(BYTE *pnPortID)
{
	HRESULT hRes = E_POINTER;

	if (pnPortID != NULL)
	{
		if (m_pLGXPort != NULL)
		{		
			*pnPortID = m_pLGXPort->GetPortID();
			hRes = S_OK;
		}
		else
		{
			hRes = E_FAIL;
		}
	}

	return hRes;
}

bool CLNPPort::TreatData(CLGXLNPFrame *pFrame)
{
	USES_CONVERSION;
	bool bOK = false;

	VARIANT vData;
	VariantClear(&vData);	

	unsigned char *pData = pFrame->GetData();
	BYTE nLength = pFrame->GetDataLength();

	if (nLength > 0)
	{	
		switch (m_eDataFormat)
		{
			case BSTR_FormatedString:
			{
				char *pString = new char[5*nLength+1];			
				if (pString != NULL)
				{
					*pString = 0;
					char szVal[6];
					for (int i=0; i<nLength; i++)
					{															
						sprintf(szVal, "0x%02x ", pData[i]);
						strcat(pString, szVal);
					}

					vData.vt = VT_BSTR;
					vData.bstrVal = SysAllocString(A2OLE(pString));
					bOK = true;
				}
				break;
			}
			case BSTR_ArrayOfByte:
			{
				char *pString = new char[nLength];			
				if (pString != NULL)
				{					
					memcpy(pString, pData, nLength);
					vData.vt = VT_BSTR;
					vData.bstrVal = SysAllocStringByteLen(pString, nLength);
					bOK = true;
				}
				break;

			}
			default:
				break;
		}
	}

	if (bOK)
	{
		Fire_DataHandler(vData);
		SysFreeString(vData.bstrVal);
	}

	VariantClear(&vData);

	return true;
}

TPORTID CLNPPort::GetSessionID()
{
	return m_nSessionID;
}

bool CLNPPort::GetDataFromVariant(VARIANT vData, ULONG &nLength, BYTE acData[256])
{
	bool bResult = false;

	switch (vData.vt)
	{
		case VT_BSTR:
		{
			switch (m_eDataFormat)
			{
				case BSTR_FormatedString:
				{
					_bstr_t bstr(vData.bstrVal);
					char *pData = bstr;

					int nRes;
					int index = 0;				
					do
					{				
						nRes = sscanf(pData, "0x%x", &acData[index++]);					
						pData += nRes*5;
					}
					while (nRes == 1 && index<256);				
					nLength = (nRes == 0) ? index-1 : index;
					bResult = true;
					break;
				}
				case BSTR_ArrayOfByte:
				{					
					nLength = SysStringByteLen(vData.bstrVal);
					nLength = (nLength > 256) ? 256 : nLength;
					memcpy(acData, (char*)vData.bstrVal, nLength);
					bResult = true;
					break;
				}
				default:
					break;
			}			
			break;
		}
		default:
			break;
	}

	return bResult;
}

STDMETHODIMP CLNPPort::SetDataFormat(ELNPDataFormat eDataFormat)
{
	m_eDataFormat = eDataFormat;
	return S_OK;
}

