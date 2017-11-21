#include <stdio.h>

int comb(int n, int k);								//���װ�� �Լ��� �����մϴ�.
int fact(int x, int y);								//���丮�� �Լ��� �����մϴ�. X�� ���� ���̰� Y�� ���� Ƚ���Դϴ�.

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
int comb(int n, int k)
{
	int res;										//�����
	if ((k == 0) || (n == k))						//nCk���� k=0�̰ų� n==k�̸� 1�̹Ƿ�
		return 1;									//1�� ��ȯ�մϴ�.
	else
		return fact(n, k) / fact(k, k);				/*nCk�� n!/(n-k)!*k!�ε� ���⼭ n!�� (n-k)!�� ��е� ��� n�� kȽ����ŭ
													���丮���� �ݺ��ϰ� �ǹǷ� fact(n,k)�� ���ڷ� �и�� (n-k)!�� ��еǹǷ� k!�� ����
													fact(k,k)�� ȣ���ϰ� �˴ϴ�.*/
}
int fact(int x, int y)								//���� �� X�� ���Ƚ�� Y�Դϴ�. ex)fact(4,2) == 4*3
{
	if (y == 0)										//Y���� 0�ϰ�� 
		return 1;									//1�� ����Ͽ� ������ ���丮���� �ϼ��մϴ�.
	else
		return x*fact(x - 1, y - 1);				//���� ���ҽ��� �Լ��� ��ȣ�� �մϴ�.
}