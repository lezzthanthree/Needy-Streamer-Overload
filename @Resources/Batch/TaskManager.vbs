Set WshShell = CreateObject("WScript.Shell")
WshShell.Run "cmd.exe /c ""taskmgr.bat""", 0
Set WshShell = Nothing