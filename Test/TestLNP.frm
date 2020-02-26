VERSION 5.00
Begin VB.Form Form1 
   Caption         =   "Form1"
   ClientHeight    =   8205
   ClientLeft      =   60
   ClientTop       =   345
   ClientWidth     =   10365
   LinkTopic       =   "Form1"
   ScaleHeight     =   8205
   ScaleWidth      =   10365
   StartUpPosition =   3  'Windows Default
   Begin VB.CheckBox UseSystemSession 
      Caption         =   "Use System Session(Port 0)"
      Height          =   375
      Left            =   360
      TabIndex        =   14
      Top             =   1080
      Width           =   2895
   End
   Begin VB.CheckBox KeepAlive 
      Caption         =   "Enable Tower Keep Alive "
      Height          =   255
      Left            =   6240
      TabIndex        =   13
      Top             =   360
      Width           =   2415
   End
   Begin VB.CommandButton DisconnectBtn 
      Caption         =   "Disconnect"
      Height          =   375
      Left            =   6240
      TabIndex        =   12
      Top             =   1800
      Width           =   1575
   End
   Begin VB.CommandButton ConnectBtn 
      Caption         =   "Connect"
      Height          =   375
      Left            =   4320
      TabIndex        =   11
      Top             =   1800
      Width           =   1575
   End
   Begin VB.TextBox PortID 
      Height          =   375
      Left            =   1680
      TabIndex        =   5
      Top             =   2280
      Width           =   1815
   End
   Begin VB.TextBox HostID 
      Height          =   375
      Left            =   1680
      TabIndex        =   3
      Top             =   1800
      Width           =   1815
   End
   Begin VB.CommandButton SendBtn 
      Caption         =   "Send"
      Height          =   375
      Left            =   8640
      TabIndex        =   2
      Top             =   3240
      Width           =   1095
   End
   Begin VB.TextBox MsgToSend 
      Height          =   375
      Left            =   360
      TabIndex        =   1
      Top             =   3240
      Width           =   7455
   End
   Begin VB.TextBox Log 
      Height          =   3615
      Left            =   360
      MultiLine       =   -1  'True
      TabIndex        =   0
      Top             =   4200
      Width           =   9735
   End
   Begin VB.Label OurPortID 
      Caption         =   "---"
      Height          =   255
      Left            =   1680
      TabIndex        =   10
      Top             =   720
      Width           =   1455
   End
   Begin VB.Label Label4 
      Caption         =   "Our Port ID :"
      Height          =   255
      Left            =   360
      TabIndex        =   9
      Top             =   720
      Width           =   1455
   End
   Begin VB.Label OurHostID 
      Caption         =   "---"
      Height          =   255
      Left            =   1680
      TabIndex        =   8
      Top             =   360
      Width           =   1455
   End
   Begin VB.Label Label3 
      Caption         =   "Our Host ID :"
      Height          =   255
      Left            =   360
      TabIndex        =   7
      Top             =   360
      Width           =   1455
   End
   Begin VB.Label Label2 
      Caption         =   "Port ID"
      Height          =   255
      Left            =   360
      TabIndex        =   6
      Top             =   2340
      Width           =   1095
   End
   Begin VB.Label Label1 
      Caption         =   "Host ID"
      Height          =   255
      Left            =   360
      TabIndex        =   4
      Top             =   1860
      Width           =   1095
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private gWinLNP As LNPManager
Attribute gWinLNP.VB_VarHelpID = -1
Private gSession As LNPSession
Private WithEvents gPort As LNPPort
Attribute gPort.VB_VarHelpID = -1
Private gConnected As Boolean


Private Sub Check1_Click()

End Sub

Private Sub Form_Load()
                                 
    Set gWinLNP = New LNPManager
    Set gSession = gWinLNP.CreateNewSession()
    
    OurHostID.Caption = gWinLNP.GetPCHostID()
    OurPortID.Caption = gSession.GetSessionID()
    HostID.Text = 0
    PortID.Text = 1
    
    UseSystemSession.Value = False
    
    KeepAlive.Value = gWinLNP.IsKeepAliveRunning()
        
        
End Sub
Private Sub UseSystemSession_Click()

    Set gPort = Nothing
    Set gSession = Nothing
    
    If (UseSystemSession.Value) Then
        Set gSession = gWinLNP.CreateSessionOnPort(0)
        OurPortID.Caption = gSession.GetSessionID()
    Else
        Set gSession = gWinLNP.CreateNewSession()
        OurPortID.Caption = gSession.GetSessionID()
    End If
End Sub


Private Sub ConnectBtn_Click()
    
    If (Not gConnected) Then
        Log.Text = Log.Text & "Connecting " & _
                   "HostID=" & HostID.Text & ", " & _
                   "PortID=" & PortID.Text & Chr(13) & Chr(10)
        Set gPort = gSession.OpenPort(HostID.Text, PortID.Text)
        Call gPort.SetDataFormat(BSTR_FormatedString)
        gConnected = True
    End If

End Sub

Private Sub DisconnectBtn_Click()

    If (gConnected) Then
        Log.Text = Log.Text & "Disconnecting " & _
                   "HostID=" & gPort.GetHostID & ", " & _
                   "PortID=" & gPort.GetPortID & Chr(13) & Chr(10)
        Set gPort = Nothing
        gConnected = False
    End If

End Sub

Private Sub SendBtn_Click()

    If (gConnected) Then
        Call gPort.Send(MsgToSend.Text)
        Log.Text = Log.Text & _
                   "HostID=" & HostID.Text & ", " & _
                   "PortID=" & PortID.Text & " : " & _
                   MsgToSend.Text & Chr(13) & Chr(10)
    Else
        Log.Text = Log.Text & "No Connection !" & Chr(13) & Chr(10)
    End If

End Sub

Private Sub KeepAlive_Click()
    gWinLNP.RunKeepAlive (KeepAlive.Value)
End Sub


Private Sub gPort_DataHandler(ByVal vData As Variant)
    Log.Text = Log.Text & "Received data form " & _
               "HostID=" & gPort.GetHostID() & ", " & _
               "PortID=" & gPort.GetPortID() & " : " & _
               vData & Chr(13) & Chr(10)
End Sub

