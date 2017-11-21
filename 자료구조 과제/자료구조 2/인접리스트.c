#include<stdio.h>

#define MAX 50

typedef struct node
{
	int vertex;
	struct node * link;
}node;

typedef struct type
{
	int n;
	node * adjlist[MAX];
}type;

void inset(type *input, int v)
{
	if ((input->n)++ > MAX)
	{
		fprintf(err)
	}
	(input->n)++;
}