/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 31 19:58:29 2002
 */
/* Compiler settings for D:\legOS\legOS\WinLNP\SRC\WinLNP.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "WinLNP.h"

#define TYPE_FORMAT_STRING_SIZE   991                               
#define PROC_FORMAT_STRING_SIZE   527                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Standard interface: __MIDL_itf_WinLNP_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: ILNPManager, ver. 0.0,
   GUID={0x1C5EF50E,0x59D4,0x4451,{0x82,0xFB,0x10,0xCA,0x72,0x27,0x50,0xBC}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPManager_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILNPManager_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56,
    84,
    118,
    158,
    192,
    226,
    254
    };

static const MIDL_SERVER_INFO ILNPManager_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPManager_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPManager_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPManager_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(16) _ILNPManagerProxyVtbl = 
{
    &ILNPManager_ProxyInfo,
    &IID_ILNPManager,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ILNPManager::GetNbMaxSession */ ,
    (void *)-1 /* ILNPManager::GetPCHostID */ ,
    (void *)-1 /* ILNPManager::CreateNewSession */ ,
    (void *)-1 /* ILNPManager::CreateSessionOnPort */ ,
    (void *)-1 /* ILNPManager::DownloadProgram */ ,
    (void *)-1 /* ILNPManager::DeleteProgram */ ,
    (void *)-1 /* ILNPManager::RunProgram */ ,
    (void *)-1 /* ILNPManager::RunKeepAlive */ ,
    (void *)-1 /* ILNPManager::IsKeepAliveRunning */
};


static const PRPC_STUB_FUNCTION ILNPManager_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILNPManagerStubVtbl =
{
    &IID_ILNPManager,
    &ILNPManager_ServerInfo,
    16,
    &ILNPManager_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILNPManagerPrivate, ver. 0.0,
   GUID={0x05FEE9DB,0x6139,0x4ff2,{0xB4,0xEC,0xA8,0x17,0xCF,0x46,0x20,0x64}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPManagerPrivate_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILNPManagerPrivate_FormatStringOffsetTable[] = 
    {
    282
    };

static const MIDL_SERVER_INFO ILNPManagerPrivate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPManagerPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPManagerPrivate_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPManagerPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(4) _ILNPManagerPrivateProxyVtbl = 
{
    &ILNPManagerPrivate_ProxyInfo,
    &IID_ILNPManagerPrivate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ILNPManagerPrivate::NotifyDeathOfSession */
};

const CInterfaceStubVtbl _ILNPManagerPrivateStubVtbl =
{
    &IID_ILNPManagerPrivate,
    &ILNPManagerPrivate_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILNPSession, ver. 0.0,
   GUID={0x7F37B1DC,0x748C,0x4DBA,{0xA6,0x4E,0xE7,0x36,0x68,0xC2,0xAB,0x48}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPSession_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILNPSession_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    310
    };

static const MIDL_SERVER_INFO ILNPSession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPSession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPSession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPSession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _ILNPSessionProxyVtbl = 
{
    &ILNPSession_ProxyInfo,
    &IID_ILNPSession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ILNPSession::GetSessionID */ ,
    (void *)-1 /* ILNPSession::OpenPort */
};


static const PRPC_STUB_FUNCTION ILNPSession_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILNPSessionStubVtbl =
{
    &IID_ILNPSession,
    &ILNPSession_ServerInfo,
    9,
    &ILNPSession_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILNPSessionPrivate, ver. 0.0,
   GUID={0x791E0FD3,0x0A69,0x4b68,{0xB2,0x03,0x80,0x59,0xE4,0x2E,0x65,0xD6}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPSessionPrivate_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILNPSessionPrivate_FormatStringOffsetTable[] = 
    {
    350,
    390
    };

static const MIDL_SERVER_INFO ILNPSessionPrivate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPSessionPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPSessionPrivate_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPSessionPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(5) _ILNPSessionPrivateProxyVtbl = 
{
    &ILNPSessionPrivate_ProxyInfo,
    &IID_ILNPSessionPrivate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ILNPSessionPrivate::Init */ ,
    (void *)-1 /* ILNPSessionPrivate::NotifyDeathOfPort */
};

const CInterfaceStubVtbl _ILNPSessionPrivateStubVtbl =
{
    &IID_ILNPSessionPrivate,
    &ILNPSessionPrivate_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: ILNPPort, ver. 0.0,
   GUID={0x7C848834,0xEED7,0x43CA,{0xAF,0xF7,0x49,0xFC,0x63,0x58,0xF8,0x45}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPPort_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short ILNPPort_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    424,
    452
    };

static const MIDL_SERVER_INFO ILNPPort_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPPort_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPPort_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPPort_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _ILNPPortProxyVtbl = 
{
    &ILNPPort_ProxyInfo,
    &IID_ILNPPort,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ILNPPort::GetHostID */ ,
    (void *)-1 /* ILNPPort::GetPortID */ ,
    (void *)-1 /* ILNPPort::Send */ ,
    (void *)-1 /* ILNPPort::SetDataFormat */
};


static const PRPC_STUB_FUNCTION ILNPPort_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ILNPPortStubVtbl =
{
    &IID_ILNPPort,
    &ILNPPort_ServerInfo,
    11,
    &ILNPPort_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ILNPPortPrivate, ver. 0.0,
   GUID={0xE44A14BA,0x385D,0x484f,{0x8B,0x8C,0xE3,0x3C,0x9B,0x7B,0xA8,0x47}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ILNPPortPrivate_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ILNPPortPrivate_FormatStringOffsetTable[] = 
    {
    480
    };

static const MIDL_SERVER_INFO ILNPPortPrivate_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ILNPPortPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ILNPPortPrivate_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ILNPPortPrivate_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(4) _ILNPPortPrivateProxyVtbl = 
{
    &ILNPPortPrivate_ProxyInfo,
    &IID_ILNPPortPrivate,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *)-1 /* ILNPPortPrivate::Init */
};

const CInterfaceStubVtbl _ILNPPortPrivateStubVtbl =
{
    &IID_ILNPPortPrivate,
    &ILNPPortPrivate_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetHostID */


	/* Procedure GetSessionID */


	/* Procedure GetNbMaxSession */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0xd ),	/* 13 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pnHostID */


	/* Parameter pnSessionID */


	/* Parameter pnMaxSession */

/* 16 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPortID */


	/* Procedure GetPCHostID */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 36 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 38 */	NdrFcShort( 0x0 ),	/* 0 */
/* 40 */	NdrFcShort( 0xd ),	/* 13 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pnPortID */


	/* Parameter pnPCHostID */

/* 44 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 48 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateNewSession */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 64 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x8 ),	/* 8 */
/* 70 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter ppSession */

/* 72 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 76 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateSessionOnPort */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 92 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 94 */	NdrFcShort( 0x5 ),	/* 5 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x3,		/* 3 */

	/* Parameter nPortID */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 102 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 104 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter ppSession */

/* 106 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 114 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DownloadProgram */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 126 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
#else
			NdrFcShort( 0x24 ),	/* MIPS & PPC Stack size/offset = 36 */
#endif
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 128 */	NdrFcShort( 0xa ),	/* 10 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter nHostID */

/* 134 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 138 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPrgID */

/* 140 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 144 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter vFileName */

/* 146 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 148 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 150 */	NdrFcShort( 0x3d0 ),	/* Type Offset=976 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 154 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
#else
			NdrFcShort( 0x20 ),	/* MIPS & PPC Stack size/offset = 32 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DeleteProgram */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 166 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 168 */	NdrFcShort( 0xa ),	/* 10 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nHostID */

/* 174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 178 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPrgID */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 182 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 184 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 188 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunProgram */

/* 192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 198 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 200 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 202 */	NdrFcShort( 0xa ),	/* 10 */
/* 204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 206 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nHostID */

/* 208 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 210 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 212 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPrgID */

/* 214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 216 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 218 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 220 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 222 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 224 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RunKeepAlive */

/* 226 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 228 */	NdrFcLong( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 234 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	NdrFcShort( 0x8 ),	/* 8 */
/* 240 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter bRun */

/* 242 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 244 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 248 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 250 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsKeepAliveRunning */

/* 254 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 256 */	NdrFcLong( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 262 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 266 */	NdrFcShort( 0x10 ),	/* 16 */
/* 268 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pbRun */

/* 270 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 272 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 278 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NotifyDeathOfSession */

/* 282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 288 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/* 290 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 292 */	NdrFcShort( 0x5 ),	/* 5 */
/* 294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 296 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter nSessionID */

/* 298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 300 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 302 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 306 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OpenPort */

/* 310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 318 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 320 */	NdrFcShort( 0xa ),	/* 10 */
/* 322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 324 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x4,		/* 4 */

	/* Parameter nHostID */

/* 326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 328 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 330 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPortID */

/* 332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 334 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 336 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter ppPort */

/* 338 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 340 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 342 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 344 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 346 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 350 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 352 */	NdrFcLong( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/* 358 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 360 */	NdrFcShort( 0xa ),	/* 10 */
/* 362 */	NdrFcShort( 0x8 ),	/* 8 */
/* 364 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter nPCHostID */

/* 366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 368 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 370 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nSessionID */

/* 372 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 374 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 376 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pManager */

/* 378 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 380 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 382 */	NdrFcShort( 0x14e ),	/* Type Offset=334 */

	/* Return value */

/* 384 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 386 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NotifyDeathOfPort */

/* 390 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 392 */	NdrFcLong( 0x0 ),	/* 0 */
/* 396 */	NdrFcShort( 0x4 ),	/* 4 */
#ifndef _ALPHA_
/* 398 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 400 */	NdrFcShort( 0xa ),	/* 10 */
/* 402 */	NdrFcShort( 0x8 ),	/* 8 */
/* 404 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter nHostID */

/* 406 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 408 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 410 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPortID */

/* 412 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 414 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 416 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Return value */

/* 418 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 420 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 422 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Send */

/* 424 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 426 */	NdrFcLong( 0x0 ),	/* 0 */
/* 430 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 432 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 438 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter acData */

/* 440 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 442 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 444 */	NdrFcShort( 0x3d0 ),	/* Type Offset=976 */

	/* Return value */

/* 446 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 448 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 450 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDataFormat */

/* 452 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 454 */	NdrFcLong( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 460 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 464 */	NdrFcShort( 0x8 ),	/* 8 */
/* 466 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter eDataFormat */

/* 468 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 470 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 472 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 476 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x3 ),	/* 3 */
#ifndef _ALPHA_
/* 488 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 490 */	NdrFcShort( 0xf ),	/* 15 */
/* 492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 494 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter nSessionID */

/* 496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 498 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 500 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nHostID */

/* 502 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 504 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 506 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter nPortID */

/* 508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 510 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 512 */	0x1,		/* FC_BYTE */
			0x0,		/* 0 */

	/* Parameter pSession */

/* 514 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 516 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 518 */	NdrFcShort( 0x14e ),	/* Type Offset=334 */

	/* Return value */

/* 520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 522 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0x10,	/* FC_RP */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 12 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 16 */	NdrFcShort( 0x0 ),	/* 0 */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 24 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 26 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 28 */	
			0x12, 0x0,	/* FC_UP */
/* 30 */	NdrFcShort( 0x39e ),	/* Offset= 926 (956) */
/* 32 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 34 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 36 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 38 */	NdrFcShort( 0x2 ),	/* Offset= 2 (40) */
/* 40 */	NdrFcShort( 0x10 ),	/* 16 */
/* 42 */	NdrFcShort( 0x2b ),	/* 43 */
/* 44 */	NdrFcLong( 0x3 ),	/* 3 */
/* 48 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 50 */	NdrFcLong( 0x11 ),	/* 17 */
/* 54 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 56 */	NdrFcLong( 0x2 ),	/* 2 */
/* 60 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 62 */	NdrFcLong( 0x4 ),	/* 4 */
/* 66 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 68 */	NdrFcLong( 0x5 ),	/* 5 */
/* 72 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 74 */	NdrFcLong( 0xb ),	/* 11 */
/* 78 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 80 */	NdrFcLong( 0xa ),	/* 10 */
/* 84 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 86 */	NdrFcLong( 0x6 ),	/* 6 */
/* 90 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (304) */
/* 92 */	NdrFcLong( 0x7 ),	/* 7 */
/* 96 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 98 */	NdrFcLong( 0x8 ),	/* 8 */
/* 102 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (310) */
/* 104 */	NdrFcLong( 0xd ),	/* 13 */
/* 108 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (334) */
/* 110 */	NdrFcLong( 0x9 ),	/* 9 */
/* 114 */	NdrFcShort( 0xffffff98 ),	/* Offset= -104 (10) */
/* 116 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 120 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (352) */
/* 122 */	NdrFcLong( 0x24 ),	/* 36 */
/* 126 */	NdrFcShort( 0x2f6 ),	/* Offset= 758 (884) */
/* 128 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 132 */	NdrFcShort( 0x2f0 ),	/* Offset= 752 (884) */
/* 134 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 138 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (888) */
/* 140 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 144 */	NdrFcShort( 0x2ec ),	/* Offset= 748 (892) */
/* 146 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 150 */	NdrFcShort( 0x2ea ),	/* Offset= 746 (896) */
/* 152 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 156 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (900) */
/* 158 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 162 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (904) */
/* 164 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 168 */	NdrFcShort( 0x2d4 ),	/* Offset= 724 (892) */
/* 170 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 174 */	NdrFcShort( 0x2d2 ),	/* Offset= 722 (896) */
/* 176 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 180 */	NdrFcShort( 0x2d8 ),	/* Offset= 728 (908) */
/* 182 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 186 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (904) */
/* 188 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 192 */	NdrFcShort( 0x2d0 ),	/* Offset= 720 (912) */
/* 194 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 198 */	NdrFcShort( 0x2ce ),	/* Offset= 718 (916) */
/* 200 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 204 */	NdrFcShort( 0x2cc ),	/* Offset= 716 (920) */
/* 206 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 210 */	NdrFcShort( 0x2ca ),	/* Offset= 714 (924) */
/* 212 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 216 */	NdrFcShort( 0x2c8 ),	/* Offset= 712 (928) */
/* 218 */	NdrFcLong( 0x10 ),	/* 16 */
/* 222 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 224 */	NdrFcLong( 0x12 ),	/* 18 */
/* 228 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 230 */	NdrFcLong( 0x13 ),	/* 19 */
/* 234 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 236 */	NdrFcLong( 0x16 ),	/* 22 */
/* 240 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 242 */	NdrFcLong( 0x17 ),	/* 23 */
/* 246 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 248 */	NdrFcLong( 0xe ),	/* 14 */
/* 252 */	NdrFcShort( 0x2ac ),	/* Offset= 684 (936) */
/* 254 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 258 */	NdrFcShort( 0x2b2 ),	/* Offset= 690 (948) */
/* 260 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 264 */	NdrFcShort( 0x2b0 ),	/* Offset= 688 (952) */
/* 266 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 270 */	NdrFcShort( 0x26e ),	/* Offset= 622 (892) */
/* 272 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 276 */	NdrFcShort( 0x26c ),	/* Offset= 620 (896) */
/* 278 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 282 */	NdrFcShort( 0x266 ),	/* Offset= 614 (896) */
/* 284 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 288 */	NdrFcShort( 0x260 ),	/* Offset= 608 (896) */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x0 ),	/* Offset= 0 (294) */
/* 296 */	NdrFcLong( 0x1 ),	/* 1 */
/* 300 */	NdrFcShort( 0x0 ),	/* Offset= 0 (300) */
/* 302 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (301) */
/* 304 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 310 */	
			0x12, 0x0,	/* FC_UP */
/* 312 */	NdrFcShort( 0xc ),	/* Offset= 12 (324) */
/* 314 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 316 */	NdrFcShort( 0x2 ),	/* 2 */
/* 318 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 320 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 322 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 324 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 328 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (314) */
/* 330 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 332 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 334 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 344 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 346 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 348 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 350 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 352 */	
			0x12, 0x10,	/* FC_UP */
/* 354 */	NdrFcShort( 0x2 ),	/* Offset= 2 (356) */
/* 356 */	
			0x12, 0x0,	/* FC_UP */
/* 358 */	NdrFcShort( 0x1fc ),	/* Offset= 508 (866) */
/* 360 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 362 */	NdrFcShort( 0x18 ),	/* 24 */
/* 364 */	NdrFcShort( 0xa ),	/* 10 */
/* 366 */	NdrFcLong( 0x8 ),	/* 8 */
/* 370 */	NdrFcShort( 0x58 ),	/* Offset= 88 (458) */
/* 372 */	NdrFcLong( 0xd ),	/* 13 */
/* 376 */	NdrFcShort( 0x78 ),	/* Offset= 120 (496) */
/* 378 */	NdrFcLong( 0x9 ),	/* 9 */
/* 382 */	NdrFcShort( 0x94 ),	/* Offset= 148 (530) */
/* 384 */	NdrFcLong( 0xc ),	/* 12 */
/* 388 */	NdrFcShort( 0xbc ),	/* Offset= 188 (576) */
/* 390 */	NdrFcLong( 0x24 ),	/* 36 */
/* 394 */	NdrFcShort( 0x114 ),	/* Offset= 276 (670) */
/* 396 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 400 */	NdrFcShort( 0x130 ),	/* Offset= 304 (704) */
/* 402 */	NdrFcLong( 0x10 ),	/* 16 */
/* 406 */	NdrFcShort( 0x148 ),	/* Offset= 328 (734) */
/* 408 */	NdrFcLong( 0x2 ),	/* 2 */
/* 412 */	NdrFcShort( 0x160 ),	/* Offset= 352 (764) */
/* 414 */	NdrFcLong( 0x3 ),	/* 3 */
/* 418 */	NdrFcShort( 0x178 ),	/* Offset= 376 (794) */
/* 420 */	NdrFcLong( 0x14 ),	/* 20 */
/* 424 */	NdrFcShort( 0x190 ),	/* Offset= 400 (824) */
/* 426 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (425) */
/* 428 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 430 */	NdrFcShort( 0x4 ),	/* 4 */
/* 432 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 438 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 440 */	NdrFcShort( 0x4 ),	/* 4 */
/* 442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 444 */	NdrFcShort( 0x1 ),	/* 1 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 450 */	0x12, 0x0,	/* FC_UP */
/* 452 */	NdrFcShort( 0xffffff80 ),	/* Offset= -128 (324) */
/* 454 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 456 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 458 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 462 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 464 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 466 */	NdrFcShort( 0x4 ),	/* 4 */
/* 468 */	NdrFcShort( 0x4 ),	/* 4 */
/* 470 */	0x11, 0x0,	/* FC_RP */
/* 472 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (428) */
/* 474 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 476 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 478 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 490 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 492 */	NdrFcShort( 0xffffff62 ),	/* Offset= -158 (334) */
/* 494 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 496 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 498 */	NdrFcShort( 0x8 ),	/* 8 */
/* 500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x6 ),	/* Offset= 6 (508) */
/* 504 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 506 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 508 */	
			0x11, 0x0,	/* FC_RP */
/* 510 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (478) */
/* 512 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 524 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 526 */	NdrFcShort( 0xfffffdfc ),	/* Offset= -516 (10) */
/* 528 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 530 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 532 */	NdrFcShort( 0x8 ),	/* 8 */
/* 534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 536 */	NdrFcShort( 0x6 ),	/* Offset= 6 (542) */
/* 538 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 540 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 542 */	
			0x11, 0x0,	/* FC_RP */
/* 544 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (512) */
/* 546 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 548 */	NdrFcShort( 0x4 ),	/* 4 */
/* 550 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 556 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 558 */	NdrFcShort( 0x4 ),	/* 4 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x1 ),	/* 1 */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	0x12, 0x0,	/* FC_UP */
/* 570 */	NdrFcShort( 0xfffffdc6 ),	/* Offset= -570 (0) */
/* 572 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 574 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 576 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x6 ),	/* Offset= 6 (588) */
/* 584 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 586 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 588 */	
			0x11, 0x0,	/* FC_RP */
/* 590 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (546) */
/* 592 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 594 */	NdrFcLong( 0x2f ),	/* 47 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 604 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 606 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 608 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 610 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 612 */	NdrFcShort( 0x1 ),	/* 1 */
/* 614 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 618 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 620 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 622 */	NdrFcShort( 0x10 ),	/* 16 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0xa ),	/* Offset= 10 (636) */
/* 628 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 630 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 632 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (592) */
/* 634 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 636 */	
			0x12, 0x0,	/* FC_UP */
/* 638 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (610) */
/* 640 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 642 */	NdrFcShort( 0x4 ),	/* 4 */
/* 644 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 648 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 650 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 652 */	NdrFcShort( 0x4 ),	/* 4 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x1 ),	/* 1 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 662 */	0x12, 0x0,	/* FC_UP */
/* 664 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (620) */
/* 666 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 668 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 670 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x6 ),	/* Offset= 6 (682) */
/* 678 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 680 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 682 */	
			0x11, 0x0,	/* FC_RP */
/* 684 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (640) */
/* 686 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 690 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 692 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 694 */	NdrFcShort( 0x10 ),	/* 16 */
/* 696 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 698 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 700 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (686) */
			0x5b,		/* FC_END */
/* 704 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 706 */	NdrFcShort( 0x18 ),	/* 24 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0xa ),	/* Offset= 10 (720) */
/* 712 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 714 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 716 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (692) */
/* 718 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 720 */	
			0x11, 0x0,	/* FC_RP */
/* 722 */	NdrFcShort( 0xffffff0c ),	/* Offset= -244 (478) */
/* 724 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 726 */	NdrFcShort( 0x1 ),	/* 1 */
/* 728 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 734 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 738 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 740 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 742 */	NdrFcShort( 0x4 ),	/* 4 */
/* 744 */	NdrFcShort( 0x4 ),	/* 4 */
/* 746 */	0x12, 0x0,	/* FC_UP */
/* 748 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (724) */
/* 750 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 752 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 754 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 756 */	NdrFcShort( 0x2 ),	/* 2 */
/* 758 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 762 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 764 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 768 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 770 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 772 */	NdrFcShort( 0x4 ),	/* 4 */
/* 774 */	NdrFcShort( 0x4 ),	/* 4 */
/* 776 */	0x12, 0x0,	/* FC_UP */
/* 778 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (754) */
/* 780 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 782 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 784 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 786 */	NdrFcShort( 0x4 ),	/* 4 */
/* 788 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 794 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 796 */	NdrFcShort( 0x8 ),	/* 8 */
/* 798 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 800 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 802 */	NdrFcShort( 0x4 ),	/* 4 */
/* 804 */	NdrFcShort( 0x4 ),	/* 4 */
/* 806 */	0x12, 0x0,	/* FC_UP */
/* 808 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (784) */
/* 810 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 812 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 814 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 824 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 830 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 832 */	NdrFcShort( 0x4 ),	/* 4 */
/* 834 */	NdrFcShort( 0x4 ),	/* 4 */
/* 836 */	0x12, 0x0,	/* FC_UP */
/* 838 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (814) */
/* 840 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 842 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 844 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 850 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 852 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 854 */	NdrFcShort( 0x8 ),	/* 8 */
/* 856 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 858 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 860 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 862 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (844) */
/* 864 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 866 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 868 */	NdrFcShort( 0x28 ),	/* 40 */
/* 870 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (852) */
/* 872 */	NdrFcShort( 0x0 ),	/* Offset= 0 (872) */
/* 874 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 876 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 878 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 880 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffdf7 ),	/* Offset= -521 (360) */
			0x5b,		/* FC_END */
/* 884 */	
			0x12, 0x0,	/* FC_UP */
/* 886 */	NdrFcShort( 0xfffffef6 ),	/* Offset= -266 (620) */
/* 888 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 890 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 892 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 894 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 896 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 898 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 900 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 902 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 904 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 906 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 908 */	
			0x12, 0x0,	/* FC_UP */
/* 910 */	NdrFcShort( 0xfffffda2 ),	/* Offset= -606 (304) */
/* 912 */	
			0x12, 0x10,	/* FC_UP */
/* 914 */	NdrFcShort( 0xfffffda4 ),	/* Offset= -604 (310) */
/* 916 */	
			0x12, 0x10,	/* FC_UP */
/* 918 */	NdrFcShort( 0xfffffdb8 ),	/* Offset= -584 (334) */
/* 920 */	
			0x12, 0x10,	/* FC_UP */
/* 922 */	NdrFcShort( 0xfffffc70 ),	/* Offset= -912 (10) */
/* 924 */	
			0x12, 0x10,	/* FC_UP */
/* 926 */	NdrFcShort( 0xfffffdc2 ),	/* Offset= -574 (352) */
/* 928 */	
			0x12, 0x10,	/* FC_UP */
/* 930 */	NdrFcShort( 0x2 ),	/* Offset= 2 (932) */
/* 932 */	
			0x12, 0x0,	/* FC_UP */
/* 934 */	NdrFcShort( 0xfffffc5a ),	/* Offset= -934 (0) */
/* 936 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 938 */	NdrFcShort( 0x10 ),	/* 16 */
/* 940 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 942 */	0x1,		/* FC_BYTE */
			0x38,		/* FC_ALIGNM4 */
/* 944 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 946 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 948 */	
			0x12, 0x0,	/* FC_UP */
/* 950 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (936) */
/* 952 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 954 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 956 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 958 */	NdrFcShort( 0x20 ),	/* 32 */
/* 960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 962 */	NdrFcShort( 0x0 ),	/* Offset= 0 (962) */
/* 964 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 966 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 968 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 970 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 972 */	NdrFcShort( 0xfffffc54 ),	/* Offset= -940 (32) */
/* 974 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 976 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x10 ),	/* 16 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0xfffffc44 ),	/* Offset= -956 (28) */
/* 986 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 988 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

const CInterfaceProxyVtbl * _WinLNP_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_ILNPManagerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILNPPortProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILNPPortPrivateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILNPSessionPrivateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILNPManagerPrivateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ILNPSessionProxyVtbl,
    0
};

const CInterfaceStubVtbl * _WinLNP_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_ILNPManagerStubVtbl,
    ( CInterfaceStubVtbl *) &_ILNPPortStubVtbl,
    ( CInterfaceStubVtbl *) &_ILNPPortPrivateStubVtbl,
    ( CInterfaceStubVtbl *) &_ILNPSessionPrivateStubVtbl,
    ( CInterfaceStubVtbl *) &_ILNPManagerPrivateStubVtbl,
    ( CInterfaceStubVtbl *) &_ILNPSessionStubVtbl,
    0
};

PCInterfaceName const _WinLNP_InterfaceNamesList[] = 
{
    "ILNPManager",
    "ILNPPort",
    "ILNPPortPrivate",
    "ILNPSessionPrivate",
    "ILNPManagerPrivate",
    "ILNPSession",
    0
};

const IID *  _WinLNP_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0,
    0,
    0,
    &IID_IDispatch,
    0
};


#define _WinLNP_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _WinLNP, pIID, n)

int __stdcall _WinLNP_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _WinLNP, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _WinLNP, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _WinLNP, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _WinLNP, 6, *pIndex )
    
}

const ExtendedProxyFileInfo WinLNP_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _WinLNP_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _WinLNP_StubVtblList,
    (const PCInterfaceName * ) & _WinLNP_InterfaceNamesList,
    (const IID ** ) & _WinLNP_BaseIIDList,
    & _WinLNP_IID_Lookup, 
    6,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
