TO RUN ON LOCAL MACHINE

open window cmd or terminal and execute the simpson1by3.exe file 




TO RUN ON GITHUB CODESPACE 

cd /workspaces/MathToolkit/simpson                   path
gcc -o simpson1by3 simpson1by3.c                     compile
chmod +x simpson1by3                                 permission
./simpson1by3                                        run


Because <conio.h> not a standard part of the C language defined by ANSI C or ISO C standards. 
Thus, use getchar() instead getch() from conio.h
