#include <stdio.h>
#include <conio.h>
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

float fx(float a, int arr[], int o)
{

    float r = 0, y;
    for (int i = 0; i <= o; i++)
    {
        y = power(a, (o - i));

        r = r + ((arr[i]) * y);
    }
    return r;
}

float dfx(float x, int arr[], int o)
{
    float r = 0;
    for (int i = 0; i <= o - 1; i++)
    {
        r = r + arr[i] * power(x, o - 1 - i) * (o - i);
    }
    return r;
}

float root(float x, int arr[], int o)
{

    float x1;

    x1 = x - (fx(x, arr, o) / dfx(x, arr, o));

    return x1;
}

int main()
{

    int o;
    int arr[10], itr;
    float a, q, err, xnew;

    printf("\nEnter the order of equation = ");
    scanf("%d", &o);
    for (int i = 0; i <= o; i++)
    {
        printf("\nEnter the x^%d coefficient of eq = ", (o - i));
        scanf("%d", &arr[i]);
    }

    printf("\nTHe value of intial root = ");
    scanf("%f", &a);

    printf("\nEnter the error value = ");
    scanf("%f", &err);

    printf("\nMax itrration = ");
    scanf("%d", &itr);

    for (int i = 1; i <= itr; i++)
    {

        if (i == itr)
        {
            printf("\n max itr reach\n");
        }

        xnew = root(a, arr, o);
        if (fabs(xnew - a) < err)
        {
            printf("\n For %d itr final value of fx at x=%f is fx=%f\n", i, a, fx(a, arr, o));
            return 0;
        }

        printf("\n For %d itr value of fx at x=%f is fx=%f\n", i, a, fx(a, arr, o));

        a = xnew;
    }

    getch();
}