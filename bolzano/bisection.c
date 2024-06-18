#include <stdio.h>
// #include <conio.h>
#include <math.h>
#define f(x) (x*x) - 4
// #define f(x) pow(x, 2) - 4

void main()
{
    printf("\nf(x) = x^2 - 4\n");

    float a, b, mid, check, err;
    int maxitr;

    printf("Enter the value of A =");
    scanf("%f", &a);

    printf("Enter the value of B = ");
    scanf("%f", &b);

    if (f(a) > 0 && f(b) > 0)
    {
        for (float i = f(a); f(b) > 0; i++)

        {
            printf("the value of b is not lead the function to converge please reenter that = ");
            scanf("%f", &b);
        }
    }

    if (f(a) < 0 && f(b) < 0)
    {
        for (float i = f(a); f(b) < 0; i++)
        {
            printf("the value of b is not lead the function to converge please reenter that = ");
            scanf("%f", &b);
        }
    }

    if (f(a) == 0)
    {
        printf("your root is = %f", a);
        return;
    }
    if (f(b) == 0)
    {
        printf("your root is = %f", b);
        return;
    }

    printf("\nEnter the value of err = ");
    scanf("%f", &err);

    printf("\nEnter the value of maxitr = ");
    scanf("%d", &maxitr);

    for (int i = 1; i < maxitr; i++)
    {
        mid = (a + b) / 2;
        if (fabs(mid - check) < err)
        {
            printf("\n***** your final result reach at %d iteration with the value %f *****", i, check);
            return;
        }

        if (f(mid) < 0)
        {
            a = mid;
        }
        else
        {
            b = mid;
        }
        check = mid;

        printf("\nAt %d iteration the value of function is = %f ", i, mid);
    }

    printf("\nyour result is %f", mid);
}