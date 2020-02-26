
var LNPManager;
var LNPSession;
var fileName = "C:\\Projects\\LegOS\\Legos-0.2.3\\TestPrg\\helloworld.lx";

function MsgBox(str)
{
	var WshShell = new ActiveXObject("Wscript.Shell");
	WshShell.popup(str);	
}

LNPManager = new ActiveXObject("WinLNP.LNPManager");

LNPManager.DownloadProgram(0, 1, fileName);
MsgBox("Downloaded into slot1");
LNPManager.RunProgram(0, 1);
MsgBox("Downloaded into slot1");


LNPManager.DownloadProgram(0, 2, fileName);
MsgBox("Downloaded into slot2");
LNPManager.RunProgram(0, 2);
MsgBox("Downloaded into slot2");


LNPManager.DownloadProgram(0, 5, fileName);
MsgBox("Downloaded into slot5");
LNPManager.RunProgram(0, 5);
MsgBox("Downloaded into slot5");


LNPManager.DownloadProgram(0, 6, fileName);
MsgBox("Downloaded into slot6");
LNPManager.RunProgram(0, 6);
MsgBox("Downloaded into slot6");





