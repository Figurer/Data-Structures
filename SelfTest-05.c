#include<stdio.h>
#include<stdlib.h>

void ScanOrder(int a[]);
void InitCards(char a[][4]);
void Shuffling(char cards[][4], int order[]);
void PrintCards(char cards[][4], int order[]);

int main()
{
    //int t;
    //scanf("%d", &t);

    int order[1+54];
    ScanOrder(order);
    
    char cards[1+54][4] = { "\0" };
    InitCards(cards);

    Shuffling(cards, order);

    PrintCards(cards, order);

    return 0;
}


void ScanOrder(int a[])
{
    for (int i = 0; i <= 54; i++)
    {
        scanf("%d", &a[i]);
    }
}

void InitCards(char a[][4])
{
    for (int i = 1; i <= 54; i++)
    {
        switch ((i - 1) / 13)
        {
        case 0:
            a[i][0] = 'S';
            break;
        case 1:
            a[i][0] = 'H';
            break;
        case 2:
            a[i][0] = 'C';
            break;
        case 3:
            a[i][0] = 'D';
            break;
        case 4:
            a[i][0] = 'J';
            break;
        default:
            break;
        }
        if ((i-1) % 13 < 9)
        {
            a[i][1] = i % 13 + '0';
        }
        else
        {
            a[i][1] = (((i-1) % 13)+1) / 10 + '0';
            a[i][2] = (((i-1) % 13)+1) % 10 + '0';
        }
    }
}

void Shuffling(char cards[][4], int order[])
{
    int a[55] = { 0 };
    int b[55] = { 0 };
    for (int i = 1; i <= 54; i++)
    {
        b[i] = i;
    }

    int t = 0;
    while (t < order[0])
    {
        for (int cnt = 1; cnt <= 54; cnt++)//做54次改写
        {
            for (int i = 1; i <= 54; i++)//寻找每一次该找的值
            {
                if (order[i] == cnt)
                {
                    a[cnt] = b[i];
                }
            }
        }
        t++;
        for (int i = 0; i <= 54; i++)
        {
            b[i] = a[i];
        }
    }
    
    for (int i = 0; i <= 54; i++)
    {
        order[i] = b[i];
    }
}

void PrintCards(char a[][4], int order[])
{
    printf("%s", a[order[1]]);
    for (int i = 2; i <= 54; i++)
    {
        printf(" %s", a[order[i]]);
    }
}