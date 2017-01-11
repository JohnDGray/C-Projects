typedef struct node{
	int data;
	struct node *next;
} Node;

Node* makeNode(int n)
{
	Node* np = (Node*)malloc(sizeof(Node));
	np -> data = n;
	np -> next = NULL;
	return np;
}
