#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

float power(float x, int y)
{

    int i;
    float t = 1;
         for (i = 0; i < y; i++)
        {
        t = t * x;
         }
    return t;
}

float eq(float up, float down)
{
    float fx;

    fx = up / down;

    return fx;
}

float up(float x, int arr[], int o1)
{

    float r = 0, y ;
    for (int i = 0; i <= o1; i++)
    {
        y = power(x, (o1 - i));

        r = r + ((arr[i]) * y);
    }
    return r;
}

float down(float x, int arr[], int o2)
{

    float r = 0, y;
    for (int i = 0; i <= o2; i++)
    {
        y = power(x, (o2 - i));

        r = r + ((arr[i]) * y);

        
    }
        if(r==0)
            {
                printf("function goes to infinte , simplify your function first\n");
                return 0 ;
            }
    return r;
}


void main()
{
  //clrscr();
  system("cls");

  //variables
    int o1 = 0;      int o2 = 0;
    float x = 0;     float rt =0 ; 
    int arrup[10];   int arrdown[10];
    float a=0 ,b=0 ;
    int n ; 
    float h;
    float fx[6] ; float result ;
    

//function nominator
    printf("Enter The Order Of Nominator Equation = ");
    scanf("%d", &o1);
    for (int i = 0; i <= o1; i++)
    {
        printf("Enter The X^%d Coefficient Of Eq = ",(o1 - i));
        scanf("%d", &arrup[i]);
    }

 

//funnction denominator
    printf("\nEnter The Order Of Denominator Equation = ");
    scanf("%d", &o2);
    for (int i = 0; i <= o2; i++)
    {
        printf("Enter The X^%d Coefficient Of Eq = ", (o2 - i));
        scanf("%d", &arrdown[i]);
    }

  

 // value of fx at particularly value of x
 /*    printf("enter the value of x\n");
    scanf("%f",&x);  

//value of fx at x
    rt = eq( up(x,arrup,o1) , down(x,arrdown,o2) );
    printf("total alue of x%f",rt);  */


 // function limit parameter
printf("\nEnter the Value of Function Limits\n");

    printf("Enter The Lower Limit = ");
    scanf("%f",&a);

    printf("Enter The Upper Limit = ");
    scanf("%f",&b);


h =(b-a)/6;

printf("\nWidth Of Each Sub-interval = %f\n\n",h);

// value of y=f(x)
for (int i = 0; i<= 6; i++)
{
   fx[i] = eq(up((a+i*h),arrup,o1) , down(a+(i*h),arrdown,o2) );
    printf("At x = %-10.4f   ||      Function Gets = %0.4f\n",(a+i*h),fx[i]);
    //printf("fx got %f\n",a+(i*h));
}


result= (h/3)*(fx[0]+fx[6]+ 4*(fx[1]+fx[3]+fx[5])+2*(fx[2]+fx[4]));

printf("\n******    The Final Result Is = %f    ******\n",result);

getch();

}

