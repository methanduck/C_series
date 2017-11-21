#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
	char dat[50];
};

void add(struct data *tree);
void preorder(int n,char *tree);
void inorder(int n, char *tree);
void postorder(int n, char *tree);
int main()
{
	struct data tree[1000] = { '\0' , };
	int option,i;
	char input[10];
	

	while (1)															
	{
		printf(" 1.Generate tree\n 2.Print preorder\n 3.Print inorder\n 4.Print postorder\n ");
		printf(">> ");
		scanf("%d", &option);

		printf("**********************\n");
		switch (option)
		{
		case 1:

			add(tree);
			continue;
		case 2:
			preorder(1, tree);
			continue;
		case 3:
			inorder(1, tree);
			continue;
		case 4:
			postorder(1, tree);
			continue;
		default:
			puts("check your input number");						
		}
		break;
	}
}

void add(struct data *tree)
{
	char tmp[10];
	char input[10];
	int itmp = 0;
	char tmp2;

	printf("Enter the file name:");
	scanf("%s", input);

	FILE *load = fopen(input, "r");;
	if (load == NULL)
	{
		printf("file error");
	}
	else
	{

		fscanf(load, "%s", input);
		strcpy((tree+1)->dat, input);
		while (!feof(load))
		{
			
			itmp = 0;
			if (fscanf(load, "%s %c %d", &tmp, &tmp2, &itmp) == EOF)
				break;
			
			if (tmp2 == 'L')
			{
				strcpy((tree+(itmp*2))->dat,tmp);
			}
			else
			{
				strcpy((tree+((itmp * 2) + 1))->dat, tmp);
			}

		}

	}
}

void inorder(int n, struct data *tree)
{
	if (strcmp((tree + n)->dat, "\0") != 0)
	{

		inorder((2 * n), tree);	
		printf("%2s", (tree + n)->dat);
		inorder((2 * n) + 1, tree);

	}
}


void postorder(int n, struct data *tree)
{
	if (strcmp((tree + n)->dat, "\0") != 0)
	{
		
		postorder((2 * n), tree);
		postorder((2 * n) + 1, tree);
		printf("%2s", (tree + n)->dat);
	}
}

void preorder(int n,struct data *tree)
{
	if (strcmp((tree+n)->dat ,"\0")!=0)
	{
		printf("%2s", (tree+n)->dat);
		preorder((2 * n), tree);
		preorder((2 * n)+1,tree);
	}
}


