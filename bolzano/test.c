#include <stdio.h>
#include <conio.h>
#include <math.h>

#define f(x) (x * x * x - 2 * x - 5)

int main()
{

    float a, b, iter;

    printf("\nthe eq is x^3-2x-5=0");
    printf("\nenter the value of a and b");

    scanf("%f\n%f", &a, &b);
    printf("\nenter the value of itteration");
    scanf("%f", &iter);

    if (f(a) * f(b) > 0)
    {
        printf("\nthe value of a and b is not valid");
        exit(0);
    }

    else
    {
        for (int i = 1; i < +iter; i++)
        {
            float mid = (a + b) / 2;
            if (f(mid) == 0)
            {
                printf("\nthe root is %f", mid);
                exit(0);
            }
            else if (f(a) * f(mid) < 0)
            {
                b = mid;
            }
            else
            {
                a = mid;
            }
            printf("\nthe root after %d itterarion is %f", i, mid);
        }
    }
    getch();
    return 0;
}