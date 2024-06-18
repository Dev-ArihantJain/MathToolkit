#include <stdio.h>
#include <math.h>
#include <conio.h>

#define f(x) (x * x * x - 2 * x - 5)

float df(float x)
{
    float R;
    R = 3 * x * x - 2;
    return R;
}

int main()
{

    float x0, x1, iter, err;

    printf("\nEnter the initial guess: ");
    scanf("%f", &x0);
    printf("\nEnter the number of iterations: ");
    scanf("%f", &iter);
    printf("\nEnter the number of err: ");
    scanf("%f", &err);

    for (int i = 0; i <= iter; i++)
    {
        x1 = x0 - (f(x0) / df(x0));
        printf("\nnext root is %f", x1);
        if (fabs(x0 - x1) < err)
        {
            printf("\nthe final root is %f", x0);
            return 0;
        }
        x0 = x1;
    }

    getch();
    return 0;
}