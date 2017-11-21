#include <stdio.h>

int comb(int input1, int input2);					//입력값 두개를 가지는 이항계수 함수를 정의합니다.
int comb(int input1, int input2)
{
	if ((input1 == input2) || (input2 == 0))		//k=0 or k=n 에 해당하면 
		return 1;									//1을 반환합니다.
	else if (0 < (input2 < input1))					//n과k는 양수이며 k가 n보다 작은지 판단합니다.
		return comb(input1 - 1, input2 - 1) + comb(input1 - 1, input2);//파스칼의 삼각형 형태를 구현합니다.
}
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

