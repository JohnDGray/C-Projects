#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long num = 600851475143;
    long pFactor = 0;
    int i;
    for(i = 3; i < num; i += 2)
    {
        if(isPrime(i))
        {
            if(num % i == 0)
            {
                pFactor = i;
            }
        }
    }

    printf("%ld\n", pFactor);
}

int isPrime(long n)
{
    int i;
    int root = sqrt(n);
    for(i = 3; i < root; i += 2)
    {
        if(n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
