typedef struct
{
	char ch;
} StackData;

#include "Stack.h"
#define SIZE 1000
void expand(char s1[], char s2[]);
char getChar(StackData sd);
StackData getSD(char c);

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		printf("Please pass an argument.\n");
		exit(1);
	}
	int length = sizeof(argv[1])/sizeof(char);	
	if(length > SIZE / 2)
	{
		printf("Are you trying to trick me again mister?\n");
		exit(1);
	}
	char *s1 = argv[1];
	char s2[SIZE];
	s2[SIZE - 1] = '\0';
	expand(s1, s2);
	
	printf("output: %s\n", s2);
	return 0;
}

void expand(char s1[], char s2[])
{
	Stack* S = initStack();	
	int s1Ind = 0;
	int s2Ind = 0;
	while(s1[s1Ind] != '\0')
	{
		if(s2Ind == SIZE)
		{
			printf("The string s2 did not have enough capacity.\n");
			exit(1);
		}
		char next = s1[s1Ind++];
		if(empty(S))
		{
			if(next == '-')
			{
				if(s1Ind == 1 || s1[s1Ind] == '\0')
				{
					s2[s2Ind++] = next;
				}
			}
			else
			{
				push(S, getSD(next));
			}
			continue;
		}
		char last = getChar(pop(S));
		if(last == '-')
		{
			if(empty(S) || next == '-' || getChar(peek(S)) == '-')
			{
				printf("Improperly formatted string.\n");
				exit(1);
			}
			char index = getChar(pop(S));
			for(;index <= next; index++)
			{
				if(s2Ind == SIZE)
				{
					printf("The string s2 did not have enough capacity.\n");
					exit(1);
				}
				s2[s2Ind++] = index;
			}
		}
		else
		{
			if(s2Ind == SIZE)
			{
				printf("The string s2 did not have enough capacity.\n");
				exit(1);
			}
			if(next != '-')
			{
				s2[s2Ind++] = last;
				push(S, getSD(next));
			}
			else
			{
				push(S, getSD(last));
				push(S, getSD(next));
			}
		}
	}
	char final;
	if(!empty(S))
	{
		char final = getChar(pop(S));
		if(!empty(S))
		{
			printf("Improperly formatted string.\n");
			exit(1);
		}
		if(s2Ind == SIZE)
		{
			printf("The string s2 did not have enough capacity.\n");
			exit(1);
		}
		s2[s2Ind++] = final;
	}
	s2[s2Ind] = '\0';
}

char getChar(StackData sd)
{
	return sd.ch;
}

StackData getSD(char c)
{
	StackData sd;
	sd.ch = c;
	return sd;
}
