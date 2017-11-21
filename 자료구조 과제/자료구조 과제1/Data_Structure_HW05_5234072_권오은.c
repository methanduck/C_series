#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct																//구조체 형식을 student로 정의합니다.
{
	char Name[6];
	int kor;
	int math;
	int eng;
	struct student *link;													//연결될 다음 구조체를 지정하는 포인터를 정ㅇ의합니다.

}student;

student *search(char name[6], student *head);								//해당 리스트의 주소를 찾습니다.
void create(student *head);													//리스트를 생성합니다.
void del(student *head);													//리스트를 삭제합니다.
void calc(student *head);													//리스트를 찾고 해당 리스트의 평균값을 구합니다.
void printall(student *head);												//저장된 모든 리스트 내용을 출력합니다.
void memfree(student *head);												//리스트 처음부터 끝까지 반환시키고 종료합니다.


int main()
{

	int input=0;															//메뉴선택을 위한 input변수를 0으로 초기화합니다.
	student head;															//헤드구조체를 선언합니다.
	memset(&head, NULL, sizeof(student));									//NULL로 구조체를 초기화합니다.
	
		while (1)															//메뉴를 반복적으로 선택하기 위한 반복문입니다.
		{
			printf(" 1.insert a student\n 2.delete a student\n 3.calculate average\n 4.print all student\n 5.exit\n");
			printf(">> ");
			scanf("%d", &input);											
			printf("**********************\n");
			switch (input)													
			{
			case 1:															
                create(&head);												//생성함수 호출
				continue;													
			case 2:
				del(&head);													//삭제함수 호출
				continue;													
			case 3:
				calc(&head);												//평균계산 함수 호출
				continue;													
			case 4:
				printall(&head);											//전체출력 함수 호출
				continue;													
			case 5:
				memfree(&head);												//모두 반환하는 함수 호출
				break;														
			default:
				puts("check your input number");							//지정된 숫자 이외의 것을 입력하였을 경우
			}
			break;															
		}
		return 0;		
}

student *search(char name[6],student *head)									//해당 리스트를 검색하는 함수입니다. 주소값을 반환합니다.
{
	student *temp;															//구조체를 찾기위해 값이 바뀌며 찾는 포인터를 선언합니다.
	temp = head;															//헤드구조체부터 시작
	if(temp==NULL)															//헤드구조체가 다음 첫 노드를 가리키지 않는다면
	{
		printf("자료가 저장되어 있지 않습니다!");							//자료가 없는것으로 판단
	}
	else
	{
		temp=head->link;													//첫노드의 주소를 포인터에 대입합니다.
		while(temp!=NULL)													//리스트의 끝까지 반복하며
		{
			if (strcmp(name, temp->Name) == 0)								//함수의 인자로 받은 name[6]과 해당 리스트의 이름을 비교합니다.
			{
				return temp;												//일치할때의 해당 리스트 주소를 받고
				break;														//반복문을 중단합니다.
			}
			else
				temp = temp->link;											//찾지 못하였으므로 다음 리스트를 탐색합니다.
		}
		
		return NULL;														//리스트내 찾는 이름이 없을경우 NULL을 반환합니다.
	}

}

void create(student *head)													//리스트 생성 함수입니다.		
{
	student *temp=NULL;														//1.첫 노드를 생성할때 사용 2. 다음링크가 비어있는 리스트를 찾는 용도
	student *n=NULL;														//리스트 할당을 위해 사용

	if(head->link==NULL)													//첫 노드 생성시에 
	{
		temp=(student *)malloc(sizeof(student));							//동적할당
		head->link=temp;													//헤드포인터에 첫 노드주소를 넣습니다.
		temp->link = NULL;													//첫노드의 링크는 NULL로 초기화합니다.

			printf("Name :");												//자료를 입력받습니다.
			scanf("%s", &temp->Name);
		printf("korean :");
		scanf("%d", &temp->kor);
		printf("math :");
		scanf("%d", &temp->math);
		printf("english :");
		scanf("%d", &temp->eng);
	}
	else																	//첫노드가 아닐경우
	{
		temp=head->link;													//temp에 첫노드의 링크를 넣습니다.
		while(1)															//무한
		{
			if (temp->link == NULL)											//다음 노드가 존재하지 않을때
				break;														//반복문을 종료하거나
			else
				temp = temp->link;										//다음 리스트를 탐색합니다.
		}
			n=(student *)malloc(sizeof(student));							//새로운 리스트를 할당하고
			temp->link=n;													//링크가 비어있는 구조체에 현재 리스트의 주소를 넣습니다.
			n->link = NULL;													//새 리스트의 링크는 초기화합니다.

			printf("Name :");												//자료를 입력받습니다.
			scanf("%s",&n->Name);
			printf("korean :");
			scanf("%d",&n->kor);
			printf("math :");
			scanf("%d",&n->math);
			printf("english :");
			scanf("%d",&n->eng);		
	}


}

void del(student *head)														//삭제함수입니다.
{
	student *searchres=NULL;												//탐색함수를 호출한 뒤 결과주소를 받는 포인터입니다.
	student *temp=NULL;														//삭제할 리스트 바로 앞의 리스트주소를 저장할 포인터입니다.
	char name[6];															//찾을 이름을 입력받을 변수입니다.
	printf("Enter the name of student :");
	scanf("%s",&name);

	searchres = search(name, head);											//탐색함수를 호출하여 해당 리스트 주소를 받습니다.

	temp=head->link;														//첫 노드주소를 temp에 넣습니다.
	while(temp!=NULL)														//리스트 끝까지 반복
	{
		if (temp->link == searchres)										//다음 리스트 주소가 searchres값인 리스트라면
		{
			temp->link = searchres->link;									//삭제할 이전의 리스트 링크에 삭제할 다음리스트 링크를 묶어줍니다.
			break;															//반복문 중단
		}
		temp=temp->link;													//다음 리스트로 가기위한 작업
	}
	
	free(searchres);														//삭제할 리스트를 반환합니다.
}

void calc(student *head)													//평균계산 함수입니다.
{
	char inname[6];															//검색할 이름을 받을 문자열입니다.
	float res,k,m,e=0;														//해당하는 학생의 평균을 구하기 위한 변수입니다.
	student *temp;															//탐색함수 호출후 주소를 받기위한 포인터입니다.

	printf("Enter the student name:");
	scanf("%s",&inname);
	temp=search(inname,head);												//탐색후 temp에 해당 리스트 주소를 대입합니다.
	if (temp == NULL)														//탐색후 해당 결과를 찾지 못하였을경우
	{
		printf("Not Found\n");
		printf("------------------\n");
	}
	else																	//해당하는 리스트 점수 평균을 구하여 출력합니다.
	{
		k = temp->kor;
		m = temp->math;
		e = temp->eng;
		res = k + m + e;
		res /= 3;
		printf("%s's average is %.3f\n", inname, res);
		printf("------------------\n");
	}
}

void printall(student *head)												//저장된 모든 리스트를 출력하는 함수입니다.
{
	student *temp;															//탐색하기 위해 사용될 포인터입니다.

	if(head->link == NULL)													//첫노드가 존재하지 않는경우
	{
	printf("출력할 자료가 없습니다.\n");
	printf("**********************\n");
	}
	else															
	{
		temp=head->link;													//첫노드 주소를 temp에 대입합니다.
		while(temp!=NULL)													//노드 끝까지 탐색합니다.
		{
			printf("Name  :  %s\n",temp->Name);								//값 출력
			printf("Kor   :  %d\n",temp->kor);
			printf("Math  :  %d\n",temp->math);
			printf("Eng   :  %d\n",temp->eng);
			printf("------------------\n");
			temp=temp->link;												//다음 리스트 주소를 대입합니다.
		}
	}
}

void memfree(student *head)													//모든 리스트를 운영체제에 반환하는 함수입니다.
{
	student *temp1;															//지워질 리스트의 주소를 받을 포인터입니다.
	student *temp2;															//지워질 리스트의 다음 리스트 주소를 받을 포인터 입니다.
	if (head->link == NULL)													//노드가 없는 상태라면
		free(head);
	else
	{
		temp1 = head;														//헤드를 temp1에 넣고
		temp2 = head->link;													//첫노드의 주소에 해당하는 head->link값을 temp2에 넣습니다.
		while (temp2->link != NULL)											//다음 리스트가 없을때까지
		{
			
			temp1 = temp2;													//첫번째 노드주소를 가집니다.
			temp2 = temp1->link;											//두번째 노드주소를 가집니다.
			free(temp1);													//첫노드를 반환합니다.
		}
	}
}




