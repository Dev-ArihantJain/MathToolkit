#include <stdio.h>
// #include <conio.h>
#include <math.h>
#include <stdlib.h>

int fact(int n)
{
    int r = 1;
    for (int i = 0; i < n; i++)
    {
        r = r * (n - i);
    }
    return r;
}

float p(int n, float u)
{
    float r = 1;
    for (int i = 0; i < n; i++)
    {
        r = r * (u - i);
    }
    return r;
}

void main()
{
    system("cls");
    int xn;
    printf("Enter The Order Of X Parameter = ");
    scanf("%d", &xn);

    float arr[xn][xn];
    float arx[xn];
    float u, x, h;

    for (int i = 0; i < xn; i++)
    {
        printf("Enter The Value Of X%d = ", i);
        scanf("%f", &arx[i]);
    }

    printf("\n");
    for (int i = 0; i < xn; i++)
    {
        printf("Enter The Value Of The Function At X%d = ", i);
        scanf("%f", &arr[i][0]);
    }

    printf("\nEnter The Point Where To Find F(X) = ");
    scanf("%f", &x);

    h = fabs(arx[1] - arx[0]);
    // printf("h is%f\n",h);
    u = (x - arx[0]) / h;
    // printf("u is%f\n",u);

    for (int j = 0; j < xn - 1; j++)
    {

        for (int i = 0; i < xn - 1; i++)
        {
            int temp = 0;
            temp = arr[i + 1][j] - arr[i][j];
            arr[i][j + 1] = temp;
        }
    }

    printf("%6s%s    ", "", "x");

    for (int i = 0; i < xn; i++)
    {
        printf("%17sy%d", "", i);
    }

    printf("\n------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < xn; i++)
    {
        printf("%10.4f\t", arx[i]);
        for (int j = 0; j < xn - i; j++)
        {
            printf("%18.4f", arr[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------------------------------------------------------------------\n");

    float sum = arr[0][0];
    for (int i = 1; i < xn - 2; i++)
    {
        sum = sum + ((arr[0][i]) * p(i, u)) / (fact(i));
    }
    printf("\n------------------------------------------------------------------------------------------\n");
    printf("\t\t\t********* Result is %f *********\n", sum);
    printf("------------------------------------------------------------------------------------------\n");
}
