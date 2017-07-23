#include<stdio.h>
#include<math.h>

int CntPrimes(int n);
int GetPrime(int number);
int IsPrime(int number);

int main()
{
    int n;
    scanf("%d", &n);

    printf("%d", CntPrimes(n));
    return 0;
}

int CntPrimes(int n)
{
    int i;
    int cnt = 0;
    for (i = 3; i <= n - 2; i += 2)
    {
        if (GetPrime(i))
        {
            cnt++;
        }
    }
    return cnt;
}

int GetPrime(int number)
{

    if (IsPrime(number) && IsPrime(number + 2))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int IsPrime(int number)
{
    int i;
    for (i = 2; i<=sqrt(number); i++)
    {
        if (number%i == 0)
        {
            return 0;
        }
    }
    return 1;
}