#include<stdio.h>
#include<stdlib.h>

#define max  10
typedef struct
{
	int stack[max];
	int top;
} conv;

void init(conv *stk);
void is_empty(conv *stk);
void is_full(conv *stk);
void push(conv *stk);
void pop(conv *stk);
void convert(conv *stk);

int main()
{
	int input;
	conv stk;
	while (1)
	{
		printf("1. Insert a decimal number\n2. Convert\n3. Exit\n");
		printf(">>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			push(&stk);
			continue;
		case 2:
		{
			convert(&stk);
			continue;
		}
		case 3:
			break;

		default:
			printf("please check your input num!");
			break;
		}
		break;
	}
	return 0;
}

void init(conv *stk)
{
	stk->top = -1;
}

void is_empty(conv *stk)
{
	return (stk->top == -1);
}

void is_full(conv *stk)
{
	return (stk->top == (max - 1));
}

void push(conv *stk)
{
	int input;
	if (isfull(stk))
	{
		printf("더이상 자료를 입력할 수 없습니다!");
	}
	else
	{
		printf("자료를 입력하세요 : ");
		scanf("%d", &input);
		stk->stack[++(stk->top)] = input;
	}
}

void pop(conv *stk)
{
	if (is_empty(stk))
		printf("자료가 없습니다!");
	else
		return stk->stack[(stk->top)--];		
}


void convert(conv *stk)
{
	int input,temp,res=0;
	printf("Enter the number system(MAX:16) :");
	scanf("%d", &input);



	if (temp < 0)
	{
		printf("자료가 없습니다!");
	}
	else if (temp == 1)
	{
		printf("1");
	}
	else if (temp == 0)
		printf("0");
	else
	{
		res = temp%num;
		printf("%d", res);
		convert(stack, res);
	}
}
