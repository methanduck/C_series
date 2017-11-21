#include<stdio.h>
#include<string.h>															//strcmp함수를 활용하기 위해 넣었습니다.
#include<stdlib.h>															//동적메모리할당을 위해 넣었습니다.
struct score 
{
	char name[10];															//학생의 이름
	int kor;																//check상위까지 성적변수
	int math;
	int eng;
	int check;																//해당 구조체가 초기화가 되어있음을 구별하기 위해 넣었습니다.
};
int search(struct score *stu,char name[10],int num);						//몇번째 구조체인지 식별하기 위한 함수입니다. 하위포함 함수설명은 함수내에 설명해 두었습니다.
void insert(struct score *stu,int num);										//삽입을 위한 함수입니다.
void del(struct score *stu,int num,int *count);								//삭제를 위한 함수입니다.
void calc(struct score *stu, int num);										//평균값 계산을 위한 함수입니다.
void print(struct score *stu,int num);										//초기화된 구조체의 전체 값을 출력하기 위한 함수입니다.

int main()
{
	int num,input,count=0;													//num:할당할 구조체 개수, input:삽입,삭제 등 메뉴선택을 입력받기 위함, count: 초기 학생 구조체 수를 확인하기 위함

	printf("Enter the number of students: ");
	scanf("%d", &num);														//구조체 개수를 입력받습니다.
	struct score *stu= (struct score *)malloc(sizeof(struct score)*num);	//갯수만큼 score형태의 구조체를 동적할당 받습니다.
	
	if (stu == NULL)														//할당받지 못해 해당 포인터가 NULL값일경우
	{	
		puts("동적할당에 실패했습니다.");									//출력
	}
	else
		
		printf("%d students can be stored.\n", num);						//할당받을 경우 출력
		puts("Program Start!");
		printf("\n--------------------------\n");
		while (1)															//계속 메뉴를 선택하기 위한 반복
		{
			printf(" 1.insert a student\n 2.delete a student\n 3.calculate average\n 4.print all student\n 5.exit\n");//메뉴출력
			printf("선택해 주세요:");
			scanf("%d", &input);											//input에 원하는 메뉴를 선택받음
			printf("**********************\n");
			switch (input)													//input값에 따라
			{
			case 1:															//1: insert
				if (count < num)											//count변수를 통해 초기에 동적할당시 확인했던 수를 체크합니다.
				{
					insert(stu,num);										//insert함수를 통해 값을 입력합니다.
					count++;												//매 입력시 마다 count변수를 증가시킵니다.
				}
				else
				{
					printf("입력하신 학생 수 보다 많습니다\n");				//이외의 경우는 입력을 받지않고 경고후
					printf("\n--------------------------\n");
				}
				continue;													//메뉴선택으로 돌아갑니다.
			case 2:
				del(stu,num,&count);										//삭제함수호출
				continue;													//완료후 메뉴로 돌아갑니다.
			case 3:
				calc(stu,num);												//평균계산함수 호출
				continue;													//완료후 메뉴로 돌아갑니다.
			case 4:
				print(stu,num);												//초기화된 구조체 전체 내용 출력
				continue;													//완료후 메뉴로 돌아갑니다.
			case 5:
				free(stu);													//5번은 종료호출로 free함수를 통해 동적 할당 받았던 stu포인터를 인자로 운영체제에 반환합니다.
				break;														//종료를 하기 위해 스위치 구문을 나갑니다.
			default:
				puts("범위내의 올바른 숫자를 입력해 주세요");				//1~5를 제외한 선택시 경고
			}
			break;															//스위치가 나온경우 반복문 탈출을 위한 break;
		}
		return 0;															//프로그램종료
	
}

int search(struct score *stu,char name[10],int num)							//이름을 인자로 하여 해당 구조체를 탐색하는 함수입니다. 동적할당된 구조체 접근(*stu),찾고자하는 이름(name[10]),최대 할당된 양(num)
{
	int i,count=1;															//반복문을 위한 i변수와 최대 구조체까지 갔는지 여부 판단을 위한 count변수입니다.

	for (i = 0; i < num; i++)												//처음구조체부터 최대 할당된 구조체 크기까지 반복합니다.
	{
		if (count == num)													//구조체 끝까지 찾는 반복이 완료되었다면
			return -1;														//-1을 출력합니다.
		else if (strcmp(stu[i].name,name)==0)								//strcmp함수를 통해 반복하며 비교하는 구조체내부의 배열과 입력받은 name배열을 비교하여 같을경우
		{
			return i;														//같을때의 i값을 리턴하고
			break;															//반복문을 빠져나가며 함수를 끝냅니다.
		}count++;
	}
	
}

void insert(struct score *stu,int num)										//삽입을 위한 함수입니다.	
{
	int i = 0;

	for(i=0;i<num;i++)														//num까지 반복합니다.
	{
		if (stu[i].check != 1)												//삽입할 구조체를 초기에 확보하기 위해 입력받았던 num까지 증가하며 초기화 여부를 판단하는 check변수를 통해 1이 아닌 구조체를 찾은뒤
		{
			stu[i].check = 1;												//해당 구조체를 초기화시켰음을 알기위해 check변수를 1로 바꿉니다.
			printf("name:");												//하위 내용. 해당 구조체의 변수를 초기화 시킵니다.
			scanf("%s", &stu[i].name);
			printf("korean:");
			scanf("%d", &stu[i].kor);
			printf("math:");
			scanf("%d", &stu[i].math);
			printf("english:");
			scanf("%d", &stu[i].eng);
			printf("----------------------------\n");
			break;
		}																	//반복문을 종료하고 함수를 끝냅니다.
	}

}

void calc(struct score *stu,int num)							//평균을 구하기 위한 함수입니다.
{
	
	int out = 0;												//탐색함수 결과를 저장하기 위한 변수
	float s1, s2, s3, res = 0;									//해당 구조체 내의 점수를 저장하고 결과를 내기위한 변수
	char temp[10];												//값을 구하고자 하는 학생의 이름을 입력받기위한 함수

	printf("Enter the name of student: ");
	scanf("%s",temp);											//구하고자 하는 학생의 변수를 temp에 저장후
	out=search(stu,temp,num);									//탐색함수를 통해 구조체를 찾습니다.
	if (out == -1)												//search함수 호출결과 찾지 못했을때
	{
		printf("찾으시는 이름이 없습니다,\n");
	}
	else														//이외에
	{
		s1 = stu[out].eng;										//학생의 점수를 각각 변수에 삽입합니다.
		s2 = stu[out].kor;
		s3 = stu[out].math;
		res = (s1 + s2 + s3) / 3;								//평균을 구하고
		printf("----------------------------\n");
		printf("%s's average is %.2f \n", temp, res);			//결과를 출력한뒤 함수를 종료합니다.
		printf("----------------------------\n");
	}
}

void print(struct score *stu,int num)							//초기화된 전체 구조체를 출력하기 위한 함수로 구조체 접근을 위한 포인터와 전체 구조체갯수를 입력받습니다.
{
	int i = 0;				
	for (i = 0; i < num; i++)									//첫 구조체부터 마지막 구조체까지 반복합니다.
	{
		if (stu[i].check == 1)									//초기화된,값이있는(check 변수가 1)구조체를 찾습니다.
		{
			printf("[%d] Name : %s\n", i + 1, stu[i].name);		//값을 출력합니다. 하위 포함
			printf("[%d] Korean : %d\n", i + 1, stu[i].kor);
			printf("[%d] Math : %d\n", i + 1, stu[i].math);
			printf("[%d] English : %d\n", i + 1, stu[i].eng);
			puts("----------------------");
		}
	}

}

void del(struct score *stu,int num,int *count)								//해당 구조체 접근을 위한 포인터와 최대크기(num) 메인 변수인 count수를 변동시키기 위한 count포인터를 입력받습니다.
{
	int i = 0;																//반복문에서 사용될 변수
	int res=0;																//search 함수호출 뒤 결과를 받을 변수
	char temp[10];															//찾을 이름을 임시로 저장할 배열
	printf("Enter the name of student: ");
	scanf("%s",temp);														//찾아서 삭제할 이름을 입력받아 temp에 임시로 저장합니다.


	res=search(stu, temp, num);												//temp에 저장된 이름을 search함수를 호출하여 해당 구조체를 찾아냅니다.
	if (res == -1)
	{
		printf("찾으시는 이름이 없습니다.\n");
	}
	else
{
	if (res == num)															//만약 마지막 마지막 구조체라면
	{
		memset(&stu[res], NULL, sizeof(struct score));						//해당 구조체를 NULL로 초기화하고
		stu[res].check = 0;													//초기화 여부를 판단하는 check변수를 0으로 초기화합니다.
		(*count)--;															//메인함수의 count변수
	}
	else																	//마지막 구조체가 아니라면 앞또는 뒤에 구조체가 있으므로 
	{
		for (i = res; i < num; i++)											//삭제할 위치에서 시작하며 한단계씩 증가하면서
		{
			if (i == num - 1)												//마지막 구조체에서 그다음 주소를 가져오면 위반이므로
				memset(&stu[i], NULL, sizeof(struct score));				//마지막일경우 바로 NULL로 초기화 하며 
			else															//앞또는 뒤에 구조체가 있는경우
				stu[i] = stu[i + 1];											//다음 구조체 내용을 현재 구조체로 내용을 복사합니다. 

		}
	}
		(*count)--;															//작업 완료 후 하나의 구조체가 NULL상태이므로 count를 하나 줄여서 다시 입력 받을수 있게 합니다.
}
		printf("----------------------------\n");
		printf("The data of %s is deleted\n", temp);						//처음 찾기 위한 이름은 삭제되고 없으므로 temp를 통해 받은 이름을 출력합니다.
		printf("----------------------------\n");

}

