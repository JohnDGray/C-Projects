#include "/home/john/Documents/CCode/StringReverse.h"
#include <stdio.h>

void itoa(int n, char s[], int width);

int main(int argc, char **argv)
{
	char output[1000];
	int n = atoi(argv[1]);
	int width = atoi(argv[2]);
	itoa(n, output, width);
	printf("%s\n", output);
	return 0;
}

void itoa(int n, char s[], int width)
{
	long bigger = n;
	if(n < 0)
	{
		bigger = -bigger;
	}
	int i = 0;
	do
	{
		s[i++] = bigger % 10 + '0';
	} while((bigger /= 10) > 0);
	while(i < width)
	{
		s[i++] = '0';
	}
	if(n < 0)
	{
		s[i++] = '-';
	}
	s[i] = '\0';
	reverse(s);
}
