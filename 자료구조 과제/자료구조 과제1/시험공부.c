#include<stdio.h>

void hanoitower(int n, char from, char tmp, char to);
int main()
{
	int input1;
	scanf("%d", &input1);
	hanoitower(input1, 'a', 'b', 'c');
}
void hanoitower(int n, char from, char tmp, char to)
{
	if (n == 1)
		printf("1���� %c���� %c�� �ű��\n", from, to);
	else
	{
		hanoitower(n - 1, from, to, tmp);
		printf("%d���� %c���� %c�� �ű��\n", n, from, to);
		hanoitower(n - 1, tmp, from, to);
	}
}
