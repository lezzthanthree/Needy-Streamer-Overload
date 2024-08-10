Set WshShell = CreateObject("WScript.Shell")
WshShell.Run "cmd.exe /c ""search.bat""", 0
Set WshShell = Nothing