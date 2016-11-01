::
:: add-cleaner-to-startup.bat
:: Bypasses default powershell scripts execution policy, then runs the powershell script
::
:: (c) May 2015 Raymel Francisco
::
powershell.exe -noprofile -executionpolicy bypass -file add-cleaner-to-startup.ps1
