#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getCofactor(double **A, double **temp, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row != p && col != q)
            {
                temp[i][j++] = A[row][col];
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

double determinant(double **A, int n)
{
    if (n == 1)
    {
        return A[0][0];
    }
    double det = 0;
    int sign = 1;
    double **temp = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = (double *)malloc((n - 1) * sizeof(double));
    }

    for (int f = 0; f < n; f++)
    {
        getCofactor(A, temp, 0, f, n);
        det += sign * A[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    for (int i = 0; i < n - 1; i++)
    {
        free(temp[i]);
    }
    free(temp);

    return det;
}

void adjoint(double **A, double **adj, int n)
{
    if (n == 1)
    {
        adj[0][0] = 1;
        return;
    }
    int sign = 1;
    double **temp = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n - 1; i++)
    {
        temp[i] = (double *)malloc((n - 1) * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            getCofactor(A, temp, i, j, n);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            adj[j][i] = (sign) * (determinant(temp, n - 1));
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        free(temp[i]);
    }
    free(temp);
}

int inverse(double **A, double **inverse, int n)
{
    double det = determinant(A, n);
    if (det == 0)
    {
        printf("Singular matrix, can't find its inverse.\n");
        return 0;
    }
    double **adj = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        adj[i] = (double *)malloc(n * sizeof(double));
    }
    adjoint(A, adj, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inverse[i][j] = adj[i][j] / det;
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(adj[i]);
    }
    free(adj);

    return 1;
}

void display(double **A, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%0.5g   ", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the size of the square matrix (N x N): ");
    scanf("%d", &n);

    // Dynamically allocate memory for the matrix
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Enter the elements of the %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }

    printf("The input matrix is:\n");
    display(A, n);

    // Dynamically allocate memory for the inverse matrix
    double **inv = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        inv[i] = (double *)malloc(n * sizeof(double));
    }

    if (inverse(A, inv, n))
    {
        printf("The inverse of the matrix is:\n");
        display(inv, n);
    }
    else
    {
        printf("The matrix is not invertible.\n");
    }

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(A[i]);
        free(inv[i]);
    }
    free(A);
    free(inv);

    return 0;
}
