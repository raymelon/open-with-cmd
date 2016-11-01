Set shell = WScript.CreateObject("WScript.Shell")
startup = shell.SpecialFolders.Item("Startup")
command = "cmd.exe /C copy ""open-with-cmd-clean.bat"" """ & startup & """"
shell.run command
