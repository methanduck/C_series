#include <stdio.h>

int main()
{
	int i,input1,input2,res,calc;

	scanf("%d", &input1);
	scanf("%d", &input2);
	
	if (input1 > input2)
	{
		while(1)
		{
			calc = input1%input2;
			input1 = input2;
			input2 = calc;
			if (calc == 0)
				break;
		}
		printf("%d", input1);
	}
	else
	{
		while (1)
		{
			calc = input2%input1;
			input2 = input1;
			input1 = calc;
			if (calc == 0)
				break;

		}				printf("%d", input2);

	}
}