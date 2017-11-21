#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#pragma warning (disable:4996)
#define KEY_SIZE	10						// Ž��Ű�� �ִ����  
#define TABLE_SIZE  13							// �ؽ� ���̺��� ũ��=�Ҽ� 

#define empty(e) (strlen(e.name)==0)
#define emptyid(e) (e.id==NULL)
#define equal(e1, e2) (!strcmp(e1.name,e2.name))
#define equalid(e1,e2) (e1.id == e2.id)

typedef struct {
	//char key[KEY_SIZE];
	char name[10];
	char city[15];
	char gender[2];
	int id;
} element;
element hash_table[TABLE_SIZE];					// �ؽ� ���̺� 
element hash_Idtable[TABLE_SIZE];

void init_table(element ht[]) {
	int i;
	for (i = 0; i<TABLE_SIZE; i++) {
		memset(&ht[i], NULL, sizeof(element));
	}
}
char * int_char(int input)
{
	char temp[20];
	itoa(input, temp, 6);
	return temp;
}
// ���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number = 0;
	while (*key) {      // ������ ���� ��� ��� �ڿ��� ���� 
		number = *key - 2;
		number += *key++;
	}
	return abs(number);
}
// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}
void hash_lp_add(element item, element ht[],int check)
{
	int i, hash_value;

	if (check == 0) // name
	{
		hash_value = i = hash_function(item.name);
		while (!empty(ht[i])) {
			if (equal(item, ht[i])) {
				fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
				return;
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "���̺��� ����á���ϴ�\n");
				return;
			}
		}
	}
	else //id
	{
		hash_value = i = hash_function(int_char(item.id));
		while (!emptyid(ht[i])) 
		{
			if (equalid(item, ht[i])) 
			{
				fprintf(stderr, "Ž��Ű�� �ߺ��Ǿ����ϴ�\n");
				
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) 
			{
				fprintf(stderr, "���̺��� ����á���ϴ�\n");
				return;
			}
		}
	}

	ht[i] = item;
}
// ����������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
int hash_lp_search(element item, element ht[],int check)
{
	int i, hash_value;
	if (check == 0)
	{
		hash_value = i = hash_function(item.name);
		while (!empty(ht[i]))
		{
			if (equal(item, ht[i])) {
				fprintf(stderr, "Ž������: ��ġ = %d\n", i);
				return i;
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "���̺� ��� Ž���Ϸ�\n");
				return 0;
			}
		}
	}
	else
	{
		hash_value = i = hash_function(int_char(item.id));
		while (!emptyid(ht[i])) 
		{
			if (equalid(item, ht[i])) 
			{
				fprintf(stderr, "Ž������: ��ġ = %d\n", i);
				return i;
				
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "���̺� ��� Ž�� �Ϸ�\n");
				return 0;
			}
		}
	}

}
// �ؽ� ���̺��� ������ ���
void hash_lp_print(element ht[])
{
	int i;
	for (i = 0; i < TABLE_SIZE; i++)
	{
		printf("[%d]	%s \n", i, ht[i].name);

	}
}
void detail_print(element ht[],int index)
{
	printf("�̸� : %s		ID : %d		�ּ� : %s		���� : %s\n", ht[index].name, ht[index].id, ht[index].city, ht[index].gender);
}
// �ؽ� ���̺��� ����� ���� 

int main(void)
{
	element tmp;
	element data[5];
	int op,res;
	init_table(hash_Idtable);
	init_table(hash_table);

	data[0].id = 200030;
	strcpy(data[0].city, "Daegu");
	strcpy(data[0].name, "Alice");
	strcpy(data[0].gender, "F");

	data[1].id = 200050;    
	strcpy(data[1].city, "Daegu");
	strcpy(data[1].name, "Bob");
	strcpy(data[1].gender, "M");

	data[2].id = 200063;
	strcpy(data[2].city, "Incheon");
	strcpy(data[2].name, "Bell");
	strcpy(data[2].gender, "M");

	data[3].id = 200067;
	strcpy(data[3].city, "Seoul");
	strcpy(data[3].name, "Charlie");
	strcpy(data[3].gender, "M");

	data[4].id = 200071;
	strcpy(data[4].city, "Seoul");
	strcpy(data[4].name, "Diana");
	strcpy(data[4].gender, "F");

	for (int i = 0; i < 5; i++)
	{
		hash_lp_add(data[i], hash_table, 0);
		hash_lp_add(data[i], hash_Idtable, 1);
	}
	hash_lp_print(hash_table);
	printf("=======================================\n");
	hash_lp_print(hash_Idtable);

	while (1)
	{
		printf("���ϴ� ������ �Է��Ͻÿ�(0=����, 1=id�˻�, 2=�̸��˻�)=");
		scanf("%d", &op);
		if (op == 1)
		{
			printf("id�� �Է��ϼ��� : ");
			scanf("%d", &tmp.id);
			res=hash_lp_search(tmp, hash_Idtable, 1);
			if (res == 0)
				printf("ã�� ���� �����ϴ�.\n");
			else
				detail_print(hash_Idtable, res);
			continue;
		}
		else if (op == 2)
		{
			printf("�̸��� �Է��ϼ��� : ");
			scanf("%s", &tmp.name);
			res=hash_lp_search(tmp, hash_table, 0);
			if(res == 0)
				printf("ã�� ���� �����ϴ�.\n");
			else
				detail_print(hash_table, res);
			continue;
		}
		else
			break;
		
	}

	return 0;
}
