// LNPPort.h : Declaration of the CLNPPort

#ifndef __LNPPORT_H_
#define __LNPPORT_H_

#include "resource.h"       // main symbols

#include "LGXHost.h"
#include "LGXPort.h"
#include "ILGXHndl.h"
#include "WinLNPCP.h"

/////////////////////////////////////////////////////////////////////////////
// CLNPPort
class ATL_NO_VTABLE CLNPPort : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CLNPPort, &CLSID_LNPPort>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CLNPPort>,
	public IDispatchImpl<ILNPPort, &IID_ILNPPort, &LIBID_WINLNPLib>,
	public ILNPPortPrivate,
	public ILGXHandler,
	public CProxy_ILNPPortEvents< CLNPPort >

{
public:
	CLNPPort();
	~CLNPPort();

DECLARE_REGISTRY_RESOURCEID(IDR_LNPPORT)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLNPPort)
	COM_INTERFACE_ENTRY(ILNPPort)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IDispatch)	
	COM_INTERFACE_ENTRY(ILNPPortPrivate)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CLNPPort)
CONNECTION_POINT_ENTRY(DIID__ILNPPortEvents)
END_CONNECTION_POINT_MAP()

private:
	BYTE m_nSessionID;
	CComQIPtr<ILNPSessionPrivate> m_pSession;
	CLGXHost *m_pLGXHost;
	CLGXPort *m_pLGXPort;
	BYTE m_nMode;
	ELNPDataFormat m_eDataFormat;

private:
	bool GetDataFromVariant(VARIANT vData, ULONG &nLength, BYTE acData[256]);

// ISupportsErrorInfo
public:
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILNPPort
public:
	STDMETHOD(GetPortID)(/*[out, retval]*/ BYTE *pnPortID);
	STDMETHOD(GetHostID)(/*[out, retval]*/ BYTE *pnHostID);
	STDMETHOD(Send)(/*[in]*/ VARIANT acData);
	STDMETHOD(SetDataFormat)(/*[in]*/ ELNPDataFormat eDataFormat);

// ILNPPortPrivate
public:		
	STDMETHOD(Init)(/*[in]*/ BYTE nSessionID, 
	                /*[in]*/ BYTE nHostID, 
	                /*[in]*/ BYTE nPortID, 
	                /*[in]*/ IUnknown *pSession);

// ILGXHandler
public:
	bool TreatData(CLGXLNPFrame *pFrame);
    TPORTID GetSessionID();
};

#endif //__LNPPORT_H_
