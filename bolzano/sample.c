#include <stdio.h>
#include <conio.h>
#include <math.h>
#define f(x) pow(x, 2) - 4

int main()
{

    float a, b, mid, check, err;
    int maxitr;

    printf("enter the value of a");
    scanf("%f", &a);

    printf("enter the value of b");
    scanf("%f", &b);

    if ((f(a)*f(b)) > 0 || (f(a)*f(b)) == 0)
    {
        printf("root does not lies between %f and %f", a, b);
        exit(0);
    }

    printf("enter the value of err");
    scanf("%f", &err);

    printf("enter the value of maxitr");
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

    printf("your result is %f", mid);
    getch();
    return 0;
}