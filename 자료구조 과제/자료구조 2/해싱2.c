#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#pragma warning (disable:4996)
#define KEY_SIZE	10						// 탐색키의 최대길이  
#define TABLE_SIZE  13							// 해싱 테이블의 크기=소수 

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
element hash_table[TABLE_SIZE];					// 해싱 테이블 
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
// 문자로 된 탐색키를 숫자로 변환
int transform(char *key)
{
	int number = 0;
	while (*key) {      // 간단한 덧셈 방식 사용 자연수 생성 
		number = *key - 2;
		number += *key++;
	}
	return abs(number);
}
// 제산 함수를 사용한 해싱 함수
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
				fprintf(stderr, "탐색키가 중복되었습니다\n");
				return;
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "테이블이 가득찼습니다\n");
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
				fprintf(stderr, "탐색키가 중복되었습니다\n");
				
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) 
			{
				fprintf(stderr, "테이블이 가득찼습니다\n");
				return;
			}
		}
	}

	ht[i] = item;
}
// 선형조사법을 이용하여 테이블에 저장된 키를 탐색
int hash_lp_search(element item, element ht[],int check)
{
	int i, hash_value;
	if (check == 0)
	{
		hash_value = i = hash_function(item.name);
		while (!empty(ht[i]))
		{
			if (equal(item, ht[i])) {
				fprintf(stderr, "탐색성공: 위치 = %d\n", i);
				return i;
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "테이블 모두 탐색완료\n");
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
				fprintf(stderr, "탐색성공: 위치 = %d\n", i);
				return i;
				
			}
			i = (i + 1) % TABLE_SIZE;
			if (i == hash_value) {
				fprintf(stderr, "테이블 모두 탐색 완료\n");
				return 0;
			}
		}
	}

}
// 해싱 테이블의 내용을 출력
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
	printf("이름 : %s		ID : %d		주소 : %s		성별 : %s\n", ht[index].name, ht[index].id, ht[index].city, ht[index].gender);
}
// 해싱 테이블을 사용한 예제 

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
		printf("원하는 연산을 입력하시오(0=종료, 1=id검색, 2=이름검색)=");
		scanf("%d", &op);
		if (op == 1)
		{
			printf("id를 입력하세요 : ");
			scanf("%d", &tmp.id);
			res=hash_lp_search(tmp, hash_Idtable, 1);
			if (res == 0)
				printf("찾는 값이 없습니다.\n");
			else
				detail_print(hash_Idtable, res);
			continue;
		}
		else if (op == 2)
		{
			printf("이름을 입력하세요 : ");
			scanf("%s", &tmp.name);
			res=hash_lp_search(tmp, hash_table, 0);
			if(res == 0)
				printf("찾는 값이 없습니다.\n");
			else
				detail_print(hash_table, res);
			continue;
		}
		else
			break;
		
	}

	return 0;
}
