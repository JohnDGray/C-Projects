#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char[]);
void push(double);
double pop(void);
double peek(void); 
void duplicate(void);
void swap(void);

main()
{
	push(3);
	push(2);
	push(1);
	printf("1 = %f\n", peek());
	printf("1 = %f\n", peek());
	duplicate();
	printf("1 = %f\n", pop());
	printf("1 = %f\n", peek());
	swap();
	printf("2 = %f\n", peek());
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

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

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");
	}
	else
	{
		buf[bufp++] = c;
	}
}
































































































