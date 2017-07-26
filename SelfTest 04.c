#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Answer(char num1[], int sata1[], char num2[], int sata2[]);
void Answer1(char num1[], int sata1[], char num2[], int sata2[]);
void Answer2(char num1[], char num2[]);
char* Double(char num1[], char num2[]);
int * Stat(char num[], int a[]);
int FindTail(char num[]);

int main()
{
    char num1[21] = "\0";
    int sata1[10] = { 0 };

    char num2[22] = "\0";
    int sata2[10] = { 0 };

    scanf("%s", &num1);

    Answer(num1, sata1, num2, sata2);

    return 0;
}


void Answer(char num1[], int sata1[], char num2[], int sata2[])
{
    Answer1(num1, sata1, num2, sata2);
    Answer2(num1, num2);
}

void Answer1(char num1[], int sata1[], char num2[], int sata2[])
{
    Stat(num1, sata1); 
    Stat(Double(num1, num2), sata2);

    int flag = 1;
    for (int i = 0; i < 10; i++)
    {
        if (sata1[i] != sata2[i])
        {
            printf("No");
            flag = 0;
            break;
        }
    }
    if(flag)
    {
        printf("Yes");
    }
}

void Answer2(char num1[], char num2[])
{
    printf("\n%s", Double(num1, num2));
}

char* Double(char num1[], char num2[])
{
    int carry = 0;
    int digit = 20;
    char num[22] = { 0 };
    char * i = num;
    for (int i = FindTail(num1); i >= 0; i--)
    {
        int n = 2 * (num1[i] - '0') + carry;
        num[digit--] = (n % 10 + '0');
        carry = n / 10;
    }
    if (carry)
    {
        num[digit] = carry + '0';
    }
    for (i = num; *i == '\0'; i++);
    //strcmp(num2, i);
    for (int cnt = 0; *i != '\0'; cnt++,i++)
    {
        num2[cnt] = *i;
    }
    return num2;
}

int * Stat(char num[], int a[])
{
    for (int i = 0; num[i] != '\0'; i++)
    {
        a[num[i] - '0']++;
    }
    return a;
}

int FindTail(char num[])
{
    int i;
    for (i = 0; num[i] != '\0'; i++);
    return i - 1;
}