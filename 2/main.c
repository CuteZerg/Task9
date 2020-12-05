#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void func1(int **a,int n,int m,int x,int y)
{
    if( (x == n - 1) || (y == m - 1) )
    {
        if (x == n - 1)
        {
            int j = 1;
            for (int i = y; i < m; i++)
            {
                a[x][i] = j;
                j++;
            }
        }
        else
        {
            int j = 1;
            for (int i = x; i < n; i++)
            {
                a[i][y] = j;
                j++;
            }
        }
    }
    else
    {
        int j = 1;
        for(int i = x; i < n; i++)
        {
            a[i][y] = j;
            j++;
        }

        j = 1;
        for (int i = y; i < m; i++)
        {
            a[x][i] = j;
            j++;
        }

        func1(a, n, m, x + 1, y + 1);
    }
}

void func2(int **a, int n, int m, int x, int y, int k)
{
    if( (m - 2*x <= 2) || (n - 2*y <= 2) )
    {
        if (n - 2*y == 1)
        {
            for(int i = x; i < m - x; i++)
            {
                a[y][i] = k;
                k++;
            }
        }
        else if (m - 2*x == 1)
        {
            for(int i = y; i < n - y; i++)
            {
                a[i][x] = k;
                k++;
            }
        }
        else if (m - 2*x == 2)
        {
            a[y][x] = k;
            k++;
            for(int i = y; i < n - y;i++)
            {
                a[i][x+1] = k;
                k++;
            }
            for (int i = n - y - 1; i > y; i--)
            {
                a[i][x] = k;
                k++;
            }
        }
        else if (n - 2*y == 2)
        {
            for(int i = x; i < m - x; i++)
            {
                a[y][i] = k;
                k++;
            }
            for(int i = m - x - 1; i > x - 1; i--)
            {
                a[y+1][i] = k;
                k++;
            }
        }
    }
    else
    {
        for (int i = x; i < m - x; i++)
        {
            a[y][i] = k;
            k++;
        }
        for (int i = y+1; i < n - y; i++)
        {
            a[i][m - x - 1] = k;
            k++;
        }
        for (int i = m - x - 2; i > x - 1; i--)
        {
            a[n - y - 1][i] = k;
            k++;
        }
        for (int i = n - y - 2; i > y; i--)
        {
            a[i][x] = k;
            k++;
        }
        func2(a, n, m, x+1, y+1, k);
    }
}

int main()
{
    int **a;
    int n,m;
    setlocale(LC_ALL, "Rus");

    printf("Введите количество строк: ");
    scanf("%d", &n);

    printf("Введите количество столбцов: ");
    scanf("%d", &m);

    // Выделение памяти под указатели на строки
    a = (int**)malloc(n * sizeof(int*));

    // Ввод элементов массива
    for (int i = 0; i < n; i++)  // цикл по строкам
    {
        // Выделение памяти под хранение строк
        a[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)  // цикл по столбцам
        {
          a[i][j] = 0;
        }
    }

    func1(a, n, m, 0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");


    func2(a, n, m, 0, 0, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0;j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
