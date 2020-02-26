// LNPSession.h : Declaration of the CLNPSession

#ifndef __LNPSESSION_H_
#define __LNPSESSION_H_

#include "resource.h"       // main symbols

#include "LGXPrgrm.h"

typedef map<WORD, bool> TPortIndicatorsMap;

/////////////////////////////////////////////////////////////////////////////
// CLNPSession
class ATL_NO_VTABLE CLNPSession : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CLNPSession, &CLSID_LNPSession>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CLNPSession>,
	public IDispatchImpl<ILNPSession, &IID_ILNPSession, &LIBID_WINLNPLib>,
	public ILNPSessionPrivate
{
public:
	CLNPSession();
	~CLNPSession();

DECLARE_REGISTRY_RESOURCEID(IDR_LNPSESSION)
DECLARE_NOT_AGGREGATABLE(CLNPSession)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLNPSession)
	COM_INTERFACE_ENTRY(ILNPSession)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ILNPSessionPrivate)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CLNPSession)
END_CONNECTION_POINT_MAP()

private:
	BYTE m_nPCHostID;
	BYTE m_nSessionID;
	CComQIPtr<ILNPManagerPrivate> m_pManager;
	TPortIndicatorsMap m_PortIndicators;

// ISupportsErrorInfo
public:
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILNPSession
public:
	STDMETHOD(GetSessionID)(/*[out, retval]*/ BYTE *pnSessionID);
	STDMETHOD(OpenPort)(/*[in]*/ BYTE nHostID, 
	                    /*[in]*/ BYTE nPortID, 
	                    /*[out, retval]*/ IDispatch **ppPort);

// ILNPSessionPrivate
public:
	STDMETHOD(Init)(/*[in]*/ BYTE nPCHostID, /*[in]*/ BYTE nSessionID, /*[in]*/ IUnknown *pManager);
	STDMETHOD(NotifyDeathOfPort)(/*[in]*/ BYTE nHostID, /*[in]*/ BYTE nPortID);
};

#endif //__LNPSESSION_H_
