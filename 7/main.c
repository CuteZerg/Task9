#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_arr(double **a, int n)
{
    printf("\n\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2lf ", a[i][j]);
        }
        printf("\n");
    }
}


void upper_triangle(double **a, int n, int k)
{
    double coef;
    while (k >= 1)
    {
        for (int i = n - k; i < n; i++)
        {
            if (a[n-k-1][n-k-1] != 0)
                coef = a[i][n-k-1]/a[n-k-1][n-k-1];
            else
                continue;
            for (int j = 0; j < n; j++)
            {
                a[i][j] -= a[n-k-1][j]*coef;
            }
        }
        k--;
    }
}

void lower_triangle(double **a, int n, int k)
{
    double coef;
    while (k >= 1)
    {
        for (int i = k-1; i >= 0; i--)
        {
            if (a[k][k] != 0)
                coef = a[i][k]/a[k][k];
            else
                continue;
            for (int j = 0; j < n; j++)
            {
                a[i][j] -= a[k][j]*coef;
            }
        }
        k--;
    }
}


int main()
{
    double **a;
    double det = 1;
    int n;
    setlocale(LC_ALL, "Rus");

    printf("Введите количество строк/столбцов в матрице: ");
    scanf("%d", &n);

    a = (double**)malloc(n * sizeof(double*));


    for (int i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
          printf("a[%d][%d] = ", i, j);
          scanf("%lf", &a[i][j]);
        }
    }

    upper_triangle(a, n, n-1);
    lower_triangle(a, n, n-1);

    for (int i = 0;i < n;i++)
    {
        det *= a[i][i];
    }
    printf("\n%lf", det);


    return 0;
}
