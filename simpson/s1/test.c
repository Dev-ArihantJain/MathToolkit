#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x)
{
    return (1 + x) / (1 + x * x);
}

int main()
{

    float a, b, n;

    printf("\nEnter the value of limits of integration");
    printf("\nEnter the value of a");
    scanf("%f", &a);
    printf("\nEnter the value of b");
    scanf("%f", &b);
    printf("\nEnter the value of n");
    scanf("%f", &n);

    float h = (b - a) / n;

    float sum = h * (f(a) + f(b)) / 3;
    printf("\n The value of sum is %f", sum);

    for (int i = 1; i < n; i++)
    {
        if (i % 2 == 0)
            (
                sum = sum + 2 * h * f(a + i * h) / 3);
        else
        {
            sum = sum + 4 * h * f(a + i * h) / 3;
        }
    }

    printf("\n The value of integral is %f", sum);

    getch();
    return 0;
}