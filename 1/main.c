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

    printf("������� ���������� �����: ");
    scanf("%d", &n);

    printf("������� ���������� ��������: ");
    scanf("%d", &m);

    // ��������� ������ ��� ��������� �� ������
    a = (int**)malloc(n * sizeof(int*));

    // ���� ��������� �������
    for (int i = 0; i < n; i++)  // ���� �� �������
    {
        // ��������� ������ ��� �������� �����
        a[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++)  // ���� �� ��������
        {
          printf("a[%d][%d] = ", i, j);
          scanf("%d", &a[i][j]);
        }
    }

    // ��������� ������ �� ���������� ������ b �������� n*m
    b = (int*)malloc(n * m * sizeof(int*));

    // ���������� ������� b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            b[i*m + j] = a[i][j];
        }
    }

    int flag = 1;
    while(flag) // ���� �������������� �������� �� � � b
    {
        printf("\n������� i � j ��� �������� a[i][j] � b[k]: ");
        scanf("%d%d", &i, &j);
        from_a_to_b(a, m, b, i, j);
        printf("���������� ������� ��������� �� � � b? \n0 - ��� \n1 - ��\n");
        scanf("%d", &flag);
    }

    flag = 1;
    while(flag) // ���� �������������� �������� �� b � a
    {
        printf("\n������� k ��� �������� b[k] � a[i][j]: ");
        scanf("%d", &k);
        from_b_to_a(a, m, b, k);
        printf("���������� ������� ��������� �� b � a? \n0 - ��� \n1 - ��\n");
        scanf("%d", &flag);
    }



    return 0;
}
