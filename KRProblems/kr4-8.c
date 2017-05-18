#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <limits.h>

#define MAXOP 100
#define NUMBER '0'
#define COMMAND '1'
#define VARIABLE '2'

int getop(char[]);
int empty();
void push(double);
double pop(void);
double peek(void); 
void duplicate(void);
void swap(void);
void assign(char, double);
double getvar(char);
int isassigned(char);
void clearvars(void);

main()
{
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

int empty(void)
{
	return sp == 0;
}

void push(double f)
{
	if(sp < MAXVAL)
	{
		val[sp++] = f;
	}
	else
	{
		printf("error: stack full, can't push %g\n", f);
	}
}

double pop(void)
{
	if(sp > 0)
	{
		return val[--sp];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

double peek(void)
{
	if(sp > 0)
	{
		return val[sp - 1];
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

void duplicate(void)
{
	if(sp > 0)
	{
		push(peek());
	}
	else
	{
		printf("error: stack empty\n");
	}
}

void swap(void)
{
	if(sp > 1)
	{
		double temp1 = pop();
		double temp2 = pop();
		push(temp1);
		push(temp2);
	}
	else
	{
		printf("error: stack contains less than two elements\n");
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c, minus;

	while((s[0] = c = getch()) == ' ' || c == '\t')
	{
		;
	}
	s[1] = '\0';
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		c = getch();
		if(!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
		{
			ungetch(c);
			return VARIABLE;
		}
		s[1] = c;
		int j = 1;
		s[++j] = c = getch();
		while((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		{
			s[++j] = c = getch();
		}
		ungetch(c);
		s[j] = '\0';
		return COMMAND;
	}
	if(!isdigit(c) && c != '.' && c != '-')
	{
		return c;
	}
	if(c == '-')
	{
		c = getch();
		if(!isdigit(c) && c != '.')
		{
			ungetch(c);
			return '-';
		}
	}
	i = 0;
	if(isdigit(c))
	{
		if(s[0] == '-')
		{
			s[++i] = c;
		}
		while(isdigit(s[++i] = c = getch()))
		{
			;
		}
	}
	if(c == '.')
	{
		while(isdigit(s[++i] = c = getch()))
		{
			;
		}
	}
	s[i] = '\0';
	if(c != EOF)
	{
		ungetch(c);
	}
	return NUMBER;
}

int buf; 
int bufUsed = 0;

int getch(void)
{
	if(!bufUsed)
	{
		printf("No character in buffer.\n");
		return;
	}
	bufUsed = 0;
	return buf;
}

void ungetch(int c)
{
	if(bufUsed == 1)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		bufUsed = 1;
		buf = c;
	}
}

double variables[26];
double assigned[26]; 

void assign(char variable, double value)
{
	int index = variable - 'a';
	if(index < 0 || index > 25)
	{
		printf("error: illegal variable name %c\n", variable);
		exit(1);
	}
	assigned[index] = 1;
	variables[index] = value;
}

double getvar(char variable)
{
	int index = variable - 'a';
	if(index < 0 || index > 25)
	{
		printf("error: illegal variable name %c\n", variable);
		exit(1);
	}
	if(!assigned[index])
	{
		printf("error: attempt to use unassigned variable %c\n", variable);
		exit(1);
	}
	return variables[index];
}

int isassigned(char variable)
{
	return variable >= 'a' && variable <= 'z' && assigned[variable - 'a'];
}

void clearvars(void)
{
	int i;
	for(i = 0; i < 26; i++)
	{
		variables[i] = 0;
		assigned[i] = 0;
	}
}
