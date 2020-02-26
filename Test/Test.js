
var LNPManager;
var LNPSession;
var LNPPort;

function MsgBox(str)
{
	var WshShell = new ActiveXObject("Wscript.Shell");
	WshShell.popup(str);	
}


LNPManager = new ActiveXObject("WinLNP.LNPManager");

var data = new Array(3);

LNPSession = LNPManager.CreateSession();

MsgBox("SessionID = " + LNPSession.GetSessionID());

LNPPort = LNPSession.OpenPort(0,0);

MsgBox("Host ID = " + LNPPort.GetHostID());
MsgBox("Port ID = " + LNPPort.GetPortID());

LNPPort.Send("0x01 0x01");

MsgBox("The End");



