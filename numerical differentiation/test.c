#include <stdio.h>
#include <math.h>
#include <conio.h>

float p(int n, float u)
{
    float res = 1;
    for (int i = 0; i < n; i++)
    {
        res = res * (u - i);
    }
    return res;
}

int fac(int n)
{
    int r = 1;
    for (int i = 1; i <= n; i++)
    {
        r = r * i;
    }
    return r;
}

int main()
{

    int x, y;
    float u, h;

    printf("Enter the order of x");
    scanf("%d", &x);
    float arx[x];
    float ary[x][x];

    for (int i = 0; i < x; i++)
    {
        printf("\nEnter the value of x%d ", i);
        scanf("%f", &arx[i]);
    }

    for (int i = 0; i < x; i++)
    {
        printf("\nEnter the value of y%d ", i);
        scanf("%f", &ary[i][0]);
    }

    printf("\nThe value of x  where you find is ");
    scanf("%d", &y);

    h = arx[1] - arx[0];
    u = (y - arx[0]) / h;

    for (int i = 0; i < x - 1; i++)
    {
        for (int j = 0; j < x - 1; j++)
        {
            float temp;
            temp = ary[j + 1][i] - ary[j][i];
            ary[j][i + 1] = temp;
        }
    }
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x - i; j++)
        {
            printf("%f\t", ary[i][j]);
        }
        printf("\n");
    }

    float res = ary[0][0];
    for (int i = 1; i < x; i++)
    {
        res = res + ((ary[0][i]) * p(i, u)) / fac(i);
    }
    printf("The value of y is %f", res);

    getch();
    return 0;
}