﻿#include <stdio.h>

void main()
{
	int magic[19][19] = { 0, };
	int i, j, ix, iy, x, y;
	int count = 1, length, again;

	printf("\t-----------------------------------\n");
	printf("\t--  마  방  진   (Magic Square)  --\n");
	printf("\t-----------------------------------\n\n");

	while (1)
	{
		do
		{
			printf("\n\t만들기 원하는 마방진의 길이를 입력하세요.\n");
			printf("\t(홀수만, 19이하) -> ");
			scanf("%d", &length);
		} while (length % 2 == 0 || length < 0 || length > 19);

		printf("\n");

		x = length / 2, y = 0;
		count = 1;

		for (i = 0; i<length; i++)
			for (j = 0; j<length; j++)
				magic[i][j] = 0;

		for (i = 0; i<length*length; i++)
		{
			magic[x][y] = count;

			ix = x, iy = y;
			x++, y--;

			if (x > length - 1) 
				x = 0;
			if (y < 0) 
				y = length - 1;

			if (magic[x][y] != 0)
			{
				x = ix, y = iy + 1;
			}

			count++;
		}

		for (i = 0; i<length; i++)
		{
			for (j = 0; j<length; j++)
				printf(" %3d", magic[j][i]);

			printf("\n");
		}

		do
		{
			printf("\n\t다시 하시겠습니까? (YES : 1, No : 2> ");
			scanf("%d", &again);
		} while (again != 1 && again != 2);

		if (again == 2)
			break;
	}
}
