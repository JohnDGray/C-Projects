#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "/home/john/Documents/CCode/StringReverse.h"
#define MAX 1000

void itoa(int n, char s[]);

int main(int argc, char **argv)
{
	char string[MAX];
	int num = INT_MIN;
	printf("%d\n", num);
	itoa(num, string);
	printf("%s\n", string);
	return 0;
}

void itoa(int n, char s[])
{
	int i, sign;
	long bigger = n;
	if ((sign = n) < 0)
	{
		bigger = -bigger;
	}
	i = 0;
	do 
	{
		s[i++] = bigger % 10 + '0';
	} while ((bigger /= 10) > 0);
	if (sign < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
