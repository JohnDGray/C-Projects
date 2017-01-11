#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	StackData data;
	struct node *next;
} Node;

typedef struct stack
{
	Node* top;
} Stack;

Stack* initStack()
{
	Stack* sp = (Stack*)malloc(sizeof(Stack));
	sp -> top = NULL;
	return sp;
}

int empty(Stack* S)
{
	return (S -> top == NULL);
}

void push(Stack* S, StackData n)
{
	Node* np = (Node*)malloc(sizeof(Node));
	np -> data = n;
	np -> next = S -> top;
	S -> top = np;
}

StackData pop(Stack* S)
{
	if (empty(S))
	{
		printf("\nAttempt to pop an empty stack.\n");
		exit(1);
	}
	StackData hold = S -> top -> data;
	Node* temp = S -> top;
	S -> top = S -> top -> next;
	free(temp);
	return hold;
}

StackData peek(Stack* S)
{
	if(empty(S))
	{
		printf("\nAttempt to peek at an empty stack.\n");
		exit(1);
	}
	return S -> top -> data;
}
