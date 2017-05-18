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
	int type;
	double op2;
	char s[MAXOP];
	char myvar;

	while((type = getop(s)) != EOF)
	{
		switch(type)
		{
			case VARIABLE:
				myvar = s[0];
				if(isassigned(myvar))
				{
					push(getvar(myvar));
				}
				else
				{
					if(empty())
					{
						printf("error: cannot assign to variable without value.\n");
						break;
					}
					assign(myvar, pop());
				}
				break;
			case NUMBER:
				push(atof(s));
				break;
			case COMMAND:
				if(strcmp(s, "sin") == 0)
				{
					push(sin(pop()));
				}
				else if(strcmp(s, "cos") == 0)
				{
					push(cos(pop()));
				}
				else if(strcmp(s, "exp") == 0)
				{
					push(exp(pop()));
				}
				else if(strcmp(s, "pow") == 0)
				{
					op2 = pop();
					if(op2 == 0 && peek() == 0)
					{
						printf("error: cannot compute 0^0\n");
					}
					else
					{
						push(pow(pop(), op2));
					}
				}
				else
				{
					printf("error: unknown command\n");
				}
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0)
				{
					push(pop() / op2);
				}
				else
				{
					printf("error: zero divisor\n");
				}
				break;
			case '%':
				op2 = pop();
				if(op2 != 0)
				{
					push(((int)pop()) % ((int)op2));
				}
				else
				{
					printf("error: zero modulus\n");
				}
				break;
			case '!':
				clearvars();
				printf("variables cleared.\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
		}
	}
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
