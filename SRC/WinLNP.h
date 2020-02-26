/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 31 19:58:29 2002
 */
/* Compiler settings for D:\legOS\legOS\WinLNP\SRC\WinLNP.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __WinLNP_h__
#define __WinLNP_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __ILNPManager_FWD_DEFINED__
#define __ILNPManager_FWD_DEFINED__
typedef interface ILNPManager ILNPManager;
#endif 	/* __ILNPManager_FWD_DEFINED__ */


#ifndef __ILNPManagerPrivate_FWD_DEFINED__
#define __ILNPManagerPrivate_FWD_DEFINED__
typedef interface ILNPManagerPrivate ILNPManagerPrivate;
#endif 	/* __ILNPManagerPrivate_FWD_DEFINED__ */


#ifndef __ILNPSession_FWD_DEFINED__
#define __ILNPSession_FWD_DEFINED__
typedef interface ILNPSession ILNPSession;
#endif 	/* __ILNPSession_FWD_DEFINED__ */


#ifndef __ILNPSessionPrivate_FWD_DEFINED__
#define __ILNPSessionPrivate_FWD_DEFINED__
typedef interface ILNPSessionPrivate ILNPSessionPrivate;
#endif 	/* __ILNPSessionPrivate_FWD_DEFINED__ */


#ifndef __ILNPPort_FWD_DEFINED__
#define __ILNPPort_FWD_DEFINED__
typedef interface ILNPPort ILNPPort;
#endif 	/* __ILNPPort_FWD_DEFINED__ */


#ifndef __ILNPPortPrivate_FWD_DEFINED__
#define __ILNPPortPrivate_FWD_DEFINED__
typedef interface ILNPPortPrivate ILNPPortPrivate;
#endif 	/* __ILNPPortPrivate_FWD_DEFINED__ */


#ifndef ___ILNPPortEvents_FWD_DEFINED__
#define ___ILNPPortEvents_FWD_DEFINED__
typedef interface _ILNPPortEvents _ILNPPortEvents;
#endif 	/* ___ILNPPortEvents_FWD_DEFINED__ */


#ifndef __LNPManager_FWD_DEFINED__
#define __LNPManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class LNPManager LNPManager;
#else
typedef struct LNPManager LNPManager;
#endif /* __cplusplus */

#endif 	/* __LNPManager_FWD_DEFINED__ */


#ifndef __LNPSession_FWD_DEFINED__
#define __LNPSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class LNPSession LNPSession;
#else
typedef struct LNPSession LNPSession;
#endif /* __cplusplus */

#endif 	/* __LNPSession_FWD_DEFINED__ */


#ifndef __LNPPort_FWD_DEFINED__
#define __LNPPort_FWD_DEFINED__

#ifdef __cplusplus
typedef class LNPPort LNPPort;
#else
typedef struct LNPPort LNPPort;
#endif /* __cplusplus */

#endif 	/* __LNPPort_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_WinLNP_0000 */
/* [local] */ 

typedef /* [public][public][v1_enum] */ 
enum __MIDL___MIDL_itf_WinLNP_0000_0001
    {	BSTR_ArrayOfByte	= 0,
	BSTR_FormatedString	= BSTR_ArrayOfByte + 1
    }	ELNPDataFormat;



extern RPC_IF_HANDLE __MIDL_itf_WinLNP_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_WinLNP_0000_v0_0_s_ifspec;

#ifndef __ILNPManager_INTERFACE_DEFINED__
#define __ILNPManager_INTERFACE_DEFINED__

/* interface ILNPManager */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1C5EF50E-59D4-4451-82FB-10CA722750BC")
    ILNPManager : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetNbMaxSession( 
            /* [retval][out] */ BYTE __RPC_FAR *pnMaxSession) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPCHostID( 
            /* [retval][out] */ BYTE __RPC_FAR *pnPCHostID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateNewSession( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE CreateSessionOnPort( 
            /* [in] */ BYTE nPortID,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DownloadProgram( 
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID,
            /* [in] */ VARIANT vFileName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE DeleteProgram( 
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RunProgram( 
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE RunKeepAlive( 
            /* [in] */ BOOL bRun) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsKeepAliveRunning( 
            /* [retval][out] */ BOOL __RPC_FAR *pbRun) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ILNPManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNbMaxSession )( 
            ILNPManager __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pnMaxSession);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPCHostID )( 
            ILNPManager __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pnPCHostID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateNewSession )( 
            ILNPManager __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSessionOnPort )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ BYTE nPortID,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DownloadProgram )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID,
            /* [in] */ VARIANT vFileName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteProgram )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RunProgram )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPrgID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RunKeepAlive )( 
            ILNPManager __RPC_FAR * This,
            /* [in] */ BOOL bRun);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsKeepAliveRunning )( 
            ILNPManager __RPC_FAR * This,
            /* [retval][out] */ BOOL __RPC_FAR *pbRun);
        
        END_INTERFACE
    } ILNPManagerVtbl;

    interface ILNPManager
    {
        CONST_VTBL struct ILNPManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILNPManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILNPManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILNPManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILNPManager_GetNbMaxSession(This,pnMaxSession)	\
    (This)->lpVtbl -> GetNbMaxSession(This,pnMaxSession)

#define ILNPManager_GetPCHostID(This,pnPCHostID)	\
    (This)->lpVtbl -> GetPCHostID(This,pnPCHostID)

#define ILNPManager_CreateNewSession(This,ppSession)	\
    (This)->lpVtbl -> CreateNewSession(This,ppSession)

#define ILNPManager_CreateSessionOnPort(This,nPortID,ppSession)	\
    (This)->lpVtbl -> CreateSessionOnPort(This,nPortID,ppSession)

#define ILNPManager_DownloadProgram(This,nHostID,nPrgID,vFileName)	\
    (This)->lpVtbl -> DownloadProgram(This,nHostID,nPrgID,vFileName)

#define ILNPManager_DeleteProgram(This,nHostID,nPrgID)	\
    (This)->lpVtbl -> DeleteProgram(This,nHostID,nPrgID)

#define ILNPManager_RunProgram(This,nHostID,nPrgID)	\
    (This)->lpVtbl -> RunProgram(This,nHostID,nPrgID)

#define ILNPManager_RunKeepAlive(This,bRun)	\
    (This)->lpVtbl -> RunKeepAlive(This,bRun)

#define ILNPManager_IsKeepAliveRunning(This,pbRun)	\
    (This)->lpVtbl -> IsKeepAliveRunning(This,pbRun)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_GetNbMaxSession_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pnMaxSession);


void __RPC_STUB ILNPManager_GetNbMaxSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_GetPCHostID_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pnPCHostID);


void __RPC_STUB ILNPManager_GetPCHostID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_CreateNewSession_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession);


void __RPC_STUB ILNPManager_CreateNewSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_CreateSessionOnPort_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [in] */ BYTE nPortID,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppSession);


void __RPC_STUB ILNPManager_CreateSessionOnPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_DownloadProgram_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPrgID,
    /* [in] */ VARIANT vFileName);


void __RPC_STUB ILNPManager_DownloadProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_DeleteProgram_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPrgID);


void __RPC_STUB ILNPManager_DeleteProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_RunProgram_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPrgID);


void __RPC_STUB ILNPManager_RunProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_RunKeepAlive_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [in] */ BOOL bRun);


void __RPC_STUB ILNPManager_RunKeepAlive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManager_IsKeepAliveRunning_Proxy( 
    ILNPManager __RPC_FAR * This,
    /* [retval][out] */ BOOL __RPC_FAR *pbRun);


void __RPC_STUB ILNPManager_IsKeepAliveRunning_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPManager_INTERFACE_DEFINED__ */


#ifndef __ILNPManagerPrivate_INTERFACE_DEFINED__
#define __ILNPManagerPrivate_INTERFACE_DEFINED__

/* interface ILNPManagerPrivate */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPManagerPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05FEE9DB-6139-4ff2-B4EC-A817CF462064")
    ILNPManagerPrivate : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE NotifyDeathOfSession( 
            /* [in] */ BYTE nSessionID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPManagerPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPManagerPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPManagerPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPManagerPrivate __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NotifyDeathOfSession )( 
            ILNPManagerPrivate __RPC_FAR * This,
            /* [in] */ BYTE nSessionID);
        
        END_INTERFACE
    } ILNPManagerPrivateVtbl;

    interface ILNPManagerPrivate
    {
        CONST_VTBL struct ILNPManagerPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPManagerPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPManagerPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPManagerPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPManagerPrivate_NotifyDeathOfSession(This,nSessionID)	\
    (This)->lpVtbl -> NotifyDeathOfSession(This,nSessionID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPManagerPrivate_NotifyDeathOfSession_Proxy( 
    ILNPManagerPrivate __RPC_FAR * This,
    /* [in] */ BYTE nSessionID);


void __RPC_STUB ILNPManagerPrivate_NotifyDeathOfSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPManagerPrivate_INTERFACE_DEFINED__ */


#ifndef __ILNPSession_INTERFACE_DEFINED__
#define __ILNPSession_INTERFACE_DEFINED__

/* interface ILNPSession */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7F37B1DC-748C-4DBA-A64E-E73668C2AB48")
    ILNPSession : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSessionID( 
            /* [retval][out] */ BYTE __RPC_FAR *pnSessionID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE OpenPort( 
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppPort) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ILNPSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ILNPSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ILNPSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ILNPSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSessionID )( 
            ILNPSession __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pnSessionID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OpenPort )( 
            ILNPSession __RPC_FAR * This,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppPort);
        
        END_INTERFACE
    } ILNPSessionVtbl;

    interface ILNPSession
    {
        CONST_VTBL struct ILNPSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILNPSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILNPSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILNPSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILNPSession_GetSessionID(This,pnSessionID)	\
    (This)->lpVtbl -> GetSessionID(This,pnSessionID)

#define ILNPSession_OpenPort(This,nHostID,nPortID,ppPort)	\
    (This)->lpVtbl -> OpenPort(This,nHostID,nPortID,ppPort)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPSession_GetSessionID_Proxy( 
    ILNPSession __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pnSessionID);


void __RPC_STUB ILNPSession_GetSessionID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPSession_OpenPort_Proxy( 
    ILNPSession __RPC_FAR * This,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPortID,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppPort);


void __RPC_STUB ILNPSession_OpenPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPSession_INTERFACE_DEFINED__ */


#ifndef __ILNPSessionPrivate_INTERFACE_DEFINED__
#define __ILNPSessionPrivate_INTERFACE_DEFINED__

/* interface ILNPSessionPrivate */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPSessionPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("791E0FD3-0A69-4b68-B203-8059E42E65D6")
    ILNPSessionPrivate : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ BYTE nPCHostID,
            /* [in] */ BYTE nSessionID,
            /* [in] */ IUnknown __RPC_FAR *pManager) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE NotifyDeathOfPort( 
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPSessionPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPSessionPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPSessionPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPSessionPrivate __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            ILNPSessionPrivate __RPC_FAR * This,
            /* [in] */ BYTE nPCHostID,
            /* [in] */ BYTE nSessionID,
            /* [in] */ IUnknown __RPC_FAR *pManager);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NotifyDeathOfPort )( 
            ILNPSessionPrivate __RPC_FAR * This,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID);
        
        END_INTERFACE
    } ILNPSessionPrivateVtbl;

    interface ILNPSessionPrivate
    {
        CONST_VTBL struct ILNPSessionPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPSessionPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPSessionPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPSessionPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPSessionPrivate_Init(This,nPCHostID,nSessionID,pManager)	\
    (This)->lpVtbl -> Init(This,nPCHostID,nSessionID,pManager)

#define ILNPSessionPrivate_NotifyDeathOfPort(This,nHostID,nPortID)	\
    (This)->lpVtbl -> NotifyDeathOfPort(This,nHostID,nPortID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPSessionPrivate_Init_Proxy( 
    ILNPSessionPrivate __RPC_FAR * This,
    /* [in] */ BYTE nPCHostID,
    /* [in] */ BYTE nSessionID,
    /* [in] */ IUnknown __RPC_FAR *pManager);


void __RPC_STUB ILNPSessionPrivate_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPSessionPrivate_NotifyDeathOfPort_Proxy( 
    ILNPSessionPrivate __RPC_FAR * This,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPortID);


void __RPC_STUB ILNPSessionPrivate_NotifyDeathOfPort_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPSessionPrivate_INTERFACE_DEFINED__ */


#ifndef __ILNPPort_INTERFACE_DEFINED__
#define __ILNPPort_INTERFACE_DEFINED__

/* interface ILNPPort */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C848834-EED7-43CA-AFF7-49FC6358F845")
    ILNPPort : public IDispatch
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetHostID( 
            /* [retval][out] */ BYTE __RPC_FAR *pnHostID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPortID( 
            /* [retval][out] */ BYTE __RPC_FAR *pnPortID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ VARIANT acData) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetDataFormat( 
            /* [in] */ ELNPDataFormat eDataFormat) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPPort __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPPort __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ILNPPort __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetHostID )( 
            ILNPPort __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pnHostID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPortID )( 
            ILNPPort __RPC_FAR * This,
            /* [retval][out] */ BYTE __RPC_FAR *pnPortID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Send )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ VARIANT acData);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDataFormat )( 
            ILNPPort __RPC_FAR * This,
            /* [in] */ ELNPDataFormat eDataFormat);
        
        END_INTERFACE
    } ILNPPortVtbl;

    interface ILNPPort
    {
        CONST_VTBL struct ILNPPortVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPPort_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPPort_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPPort_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPPort_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILNPPort_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILNPPort_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILNPPort_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILNPPort_GetHostID(This,pnHostID)	\
    (This)->lpVtbl -> GetHostID(This,pnHostID)

#define ILNPPort_GetPortID(This,pnPortID)	\
    (This)->lpVtbl -> GetPortID(This,pnPortID)

#define ILNPPort_Send(This,acData)	\
    (This)->lpVtbl -> Send(This,acData)

#define ILNPPort_SetDataFormat(This,eDataFormat)	\
    (This)->lpVtbl -> SetDataFormat(This,eDataFormat)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPPort_GetHostID_Proxy( 
    ILNPPort __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pnHostID);


void __RPC_STUB ILNPPort_GetHostID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPPort_GetPortID_Proxy( 
    ILNPPort __RPC_FAR * This,
    /* [retval][out] */ BYTE __RPC_FAR *pnPortID);


void __RPC_STUB ILNPPort_GetPortID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPPort_Send_Proxy( 
    ILNPPort __RPC_FAR * This,
    /* [in] */ VARIANT acData);


void __RPC_STUB ILNPPort_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPPort_SetDataFormat_Proxy( 
    ILNPPort __RPC_FAR * This,
    /* [in] */ ELNPDataFormat eDataFormat);


void __RPC_STUB ILNPPort_SetDataFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPPort_INTERFACE_DEFINED__ */


#ifndef __ILNPPortPrivate_INTERFACE_DEFINED__
#define __ILNPPortPrivate_INTERFACE_DEFINED__

/* interface ILNPPortPrivate */
/* [unique][oleautomation][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILNPPortPrivate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E44A14BA-385D-484f-8B8C-E33C9B7BA847")
    ILNPPortPrivate : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ BYTE nSessionID,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID,
            /* [in] */ IUnknown __RPC_FAR *pSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILNPPortPrivateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ILNPPortPrivate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ILNPPortPrivate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ILNPPortPrivate __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            ILNPPortPrivate __RPC_FAR * This,
            /* [in] */ BYTE nSessionID,
            /* [in] */ BYTE nHostID,
            /* [in] */ BYTE nPortID,
            /* [in] */ IUnknown __RPC_FAR *pSession);
        
        END_INTERFACE
    } ILNPPortPrivateVtbl;

    interface ILNPPortPrivate
    {
        CONST_VTBL struct ILNPPortPrivateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILNPPortPrivate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILNPPortPrivate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILNPPortPrivate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILNPPortPrivate_Init(This,nSessionID,nHostID,nPortID,pSession)	\
    (This)->lpVtbl -> Init(This,nSessionID,nHostID,nPortID,pSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE ILNPPortPrivate_Init_Proxy( 
    ILNPPortPrivate __RPC_FAR * This,
    /* [in] */ BYTE nSessionID,
    /* [in] */ BYTE nHostID,
    /* [in] */ BYTE nPortID,
    /* [in] */ IUnknown __RPC_FAR *pSession);


void __RPC_STUB ILNPPortPrivate_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILNPPortPrivate_INTERFACE_DEFINED__ */



#ifndef __WINLNPLib_LIBRARY_DEFINED__
#define __WINLNPLib_LIBRARY_DEFINED__

/* library WINLNPLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WINLNPLib;

#ifndef ___ILNPPortEvents_DISPINTERFACE_DEFINED__
#define ___ILNPPortEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ILNPPortEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ILNPPortEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("30F1AF08-727B-4087-A54C-6D98BD459DD0")
    _ILNPPortEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ILNPPortEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ILNPPortEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ILNPPortEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ILNPPortEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ILNPPortEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ILNPPortEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ILNPPortEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ILNPPortEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _ILNPPortEventsVtbl;

    interface _ILNPPortEvents
    {
        CONST_VTBL struct _ILNPPortEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ILNPPortEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ILNPPortEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ILNPPortEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ILNPPortEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ILNPPortEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ILNPPortEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ILNPPortEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ILNPPortEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LNPManager;

#ifdef __cplusplus

class DECLSPEC_UUID("D0F142C2-C587-4A64-A4D2-D53CB0C02A58")
LNPManager;
#endif

EXTERN_C const CLSID CLSID_LNPSession;

#ifdef __cplusplus

class DECLSPEC_UUID("F2C4E6A4-8129-45C9-82C7-3E0A102FF8A5")
LNPSession;
#endif

EXTERN_C const CLSID CLSID_LNPPort;

#ifdef __cplusplus

class DECLSPEC_UUID("69E24352-C833-46DA-A5BF-AEEDB685179C")
LNPPort;
#endif
#endif /* __WINLNPLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
