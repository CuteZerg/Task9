#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void from_a_to_b(int **a, int m, int *b, int i, int j)
{
    printf("a[%d][%d] = b[%d] = %d\n\n", i, j, i*m + j, b[i*m + j]);
}

void from_b_to_a(int **a, int m, int *b, int k)
{
    printf("b[%d] = a[%d][%d] = %d\n\n", k, k / m, k % m, a[k / m][k % m]);
}

int main()
{
    int **a;
    int *b;
    int n,m;
    int i,j,k;
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
          printf("a[%d][%d] = ", i, j);
          scanf("%d", &a[i][j]);
        }
    }

    // Выделение памяти на одномерный массив b размером n*m
    b = (int*)malloc(n * m * sizeof(int*));

    // Заполнение массива b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i*m + j] = a[i][j];
        }
    }

    int flag = 1;
    while(flag) // Цикл множественного перевода из а в b
    {
        printf("\nВведите i и j для перевода a[i][j] в b[k]: ");
        scanf("%d%d", &i, &j);
        from_a_to_b(a, m, b, i, j);
        printf("Продолжить перевод элементов из а в b? \n0 - нет \n1 - да\n");
        scanf("%d", &flag);
    }

    flag = 1;
    while(flag) // Цикл множественного перевода из b в a
    {
        printf("\nВведите k для перевода b[k] в a[i][j]: ");
        scanf("%d", &k);
        from_b_to_a(a, m, b, k);
        printf("Продолжить перевод элементов из b в a? \n0 - нет \n1 - да\n");
        scanf("%d", &flag);
    }



    return 0;
}
