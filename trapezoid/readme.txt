TO RUN ON LOCAL MACHINE

open window cmd or terminal and execute the trapezoidal.exe file 




TO RUN ON GITHUB CODESPACE 

cd /workspaces/MathToolkit/trapezoid                 path
gcc -o trapezoidal trapezoidal.c                     compile
chmod +x trapezoidal                                 permission
./trapezoidal                                        run


Because <conio.h> not a standard part of the C language defined by ANSI C or ISO C standards. 
Thus, use getchar() instead getch() from conio.h
