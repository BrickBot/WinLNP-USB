
WinLNPps.dll: dlldata.obj WinLNP_p.obj WinLNP_i.obj
	link /dll /out:WinLNPps.dll /def:WinLNPps.def /entry:DllMain dlldata.obj WinLNP_p.obj WinLNP_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del WinLNPps.dll
	@del WinLNPps.lib
	@del WinLNPps.exp
	@del dlldata.obj
	@del WinLNP_p.obj
	@del WinLNP_i.obj
