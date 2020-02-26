// LNPManager.h : Declaration of the CLNPManager

#ifndef __LNPMANAGER_H_
#define __LNPMANAGER_H_

#include "resource.h"       // main symbols
#include "WinLNPCP.h"

/////////////////////////////////////////////////////////////////////////////
// CLNPManager
class ATL_NO_VTABLE CLNPManager : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CLNPManager, &CLSID_LNPManager>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CLNPManager>,
	public IDispatchImpl<ILNPManager, &IID_ILNPManager, &LIBID_WINLNPLib>,
	public ILNPManagerPrivate
{
public:
	DECLARE_CLASSFACTORY_SINGLETON(CLNPManager)

public:
	CLNPManager();
	~CLNPManager();

DECLARE_REGISTRY_RESOURCEID(IDR_LNPMANAGER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CLNPManager)
	COM_INTERFACE_ENTRY(ILNPManager)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IDispatch)	
	COM_INTERFACE_ENTRY(ILNPManagerPrivate)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CLNPManager)
END_CONNECTION_POINT_MAP()

private:
	// Parameterizable values from registry
	BYTE m_nPCHostID;
	BYTE m_nCommPort;

	// Management of existing sessions
	BYTE m_nMaxSession;
	bool *m_abSessionFlags;  // array of created session indicators 	

private:
	void InitSessionIndicators(BYTE nHostMask);
	bool GetNewSessionID(BYTE &nSessionID);
	void SetSessionFlag(BYTE nSessionID);
	bool GetSessionFlag(BYTE nSessionID);
	void ClearSessionFlag(BYTE nSessionID);

// ISupportsErrorInfo
public:
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// ILNPManager
public:
	STDMETHOD(GetNbMaxSession)(/*[out, retval]*/ BYTE *pnMaxSession);
	STDMETHOD(GetPCHostID)(/*[out, retval]*/ BYTE *pnPCHostID);
	STDMETHOD(CreateNewSession)(/*[out, retval]*/ IDispatch **ppSession);
	STDMETHOD(CreateSessionOnPort)(/*[in]*/ BYTE nPortID, /*[out, retval]*/ IDispatch **ppSession);		
	STDMETHOD(DownloadProgram)(/*[in]*/ BYTE nHostID, /*[in]*/ BYTE nPrgID, /*[in]*/ VARIANT vFileName);
	STDMETHOD(DeleteProgram)(/*[in]*/ BYTE nHostID, /*[in]*/ BYTE nPrgID);
	STDMETHOD(RunProgram)(/*[in]*/ BYTE nHostID, /*[in]*/ BYTE nPrgID);
	STDMETHOD(IsKeepAliveRunning)(/*[out, retval]*/ BOOL *pbRun);
	STDMETHOD(RunKeepAlive)(/*[in]*/ BOOL bRun);

// ILNPManagerPrivate
public:
	STDMETHOD(NotifyDeathOfSession)(/*[in]*/BYTE nSessionID);
};



#endif //__LNPMANAGER_H_
