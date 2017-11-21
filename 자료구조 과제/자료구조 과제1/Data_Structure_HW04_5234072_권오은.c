#include<stdio.h>
#include<string.h>															//strcmp�Լ��� Ȱ���ϱ� ���� �־����ϴ�.
#include<stdlib.h>															//�����޸��Ҵ��� ���� �־����ϴ�.
struct score 
{
	char name[10];															//�л��� �̸�
	int kor;																//check�������� ��������
	int math;
	int eng;
	int check;																//�ش� ����ü�� �ʱ�ȭ�� �Ǿ������� �����ϱ� ���� �־����ϴ�.
};
int search(struct score *stu,char name[10],int num);						//���° ����ü���� �ĺ��ϱ� ���� �Լ��Դϴ�. �������� �Լ������� �Լ����� ������ �ξ����ϴ�.
void insert(struct score *stu,int num);										//������ ���� �Լ��Դϴ�.
void del(struct score *stu,int num,int *count);								//������ ���� �Լ��Դϴ�.
void calc(struct score *stu, int num);										//��հ� ����� ���� �Լ��Դϴ�.
void print(struct score *stu,int num);										//�ʱ�ȭ�� ����ü�� ��ü ���� ����ϱ� ���� �Լ��Դϴ�.

int main()
{
	int num,input,count=0;													//num:�Ҵ��� ����ü ����, input:����,���� �� �޴������� �Է¹ޱ� ����, count: �ʱ� �л� ����ü ���� Ȯ���ϱ� ����

	printf("Enter the number of students: ");
	scanf("%d", &num);														//����ü ������ �Է¹޽��ϴ�.
	struct score *stu= (struct score *)malloc(sizeof(struct score)*num);	//������ŭ score������ ����ü�� �����Ҵ� �޽��ϴ�.
	
	if (stu == NULL)														//�Ҵ���� ���� �ش� �����Ͱ� NULL���ϰ��
	{	
		puts("�����Ҵ翡 �����߽��ϴ�.");									//���
	}
	else
		
		printf("%d students can be stored.\n", num);						//�Ҵ���� ��� ���
		puts("Program Start!");
		printf("\n--------------------------\n");
		while (1)															//��� �޴��� �����ϱ� ���� �ݺ�
		{
			printf(" 1.insert a student\n 2.delete a student\n 3.calculate average\n 4.print all student\n 5.exit\n");//�޴����
			printf("������ �ּ���:");
			scanf("%d", &input);											//input�� ���ϴ� �޴��� ���ù���
			printf("**********************\n");
			switch (input)													//input���� ����
			{
			case 1:															//1: insert
				if (count < num)											//count������ ���� �ʱ⿡ �����Ҵ�� Ȯ���ߴ� ���� üũ�մϴ�.
				{
					insert(stu,num);										//insert�Լ��� ���� ���� �Է��մϴ�.
					count++;												//�� �Է½� ���� count������ ������ŵ�ϴ�.
				}
				else
				{
					printf("�Է��Ͻ� �л� �� ���� �����ϴ�\n");				//�̿��� ���� �Է��� �����ʰ� �����
					printf("\n--------------------------\n");
				}
				continue;													//�޴��������� ���ư��ϴ�.
			case 2:
				del(stu,num,&count);										//�����Լ�ȣ��
				continue;													//�Ϸ��� �޴��� ���ư��ϴ�.
			case 3:
				calc(stu,num);												//��հ���Լ� ȣ��
				continue;													//�Ϸ��� �޴��� ���ư��ϴ�.
			case 4:
				print(stu,num);												//�ʱ�ȭ�� ����ü ��ü ���� ���
				continue;													//�Ϸ��� �޴��� ���ư��ϴ�.
			case 5:
				free(stu);													//5���� ����ȣ��� free�Լ��� ���� ���� �Ҵ� �޾Ҵ� stu�����͸� ���ڷ� �ü���� ��ȯ�մϴ�.
				break;														//���Ḧ �ϱ� ���� ����ġ ������ �����ϴ�.
			default:
				puts("�������� �ùٸ� ���ڸ� �Է��� �ּ���");				//1~5�� ������ ���ý� ���
			}
			break;															//����ġ�� ���°�� �ݺ��� Ż���� ���� break;
		}
		return 0;															//���α׷�����
	
}

int search(struct score *stu,char name[10],int num)							//�̸��� ���ڷ� �Ͽ� �ش� ����ü�� Ž���ϴ� �Լ��Դϴ�. �����Ҵ�� ����ü ����(*stu),ã�����ϴ� �̸�(name[10]),�ִ� �Ҵ�� ��(num)
{
	int i,count=1;															//�ݺ����� ���� i������ �ִ� ����ü���� ������ ���� �Ǵ��� ���� count�����Դϴ�.

	for (i = 0; i < num; i++)												//ó������ü���� �ִ� �Ҵ�� ����ü ũ����� �ݺ��մϴ�.
	{
		if (count == num)													//����ü ������ ã�� �ݺ��� �Ϸ�Ǿ��ٸ�
			return -1;														//-1�� ����մϴ�.
		else if (strcmp(stu[i].name,name)==0)								//strcmp�Լ��� ���� �ݺ��ϸ� ���ϴ� ����ü������ �迭�� �Է¹��� name�迭�� ���Ͽ� �������
		{
			return i;														//�������� i���� �����ϰ�
			break;															//�ݺ����� ���������� �Լ��� �����ϴ�.
		}count++;
	}
	
}

void insert(struct score *stu,int num)										//������ ���� �Լ��Դϴ�.	
{
	int i = 0;

	for(i=0;i<num;i++)														//num���� �ݺ��մϴ�.
	{
		if (stu[i].check != 1)												//������ ����ü�� �ʱ⿡ Ȯ���ϱ� ���� �Է¹޾Ҵ� num���� �����ϸ� �ʱ�ȭ ���θ� �Ǵ��ϴ� check������ ���� 1�� �ƴ� ����ü�� ã����
		{
			stu[i].check = 1;												//�ش� ����ü�� �ʱ�ȭ�������� �˱����� check������ 1�� �ٲߴϴ�.
			printf("name:");												//���� ����. �ش� ����ü�� ������ �ʱ�ȭ ��ŵ�ϴ�.
			scanf("%s", &stu[i].name);
			printf("korean:");
			scanf("%d", &stu[i].kor);
			printf("math:");
			scanf("%d", &stu[i].math);
			printf("english:");
			scanf("%d", &stu[i].eng);
			printf("----------------------------\n");
			break;
		}																	//�ݺ����� �����ϰ� �Լ��� �����ϴ�.
	}

}

void calc(struct score *stu,int num)							//����� ���ϱ� ���� �Լ��Դϴ�.
{
	
	int out = 0;												//Ž���Լ� ����� �����ϱ� ���� ����
	float s1, s2, s3, res = 0;									//�ش� ����ü ���� ������ �����ϰ� ����� �������� ����
	char temp[10];												//���� ���ϰ��� �ϴ� �л��� �̸��� �Է¹ޱ����� �Լ�

	printf("Enter the name of student: ");
	scanf("%s",temp);											//���ϰ��� �ϴ� �л��� ������ temp�� ������
	out=search(stu,temp,num);									//Ž���Լ��� ���� ����ü�� ã���ϴ�.
	if (out == -1)												//search�Լ� ȣ���� ã�� ��������
	{
		printf("ã���ô� �̸��� �����ϴ�,\n");
	}
	else														//�̿ܿ�
	{
		s1 = stu[out].eng;										//�л��� ������ ���� ������ �����մϴ�.
		s2 = stu[out].kor;
		s3 = stu[out].math;
		res = (s1 + s2 + s3) / 3;								//����� ���ϰ�
		printf("----------------------------\n");
		printf("%s's average is %.2f \n", temp, res);			//����� ����ѵ� �Լ��� �����մϴ�.
		printf("----------------------------\n");
	}
}

void print(struct score *stu,int num)							//�ʱ�ȭ�� ��ü ����ü�� ����ϱ� ���� �Լ��� ����ü ������ ���� �����Ϳ� ��ü ����ü������ �Է¹޽��ϴ�.
{
	int i = 0;				
	for (i = 0; i < num; i++)									//ù ����ü���� ������ ����ü���� �ݺ��մϴ�.
	{
		if (stu[i].check == 1)									//�ʱ�ȭ��,�����ִ�(check ������ 1)����ü�� ã���ϴ�.
		{
			printf("[%d] Name : %s\n", i + 1, stu[i].name);		//���� ����մϴ�. ���� ����
			printf("[%d] Korean : %d\n", i + 1, stu[i].kor);
			printf("[%d] Math : %d\n", i + 1, stu[i].math);
			printf("[%d] English : %d\n", i + 1, stu[i].eng);
			puts("----------------------");
		}
	}

}

void del(struct score *stu,int num,int *count)								//�ش� ����ü ������ ���� �����Ϳ� �ִ�ũ��(num) ���� ������ count���� ������Ű�� ���� count�����͸� �Է¹޽��ϴ�.
{
	int i = 0;																//�ݺ������� ���� ����
	int res=0;																//search �Լ�ȣ�� �� ����� ���� ����
	char temp[10];															//ã�� �̸��� �ӽ÷� ������ �迭
	printf("Enter the name of student: ");
	scanf("%s",temp);														//ã�Ƽ� ������ �̸��� �Է¹޾� temp�� �ӽ÷� �����մϴ�.


	res=search(stu, temp, num);												//temp�� ����� �̸��� search�Լ��� ȣ���Ͽ� �ش� ����ü�� ã�Ƴ��ϴ�.
	if (res == -1)
	{
		printf("ã���ô� �̸��� �����ϴ�.\n");
	}
	else
{
	if (res == num)															//���� ������ ������ ����ü���
	{
		memset(&stu[res], NULL, sizeof(struct score));						//�ش� ����ü�� NULL�� �ʱ�ȭ�ϰ�
		stu[res].check = 0;													//�ʱ�ȭ ���θ� �Ǵ��ϴ� check������ 0���� �ʱ�ȭ�մϴ�.
		(*count)--;															//�����Լ��� count����
	}
	else																	//������ ����ü�� �ƴ϶�� �նǴ� �ڿ� ����ü�� �����Ƿ� 
	{
		for (i = res; i < num; i++)											//������ ��ġ���� �����ϸ� �Ѵܰ辿 �����ϸ鼭
		{
			if (i == num - 1)												//������ ����ü���� �״��� �ּҸ� �������� �����̹Ƿ�
				memset(&stu[i], NULL, sizeof(struct score));				//�������ϰ�� �ٷ� NULL�� �ʱ�ȭ �ϸ� 
			else															//�նǴ� �ڿ� ����ü�� �ִ°��
				stu[i] = stu[i + 1];											//���� ����ü ������ ���� ����ü�� ������ �����մϴ�. 

		}
	}
		(*count)--;															//�۾� �Ϸ� �� �ϳ��� ����ü�� NULL�����̹Ƿ� count�� �ϳ� �ٿ��� �ٽ� �Է� ������ �ְ� �մϴ�.
}
		printf("----------------------------\n");
		printf("The data of %s is deleted\n", temp);						//ó�� ã�� ���� �̸��� �����ǰ� �����Ƿ� temp�� ���� ���� �̸��� ����մϴ�.
		printf("----------------------------\n");

}

