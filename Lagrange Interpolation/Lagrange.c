#include <stdio.h>
#include <conio.h>

float lagrangeInterpolation(float x[], float y[], int n, float xp)
{
    float yp = 0;

    for (int i = 0; i < n; i++)
    {
        float p = 1;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                p *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        yp += p * y[i];
    }

    return yp;
}

int main()
{
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    float x[n], y[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter x[%d] and y[%d]: ", i, i);
        scanf("%f %f", &x[i], &y[i]);
    }

    float xp;
    printf("Enter the interpolation point: ");
    scanf("%f", &xp);

    float yp = lagrangeInterpolation(x, y, n, xp);
    printf("The interpolated value at %f is %f\n", xp, yp);

    getch();
}
