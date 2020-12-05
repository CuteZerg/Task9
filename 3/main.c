#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int **a;
    setlocale(LC_ALL, "Rus");

    a = (int**)malloc(9 * sizeof(int*));

    for (int i = 0; i < 9; i++)
    {
        a[i] = (int*)malloc(9 * sizeof(int));
        printf("Через пробел введите %d-ую строчку массива: ", i+1);
        scanf("%d%d%d%d%d%d%d%d%d", &a[i][0], &a[i][1], &a[i][2], &a[i][3], &a[i][4], &a[i][5], &a[i][6], &a[i][7], &a[i][8]);
    }

    int k = 0;
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = k; j < 9 - k;j++)
        {
            sum += a[i][j];
        }
        if (i < 4)
            k++;
        else
            k--;
    }
    printf("Итоговая сумма равна %d", sum);
    return 0;
}
