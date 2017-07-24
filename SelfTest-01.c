#include<stdio.h>
#include<math.h>
                
int GetLine(int n);
void Print(int line, char mark);

int main()
{
    char mark;
    int n;
    scanf("%d %c", &n, &mark);
    int line = GetLine(n);
    Print(line, mark);
    printf("%d", n - (6 * line + line*(line-1)*4 / 2) -1);
    return 0;
}

int GetLine(int n)
{
    int temp = 2;
    int number = 1;
    int line = 0;
    while (number <= n)
    {
        line++;
        temp += 4;
        number += temp;
    }
    line--;
    return line;
}

 void Print(int line, char mark)
{
    int cnt;
    for (int i = -line; i <= line; i++)
    {
        cnt = -abs(i) + line;

        for (int i = 0; i < cnt; i++)
            printf(" ");

        for (int j = 1; j <= 2 * abs(i) + 1; j++)
        {
            printf("%c", mark);
        }

        printf("\n");
    }
}