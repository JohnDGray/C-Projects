#include <stdio.h>
#include <stdlib.h>
#include "/home/john/Documents/CCode/StringReverse.h"
char getChar(int n);
int power(int base, int exp);
void itob(int n, char s[], int b);

int main(int argc, char **argv)
{
	char output[1000];
	int num = atoi(argv[1]);
	int base = atoi(argv[2]);
	itob(num, output, base);
	printf("%s\n", output);
	return 0;
}

char getChar(int n)
{
	if(n < 0)
	{
		printf("Don't pass such numbers.\n");
		exit(1);
	}
	if(n < 10)
	{
		return n + '0';
	}
	return (n - 10) + 'a';
}

int power(int base, int exp)
{
	int output = 1;
	while(exp > 0)
	{
		output *= base;
		exp--;
	}
	return output;
}

void itob(int n, char s[], int b)
{
	if(b < 2 || b > 35)
	{
		printf("Invalid base.\n");
		exit(1);
	}
	long bigger = n;
	if(bigger < 0)
	{
		bigger = -bigger;
	}
	
	int pow = 0;
	int product = 1;
	while(1)
	{
		product *= b;
		if(product > bigger)
		{
			break;
		}
		pow++;
	}
	int i = 0;
	if(n < 0)
	{
		s[i++] = '-';
	}
	while(pow >= 0)
	{
		int next = power(b, pow);
		if(next > bigger)
		{
			s[i++] = '0';
		}
		else
		{
			int amount = bigger/next;
			s[i++] = getChar(amount);
			bigger -= (next*amount);
		}
		pow--;
	}
	s[i] = '\0';
}
