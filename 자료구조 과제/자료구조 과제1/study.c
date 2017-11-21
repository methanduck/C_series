#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
	int data;
	test *link;
}test;
int top = -1;

void push();
void pop(test *input);
void isfull(test *input);
void isempty();


int main()
{
	
}

void push(test *input)
{
	test* temp;
	int input;
	if (isfull(input))
	{
		printf("full", stderr);
	}
	else if(top==-1)
	{
		temp = (test *)malloc(sizeof(test));
		scanf("%d", &input);
		temp->data = input;
		head->link = temp;
		top++;
	}
	else
}

void pop(test *input)
{
	if (isempty(input))
		printf("empty", stderr);
	else
	{
	return 
	}
}
