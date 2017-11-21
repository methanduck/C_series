#include<stdio.h>
#include<stdlib.h>
int count = -1;
void push(int *stack);
int pop(int stack[10]);
void convert(int stack[10],int num);

int main()
{
	int stack[10];
	int input, input2;
	int (*pstack)[10] = stack;
	while (1)
	{
		printf("1. Insert a decimal number\n2. Convert\n3. Exit\n");
		printf(">>");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			push(pstack);
			continue;
		case 2:
		{
			printf("Enter the number system(max: 16)");
			scanf("%d", &input2);
			convert(stack, input2);
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

void push(int *stack)
{
	int input;
	if (count >9 )
	{
		printf("더이상 입력할 수 없습니다!");
	}
	else
	{
		printf("Decimal number :");
		scanf("%d", &input);
		stack[count++] = input;
	}

}

int pop(int stack[10])
{
	if (count<0 )
		return -1;
	else
		printf("%d", stack[count]);
	count--;
}

void convert(int stack[10],int num)
{
	int temp,res=0;
	temp = pop(count, stack);
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
		convert(stack,res);
	}
}
