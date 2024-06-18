#include<stdio.h>
#include<conio.h>
#include<math.h>



main(){

int xn ;

printf("enter the number of x parameter\n");
scanf("%d",&xn);
float arr[xn][xn] ;

for (int i = 0; i < xn; i++)
{
    printf("enter the valuen of the x%d\n",i);
    scanf("%f",&arr[i][0]);
}


for (int j = 0; j < xn-1; j++)
{

    for (int i = 0; i<xn-1; i++)
    {
    int temp=0 ;
    temp = arr[i][j]-arr[i+1][j];
    arr[i][j+1]=temp;
    }
    // for (int i = 0; i < xn; i++)
    // {
    // printf("\t%f \t %f \n",arr[i][j],arr[i][j+1]);
    
    
}


    for (int i = 0; i < xn; i++)
    {
        for (int j= 0; j < xn-i ; j++)
        {
            printf("%f  ",arr[i][j]);
        }
        printf("\n");
    }
}











