#include <stdio.h>

int main()
{
	char input[30];											
	int check[26][2] = { 0 };								
	int i, j, ch1, ch2, m;
	ch1 = 65;												
	ch2 = 97;												
	
	
	printf("Enter the sentence:");
	gets(input);
		
	for (i = 0; i<26; i++)									
	{
		check[i][0] = ch2;									
		
		for (j = 0; j<30; j++)								
		{
			if ((input[j] == ch1) || (input[j] == ch2))		
			{
				check[i][1]++;								
			}	
		}
		ch1++;												
		ch2++;
	}

	for (m = 0; m<26; m++)									
	{
		if (check[m][1] != 0)								
			printf(">> %c: %d\n", check[m][0], check[m][1]);
	}
}
