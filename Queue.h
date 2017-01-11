#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	QueueData data;
	struct node *next;
} Node;

typedef struct queue
{
	Node* head;
	Node* tail;
} Queue;

Queue* initQueue()
{
	Queue* qp = (Queue*)malloc(sizeof(Queue));
	qp -> head = NULL;
	qp -> tail = NULL;
	return qp;
}

int empty(Queue* Q)
{
	return (Q -> head == NULL);
}

void enqueue(Queue* Q, QueueData d)
{
	Node* np = (Node*)malloc(sizeof(Node*));
	np -> data = d;
	np -> next = NULL;
	if (empty(Q))
	{
		Q -> head = np;
		Q -> tail = np;
	}
	else
	{
		Q -> tail -> next = np;
		Q -> tail = np;
	}
}

QueueData dequeue(Queue* Q)
{
	if(empty(Q))
	{
		printf("\nAttempt to remove from an empty queue\n.");
		exit(1);
	}
	QueueData hold = Q -> head -> data;
	Node* temp = Q -> head;
	Q -> head = Q -> head -> next;
	if(Q -> head == NULL)
	{
		Q -> tail = NULL;
	}
	free(temp);
	return hold;
}
