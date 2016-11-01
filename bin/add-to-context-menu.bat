::
:: add-to-context-menu.bat
:: Adds "Open with command prompt" to context menu
::
:: (c) April 2015 Raymel Francisco
::
@echo off
set location=F:\Documents\Random Files\My C samples\C Projects\Open with cmd\v1.0\bin\open-with-cmd.exe

reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt" /t REG_SZ /v "" /d "Open with command prompt" /f
reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt" /t REG_EXPAND_SZ /v "Icon" /d "%location%,0" /f
reg add "HKEY_CLASSES_ROOT\*\shell\Open with command prompt\command" /t REG_SZ /v "" /d "%location% \"%%1\"" /f

pause
