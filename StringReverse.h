#include <string.h>

void reverse(char s[])
{
	int length = strlen(s);
	int half = length/2;
	int i = 0;
	for(; i < half; i++)
	{
		char temp = s[i];
		s[i] = s[length-i-1];
		s[length-i-1] = temp;
	}
}
