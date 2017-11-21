#include <stdio.h>

int func(int input1, int input2);						//최대공약수 함수를 정의합니다.기본 input1이 input2보다 크다는 전제하에 코딩했습니다.

int func(int input1, int input2)						//정수로 된 두 입력을 받습니다.
{
	if (input1<input2)									//input1이 input2보다 작다면 
		func(input2, input1);							//서로의 자리를 바꿔준뒤 최대공약수 함수를 호출합니다.
	else if (input2 == 0)								//나머지가 0이 나왔을 시
		return input1;									//마지막 나눈 수를 출력합니다.
	else
		func(input2, input1%input2);					//나머지가 0이 나올때까지 연산을 위해 함수를 호출합니다.
}

int main()
{
	int input1, input2;									//변수선언

	while (1)											//무한반복
	{
		printf("Enter the value of a:");
		scanf("%d", &input1);							//첫번째 입력값
		printf("Enter the value of b:");
		scanf("%d", &input2);							//두번째 입력값

		printf("GCD = %d\n", func(input1, input2));		//함수 호출결과를 출력합니다.
		printf("---------------------\n");
	}
}
