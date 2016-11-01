::
:: compile-uninstall.bat
:: Compiles uninstall.c to exe file using gcc 4.8.1
::
:: (c) May 2015 Raymel Francisco
::
@windres src/uninstall.rc -O coff -o res/uninstall.res
@gcc -m32 -o bin/uninstall.exe src/uninstall.c res/uninstall.res
@pause
