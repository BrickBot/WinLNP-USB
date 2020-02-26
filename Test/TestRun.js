
var LNPManager;
var LNPSession;
var LNPPort;

function MsgBox(str)
{
	var WshShell = new ActiveXObject("Wscript.Shell");
	WshShell.popup(str);	
}



LNPManager = new ActiveXObject("WinLNP.LNPManager");
LNPManager.RunProgram(0,5);




