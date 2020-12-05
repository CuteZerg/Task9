#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void insertion_sort(int *a, int *b, int n)
{
    int tmp, j, tmp_ind;
    for(int i = 1;i < n;i++)
    {
        tmp = a[i];
        tmp_ind = b[i];
        j = i;
        while( (j > 0) && (a[j-1] > tmp) )
        {
            a[j] = a[j-1];
            b[j] = b[j-1];
            j = j-1;
        }
        a[j] = tmp;
        b[j] = tmp_ind;
    }
}


int main()
{
    int **a;
    int *sum;
    int *ind_s;
    int *tmp;

    int n,m;
    setlocale(LC_ALL, "Rus");

    printf("Введите количество строк: ");
    scanf("%d", &n);

    printf("Введите количество столбцов: ");
    scanf("%d", &m);

    a = (int**)malloc(n * sizeof(int*));
    sum = (int*)malloc(m * sizeof(int));
    ind_s = (int*)malloc(m * sizeof(int));
    tmp = (int*)malloc(m * sizeof(int));


    for(int i = 0; i < m;i++)
    {
        ind_s[i] = i;
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
            sum[j] += a[i][j];
        }
    }

    insertion_sort(sum, ind_s, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tmp[j] = a[i][ind_s[j]];
        }
        for (int j = 0;j < m; j++)
        {
            a[i][j] = tmp[j];
        }
    }

    printf("\nПреобразованный массив:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }


    return 0;
}
