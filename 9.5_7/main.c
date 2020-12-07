#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void t9_5()
{
    void swap_rows(double **a, int r1, int r2, int n)
    {
        int tmp;
        for (int j = 0; j < n+1; j++)
        {
            tmp = a[r1][j];
            a[r1][j] = a[r2][j];
            a[r2][j] = tmp;
        }
    }

    void prepare(double **a, int n)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if( (a[j][j] == 0) && (a[i][j] != 0) )
                {
                    swap_rows(a, j, i, n);
                }
            }
        }
    }

    void print_arr(double **a, int n)
    {
        printf("\n\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n+1; j++)
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
                for (int j = 0; j < n+1; j++)
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
                for (int j = 0; j < n + 1; j++)
                {
                    a[i][j] -= a[k][j]*coef;
                }
            }
            k--;
        }
    }


    double **a;
    int n;

    printf("Введите количество переменных: ");
    scanf("%d", &n);

    a = (double**)malloc(n * sizeof(double*));


    for (int i = 0; i < n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n+1; j++)
        {
          printf("a[%d][%d] = ", i, j);
          scanf("%lf", &a[i][j]);
        }
    }
    prepare(a, n);
    upper_triangle(a, n, n-1);
    lower_triangle(a, n, n-1);

    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i+1, a[i][n]/a[i][i]);
    }
}

void t9_6()
{
    void swap_rows(double **a, int r1, int r2, int n)
    {
        int tmp;
        for (int j = 0; j < 2*n; j++)
        {
            tmp = a[r1][j];
            a[r1][j] = a[r2][j];
            a[r2][j] = tmp;
        }
    }

    void prepare(double **a, int n)
    {
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if( (a[j][j] == 0) && (a[i][j] != 0) )
                {
                    swap_rows(a, j, i, n);
                }
            }
        }
    }

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


    void print_arr(double **a, int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
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

    double **a;
    double **a_copy;
    double **a_m;
    double **e;
    int n;

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

    prepare(a, n);
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
    print_arr(a_copy,n,n);

    printf("\nОбратная матрица:\n");
    print_arr(a_m, n,n);

    printf("\nПроизведение обратной матрицы к исходной:\n");
    multiply(e, a_m, a_copy, n);
    print_arr(e, n,n);

}

void t9_7()
{
    void swap_rows(double **a, int r1, int r2, int n)
    {
        int tmp;
        for (int j = 0; j < 2*n; j++)
        {
            tmp = a[r1][j];
            a[r1][j] = a[r2][j];
            a[r2][j] = tmp;
        }
    }


    int prepare(double **a, int n)
    {
        int k = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if( (a[j][j] == 0) && (a[i][j] != 0) )
                {
                    swap_rows(a, j, i, n);
                    k++;
                }
            }
        }
        return k%2;
    }


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

    double **a;
    double det = 1;
    int n;

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
    int k = prepare(a, n);
    upper_triangle(a, n, n-1);
    lower_triangle(a, n, n-1);

    for (int i = 0;i < n;i++)
    {
        det *= a[i][i];
    }
    if (!k)
        printf("\n%lf", det);
    else
        printf("\n%lf", -det);
}

int main()
{
    int task;
    setlocale(LC_ALL, "Rus");
    printf("Введите номер таска для вызова (цифра от 5 до 7): ");
    scanf("%d", &task);
    printf("\n");
    switch(task)
    {
        case 5:
            t9_5();
            break;

        case 6:
            t9_6();
            break;

        case 7:
            t9_7();
            break;
    }
    return 0;
}
