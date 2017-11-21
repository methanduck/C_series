#include <stdio.h>

int comb(int n, int k);								//이항계수 함수를 정의합니다.
int fact(int x, int y);								//팩토리얼 함수를 정의합니다. X는 계산될 값이고 Y는 계산될 횟수입니다.

int main()
{

	int input1, input2;

	while (1)										//무한반복
	{
		printf("Enter the value of n:");
		scanf("%d", &input1);						//첫번째 입력값
		printf("Enter the value of k:");
		scanf("%d", &input2);						//두번째 입력값

		printf("Result = %d\n", comb(input1, input2));//이항계수 함수 호출 결과를 출력합니다.
		printf("---------------------\n");
	}
}
int comb(int n, int k)
{
	int res;										//결과값
	if ((k == 0) || (n == k))						//nCk에서 k=0이거나 n==k이면 1이므로
		return 1;									//1을 반환합니다.
	else
		return fact(n, k) / fact(k, k);				/*nCk는 n!/(n-k)!*k!인데 여기서 n!는 (n-k)!로 약분될 경우 n은 k횟수만큼
													팩토리얼을 반복하게 되므로 fact(n,k)가 분자로 분모는 (n-k)!이 약분되므로 k!만 남아
													fact(k,k)를 호출하게 됩니다.*/
}
int fact(int x, int y)								//계산될 값 X와 계산횟수 Y입니다. ex)fact(4,2) == 4*3
{
	if (y == 0)										//Y값이 0일경우 
		return 1;									//1을 출력하여 마지막 팩토리얼을 완성합니다.
	else
		return x*fact(x - 1, y - 1);				//값을 감소시켜 함수를 재호출 합니다.
}