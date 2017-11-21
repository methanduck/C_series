#include <stdio.h>						

int main()
{
	int matrix[15][15] = {0};							//마방진이 입력받을 수 있는 최대 값을 지정합니다.
	int size=0, i, j,x,y;									//size : 입력받을 마방진의 크기 i,j : 반복문에 사용될 변수 x : x좌표 y : y좌표
	while (1)
	{

		/*do												//
		{
			printf("enter the size of magic square : ");
			scanf("%d", &size);								//마방진의 크기를 입력받습니다.
		} while (size % 2 == 0);*/

		while (size % 2 == 0)
		{
			printf("enter :");
			scanf("%d", &size);
		}

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				matrix[i][j] = 0;							//마방진을 0으로 초기화 하여 추후에 내부 값이 저장된 여부를 판단합니다.
			}
		}

		x = 0; y = size / 2;								//초기 1이 배치될 시작 지점을 지정합니다. 
		for (i = 1; i <= size*size; i++)					//마방진의 크기만큼 반복합니다.
		{
			matrix[x][y] = i;								//반복문의 증가값에 따라 배열에 값을 추가합니다.
			x -= 1; y += 1;									//기본 이동형태로 우측상위대각선 방향의 규칙을 지정합니다.

			if ((x < 0) && (y >= size))							//(0,size)위치일 경우 
			{
				x = x + 2; y--;								//계산되었던 값에서 바로 아래위치의 좌표로 정해줍니다.
			}
			else if (x < 0)									//마방진의 위쪽 범위로 벗어날 경우
				x = size - 1;								//제일 하단으로 이동합니다.
			else if (y >= size)								//마방진의 오른쪽 범위로 벗어날 경우
				y = 0;										//제일 좌측으로 이동합니다.
			else if (matrix[x][y] != 0)						//이동하려는 다음 좌표 배열에 초기화되었던 값 0 이 아닐경우
			{
				x = x + 2; y--;								//바로 아래 좌표로 정해줍니다.
			}
		}
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
				printf(" %4d", matrix[i][j]);				//각 숫자마다의 여유를 위해 %4d를 이용하여 반복문에 맞게 표현합니다.

			printf("  \n");									//한개 행으로 정의될 수 있는 배열이 표시되면 한칸 아래에 내립니다
		}

		printf("\n\n");
	}


}