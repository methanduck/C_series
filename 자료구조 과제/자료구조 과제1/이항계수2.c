#include <stdio.h>

int comb(int input1, int input2);					//�Է°� �ΰ��� ������ ���װ�� �Լ��� �����մϴ�.
int comb(int input1, int input2)
{
	if ((input1 == input2) || (input2 == 0))		//k=0 or k=n �� �ش��ϸ� 
		return 1;									//1�� ��ȯ�մϴ�.
	else if (0 < (input2 < input1))					//n��k�� ����̸� k�� n���� ������ �Ǵ��մϴ�.
		return comb(input1 - 1, input2 - 1) + comb(input1 - 1, input2);//�Ľ�Į�� �ﰢ�� ���¸� �����մϴ�.
}
int main()
{

	int input1, input2;

	while (1)										//���ѹݺ�
	{
		printf("Enter the value of n:");
		scanf("%d", &input1);						//ù��° �Է°�
		printf("Enter the value of k:");
		scanf("%d", &input2);						//�ι�° �Է°�

		printf("Result = %d\n", comb(input1, input2));//���װ�� �Լ� ȣ�� ����� ����մϴ�.
		printf("---------------------\n");
	}
}

