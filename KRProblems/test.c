#include <stdio.h>
#include <stdlib.h>

double myatof(char s[]);

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		printf("Wrong number of arguments.\n");
	}
	double result = myatof(argv[1]); 
	printf("%f\n", result);
	return 0;
}
