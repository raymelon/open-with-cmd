::
:: compile-main.bat
:: Compiles main.c to exe file using gcc 4.8.1
::
:: (c) April 2015 Raymel Francisco
::
@windres src/main.rc -O coff -o res/main.res
@gcc -m32 -o bin/open-with-cmd.exe src/main.c res/main.res
@pause
