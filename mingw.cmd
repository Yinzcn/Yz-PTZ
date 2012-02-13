
@rem ÷∏∂® MinGW Œª÷√
@set mingw=D:\MinGW
@set path=C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;%mingw%\bin


:make
windres -i res.rc -o res.o -O coff
gcc Yz_PTZ_win.c res.o -lgdi32 -lcomctl32 -Wall

@if not exist a.exe pause
a.exe
@goto make


:error
pause
@goto make
