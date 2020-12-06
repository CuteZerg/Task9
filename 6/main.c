#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void multiply(double **result, double **m1, double **m2, int n)
{

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for(int k = 0; k < n; k++)
            {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
}


void print_arr(double **a, int n)
{
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
            for (int j = 0; j < 2*n; j++)
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
            for (int j = 0; j < 2*n; j++)
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
    double **a_copy;
    double **a_m;
    double **e;
    int n;
    setlocale(LC_ALL, "Rus");

    printf("Введите количество строк/столбцов в матрице: ");
    scanf("%d", &n);

    e = (double**)malloc(n * sizeof(double*));
    a_m = (double**)malloc(n * sizeof(double*));
    a = (double**)malloc(n * sizeof(double*));
    a_copy = (double**)malloc(n * sizeof(double*));

    for (int i = 0;i < n;i++)
    {
        e[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(2*n * sizeof(double));
        for (int j = 0; j < n; j++)
        {
          printf("a[%d][%d] = ", i, j);
          scanf("%lf", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        a_copy[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n;j++)
        {
            a_copy[i][j] = a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = n; j < 2*n; j++)
        {
            if (i == j-n)
                a[i][j] = 1;
            else
                a[i][j] = 0;
        }
    }


    upper_triangle(a, n, n-1);
    lower_triangle(a, n, n-1);

    double coef;
    for(int i = 0; i<n; i++)
    {
        coef = a[i][i];
        for(int j = 0;j < 2*n;j++)
        {
            a[i][j] /= coef;
        }
    }

    for(int i = 0; i < n; i++)
    {
        a_m[i] = (double*)malloc(n * sizeof(double));
        for(int j = 0;j < n;j++)
        {
            a_m[i][j] = a[i][j+n];
        }
    }

    printf("\nИсходная матрица:\n");
    print_arr(a_copy,n);

    printf("\nОбратная матрица:\n");
    print_arr(a_m, n);

    printf("\nПроизведение обратной матрицы к исходной:\n");
    multiply(e, a_m, a_copy, n);
    print_arr(e, n);

    return 0;
}
