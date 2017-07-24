#include<stdio.h>
#include<stdlib.h>

void MoveArray(int* p, int move, int n);
void ScanArray(int* p, int n);
void PrintArray(int* p, int n);

int main()
{
    int n, move;
    scanf("%d %d", &n, &move);
    int *p = (int*)malloc(n * sizeof(int));
    ScanArray(p, n);

    //int a[6] = { 1,2,3,4,5,6 };
    //int *p = a;

    MoveArray(p, move, n);

    PrintArray(p, n);
    return 0;
}

void MoveArray(int* p, int move, int n)
{
    int cnt;
    int i;
    int temp = *(p + n - 1);

    for (cnt = 0; cnt < move; cnt++)
    {
        temp = *(p + n - 1);
        for (i = n - 2; i >= 0; i--)
        {
            *(p + i + 1) = *(p + i);
        }
        *p = temp;
    }
    /*for (i = 0; i < n - move; i++)
    {
    temp = *(p + i + move);
    *(p + i + move) = *(p + i);
    *(p + i) = temp;
    }
    for (i = n - move; i < n; i++)
    {
    temp = *(p + i + move - n);
    *(p + i + move - n) = *(p + i);
    *(p + i) = temp;
    }*/
}

void ScanArray(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%d", p++);
    }
}

void PrintArray(int* p, int n)
{
    printf("%d", *p++);
    for (int i = 1; i < n; i++)
    {
        printf(" %d", *p++);
    }
}