#include<stdio.h>
#include<string.h>
#define _CRT_SECURE_NO_WARNINGS
#define KEY_SIZE	10						// Ž��Ű�� �ִ����  
#define TABLE_SIZE  13							// �ؽ� ���̺��� ũ��=�Ҽ� 

#define empty(e) (strlen(e.key)==0)
#define equal(e1, e2) (!strcmp(e1.key,e2.key))

typedef struct {
	char key[KEY_SIZE];
												// �ٸ� �ʿ��� �ʵ���� ���⿡ �ִ´�. 
} element;
element hash_table[TABLE_SIZE];					// �ؽ� ���̺� 

void init_table(element ht[]) {
	int i;
	for (i = 0; i<TABLE_SIZE; i++) {
		ht[i].key[0] = 0;
	}
}
// ���ڷ� �� Ž��Ű�� ���ڷ� ��ȯ
int transform(char *key)
{
	int number = 0;
	while (*key) {      // ������ ���� ��� ��� �ڿ��� ���� 
		printf("%d\n", *key);
		number += *key++;
	}
	return number;
}
															// ���� �Լ��� ����� �ؽ� �Լ�
int hash_function(char *key)
{
	return transform(key) % TABLE_SIZE;
}  
void hash_lp_add(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
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
	ht[i] = item;
}
// ����������� �̿��Ͽ� ���̺� ����� Ű�� Ž��
void hash_lp_search(element item, element ht[])
{
	int i, hash_value;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "Ž������: ��ġ = %d\n", i);
			return;
		}
		i = (i + 1) % TABLE_SIZE;
		if (i == hash_value) {
			fprintf(stderr, "ã�� ���� ���̺� ����\n");
			return;
		}
	}
	fprintf(stderr, "ã�� ���� ���̺� ����\n");
}
// �ؽ� ���̺��� ������ ���
void hash_lp_print(element ht[])
{
	int i;
	for (i = 0; i<TABLE_SIZE; i++)
		printf("[%d]	%s\n", i, ht[i].key);
}
// �ؽ� ���̺��� ����� ���� 
int main(void)
{
	element tmp;
	int op;
	while (1) {
		printf("���ϴ� ������ �Է��Ͻÿ�(0=�Է�, 1=Ž��, 2=����)=");
		scanf("%d", &op);
		if (op == 2) break;
		printf("Ű�� �Է��Ͻÿ�=");
		scanf("%s", tmp.key);
		if (op == 0)
			hash_lp_add(tmp, hash_table);
		else if (op == 1)
			hash_lp_search(tmp, hash_table);
		hash_lp_print(hash_table);
	}
	return 0;
}
