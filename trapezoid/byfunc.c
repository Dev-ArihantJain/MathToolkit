#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

#define f(x) (sin(x))+x


void main()
{
  //clrscr();
  system("cls");

  //variables
    float a=0 ,b=0 ;
    float h;
    float result ;
    float fx[10];


 // function limit parameter
printf("\nEnter the Value of Function Limits\n");

    printf("Enter The Lower Limit = ");
    scanf("%f",&a);

    printf("Enter The Upper Limit = ");
    scanf("%f",&b);


h =(b-a)/6;

printf("\nWidth Of Each Sub-interval = %f\n",h);
printf("--------------------------------------------------------\n");


// value of y=f(x)
for (int i = 0; i<= 6; i++)
{
   fx[i]=f(a);
    printf("At x = %-10.4f   ||      Function Gets f(x%d) = %0.4f\n",(a),i,fx[i]);
    //printf("fx got %f\n",a+(i*h));
    a=a+h;
}


result= (h)*(((fx[0]+fx[6])/2)+fx[1]+fx[3]+fx[5]+fx[2]+fx[4]);
printf("--------------------------------------------------------\n");

printf("\n******    The Final Result Is = %f    ******\n",result);

getch();

}

