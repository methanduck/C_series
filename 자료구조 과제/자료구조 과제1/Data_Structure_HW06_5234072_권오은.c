#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct																//±¸Á¶Ã¼ Çü½ÄÀ» student·Î Á¤ÀÇÇÕ´Ï´Ù.
{
	char Name[6];
	int kor;
	int math;
	int eng;
	struct student *link;													//¿¬°áµÉ ´ÙÀ½ ±¸Á¶Ã¼¸¦ ÁöÁ¤ÇÏ´Â Æ÷ÀÎÅÍ¸¦ Á¤¤·ÀÇÇÕ´Ï´Ù.
	struct student *prev;

}student;

student *search(char name[6], student *head);								//ÇØ´ç ¸®½ºÆ®ÀÇ ÁÖ¼Ò¸¦ Ã£½À´Ï´Ù.
void create(student *head);													//¸®½ºÆ®¸¦ »ý¼ºÇÕ´Ï´Ù.
void del(student *head);													//¸®½ºÆ®¸¦ »èÁ¦ÇÕ´Ï´Ù.
void calc(student *head);													//¸®½ºÆ®¸¦ Ã£°í ÇØ´ç ¸®½ºÆ®ÀÇ Æò±Õ°ªÀ» ±¸ÇÕ´Ï´Ù.
void printall(student *head);												//ÀúÀåµÈ ¸ðµç ¸®½ºÆ® ³»¿ëÀ» Ãâ·ÂÇÕ´Ï´Ù.
void memfree(student *head);												//¸®½ºÆ® Ã³À½ºÎÅÍ ³¡±îÁö ¹ÝÈ¯½ÃÅ°°í Á¾·áÇÕ´Ï´Ù.


int main()
{

	int input = 0;															//¸Þ´º¼±ÅÃÀ» À§ÇÑ inputº¯¼ö¸¦ 0À¸·Î ÃÊ±âÈ­ÇÕ´Ï´Ù.
	student head;															//Çìµå±¸Á¶Ã¼¸¦ ¼±¾ðÇÕ´Ï´Ù.
	memset(&head, NULL, sizeof(student));									//NULL·Î ±¸Á¶Ã¼¸¦ ÃÊ±âÈ­ÇÕ´Ï´Ù.

	while (1)															//¸Þ´º¸¦ ¹Ýº¹ÀûÀ¸·Î ¼±ÅÃÇÏ±â À§ÇÑ ¹Ýº¹¹®ÀÔ´Ï´Ù.
	{
		printf(" 1.insert a student\n 2.delete a student\n 3.calculate average\n 4.print all student\n 5.exit\n");
		printf(">> ");
		scanf("%d", &input);
		printf("**********************\n");
		switch (input)
		{
		case 1:
			create(&head);												//»ý¼ºÇÔ¼ö È£Ãâ
			continue;
		case 2:
			del(&head);													//»èÁ¦ÇÔ¼ö È£Ãâ
			continue;
		case 3:
			calc(&head);												//Æò±Õ°è»ê ÇÔ¼ö È£Ãâ
			continue;
		case 4:
			printall(&head);											//ÀüÃ¼Ãâ·Â ÇÔ¼ö È£Ãâ
			continue;
		case 5:
			memfree(&head);												//¸ðµÎ ¹ÝÈ¯ÇÏ´Â ÇÔ¼ö È£Ãâ
			break;
		default:
			puts("check your input number");							//ÁöÁ¤µÈ ¼ýÀÚ ÀÌ¿ÜÀÇ °ÍÀ» ÀÔ·ÂÇÏ¿´À» °æ¿ì
		}
		break;
	}
	return 0;
}

student *search(char name[6], student *head)									//ÇØ´ç ¸®½ºÆ®¸¦ °Ë»öÇÏ´Â ÇÔ¼öÀÔ´Ï´Ù. ÁÖ¼Ò°ªÀ» ¹ÝÈ¯ÇÕ´Ï´Ù.
{
	student *temp;															//±¸Á¶Ã¼¸¦ Ã£±âÀ§ÇØ °ªÀÌ ¹Ù²î¸ç Ã£´Â Æ÷ÀÎÅÍ¸¦ ¼±¾ðÇÕ´Ï´Ù.
	temp = head;															//Çìµå±¸Á¶Ã¼ºÎÅÍ ½ÃÀÛ
	if (temp == NULL)															//Çìµå±¸Á¶Ã¼°¡ ´ÙÀ½ Ã¹ ³ëµå¸¦ °¡¸®Å°Áö ¾Ê´Â´Ù¸é
	{
		printf("ÀÚ·á°¡ ÀúÀåµÇ¾î ÀÖÁö ¾Ê½À´Ï´Ù!");							//ÀÚ·á°¡ ¾ø´Â°ÍÀ¸·Î ÆÇ´Ü
	}
	else
	{
		temp = head->link;													//Ã¹³ëµåÀÇ ÁÖ¼Ò¸¦ Æ÷ÀÎÅÍ¿¡ ´ëÀÔÇÕ´Ï´Ù.
		while (temp != head)													//¸®½ºÆ®ÀÇ ³¡±îÁö ¹Ýº¹ÇÏ¸ç
		{
			if (strcmp(name, temp->Name) == 0)								//ÇÔ¼öÀÇ ÀÎÀÚ·Î ¹ÞÀº name[6]°ú ÇØ´ç ¸®½ºÆ®ÀÇ ÀÌ¸§À» ºñ±³ÇÕ´Ï´Ù.
			{
				return temp;												//ÀÏÄ¡ÇÒ¶§ÀÇ ÇØ´ç ¸®½ºÆ® ÁÖ¼Ò¸¦ ¹Þ°í
				break;														//¹Ýº¹¹®À» Áß´ÜÇÕ´Ï´Ù.
			}
			else
				temp = temp->link;											//Ã£Áö ¸øÇÏ¿´À¸¹Ç·Î ´ÙÀ½ ¸®½ºÆ®¸¦ Å½»öÇÕ´Ï´Ù.
		}

		return NULL;														//¸®½ºÆ®³» Ã£´Â ÀÌ¸§ÀÌ ¾øÀ»°æ¿ì NULLÀ» ¹ÝÈ¯ÇÕ´Ï´Ù.
	}

}

void create(student *head)													//¸®½ºÆ® »ý¼º ÇÔ¼öÀÔ´Ï´Ù.		
{
	student *temp = NULL;														//1.Ã¹ ³ëµå¸¦ »ý¼ºÇÒ¶§ »ç¿ë 2. ´ÙÀ½¸µÅ©°¡ ºñ¾îÀÖ´Â ¸®½ºÆ®¸¦ Ã£´Â ¿ëµµ
	student *n = NULL;														//¸®½ºÆ® ÇÒ´çÀ» À§ÇØ »ç¿ë

	if (head->link == NULL)													//Ã¹ ³ëµå »ý¼º½Ã¿¡ 
	{
		temp = (student *)malloc(sizeof(student));							//µ¿ÀûÇÒ´ç
		head->link = temp;													//ÇìµåÆ÷ÀÎÅÍ¿¡ Ã¹ ³ëµåÁÖ¼Ò¸¦ ³Ö½À´Ï´Ù.
		temp->link = head;													//Ã¹³ëµåÀÇ ¸µÅ©´Â NULL·Î ÃÊ±âÈ­ÇÕ´Ï´Ù.
		head->prev = temp;
		temp->prev = head;

		printf("Name :");												//ÀÚ·á¸¦ ÀÔ·Â¹Þ½À´Ï´Ù.
		scanf("%s", &temp->Name);
		printf("korean :");
		scanf("%d", &temp->kor);
		printf("math :");
		scanf("%d", &temp->math);
		printf("english :");
		scanf("%d", &temp->eng);
	}
	else																	//Ã¹³ëµå°¡ ¾Æ´Ò°æ¿ì
	{
		temp = head->link;													//temp¿¡ Ã¹³ëµåÀÇ ¸µÅ©¸¦ ³Ö½À´Ï´Ù.
		while (1)															//¹«ÇÑ
		{
			if (temp->link == head)											//´ÙÀ½ ³ëµå°¡ Á¸ÀçÇÏÁö ¾ÊÀ»¶§
				break;														//¹Ýº¹¹®À» Á¾·áÇÏ°Å³ª
			else
				temp = (*temp).link;										//´ÙÀ½ ¸®½ºÆ®¸¦ Å½»öÇÕ´Ï´Ù.
		}
		n = (student *)malloc(sizeof(student));							//»õ·Î¿î ¸®½ºÆ®¸¦ ÇÒ´çÇÏ°í
		temp->link = n;													//¸µÅ©°¡ ºñ¾îÀÖ´Â ±¸Á¶Ã¼¿¡ ÇöÀç ¸®½ºÆ®ÀÇ ÁÖ¼Ò¸¦ ³Ö½À´Ï´Ù.
		n->link = head;													//»õ ¸®½ºÆ®ÀÇ ¸µÅ©´Â ÃÊ±âÈ­ÇÕ´Ï´Ù.
		n->prev = temp;


		printf("Name :");												//ÀÚ·á¸¦ ÀÔ·Â¹Þ½À´Ï´Ù.
		scanf("%s", &n->Name);
		printf("korean :");
		scanf("%d", &n->kor);
		printf("math :");
		scanf("%d", &n->math);
		printf("english :");
		scanf("%d", &n->eng);
	}


}

void del(student *head)														//»èÁ¦ÇÔ¼öÀÔ´Ï´Ù.
{
	student *target = NULL;												//Å½»öÇÔ¼ö¸¦ È£ÃâÇÑ µÚ °á°úÁÖ¼Ò¸¦ ¹Þ´Â Æ÷ÀÎÅÍÀÔ´Ï´Ù.
	student *temp = NULL;													//»èÁ¦ÇÒ ¸®½ºÆ® ¹Ù·Î ¾ÕÀÇ ¸®½ºÆ®ÁÖ¼Ò¸¦ ÀúÀåÇÒ Æ÷ÀÎÅÍÀÔ´Ï´Ù.
	student *temp2 = NULL;
	char name[6];															//Ã£À» ÀÌ¸§À» ÀÔ·Â¹ÞÀ» º¯¼öÀÔ´Ï´Ù.
	printf("Enter the name of student :");
	scanf("%s", &name);
	target = search(name, head);											//Å½»öÇÔ¼ö¸¦ È£ÃâÇÏ¿© ÇØ´ç ¸®½ºÆ® ÁÖ¼Ò¸¦ ¹Þ½À´Ï´Ù.
	temp2 = target->link;
	temp = head->link;														//Ã¹ ³ëµåÁÖ¼Ò¸¦ temp¿¡ ³Ö½À´Ï´Ù.
	while (temp != NULL)														//¸®½ºÆ® ³¡±îÁö ¹Ýº¹
	{
		if (temp->link == target)										//´ÙÀ½ ¸®½ºÆ® ÁÖ¼Ò°¡ searchres°ªÀÎ ¸®½ºÆ®¶ó¸é
		{
			temp->link = target->link;									//»èÁ¦ÇÒ ÀÌÀüÀÇ ¸®½ºÆ® ¸µÅ©¿¡ »èÁ¦ÇÒ ´ÙÀ½¸®½ºÆ® ¸µÅ©¸¦ ¹­¾îÁÝ´Ï´Ù.
			temp2->prev = temp;
			break;															//¹Ýº¹¹® Áß´Ü
		}
		temp = temp->link;													//´ÙÀ½ ¸®½ºÆ®·Î °¡±âÀ§ÇÑ ÀÛ¾÷
	}

	
	free(target);														//»èÁ¦ÇÒ ¸®½ºÆ®¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.
}

void calc(student *head)													//Æò±Õ°è»ê ÇÔ¼öÀÔ´Ï´Ù.
{
	char inname[6];															//°Ë»öÇÒ ÀÌ¸§À» ¹ÞÀ» ¹®ÀÚ¿­ÀÔ´Ï´Ù.
	float res, k, m, e = 0;														//ÇØ´çÇÏ´Â ÇÐ»ýÀÇ Æò±ÕÀ» ±¸ÇÏ±â À§ÇÑ º¯¼öÀÔ´Ï´Ù.
	student *temp;															//Å½»öÇÔ¼ö È£ÃâÈÄ ÁÖ¼Ò¸¦ ¹Þ±âÀ§ÇÑ Æ÷ÀÎÅÍÀÔ´Ï´Ù.

	printf("Enter the student name:");
	scanf("%s", &inname);
	temp = search(inname, head);												//Å½»öÈÄ temp¿¡ ÇØ´ç ¸®½ºÆ® ÁÖ¼Ò¸¦ ´ëÀÔÇÕ´Ï´Ù.
	if (temp == NULL)														//Å½»öÈÄ ÇØ´ç °á°ú¸¦ Ã£Áö ¸øÇÏ¿´À»°æ¿ì
	{
		printf("Not Found\n");
		printf("------------------\n");
	}
	else																	//ÇØ´çÇÏ´Â ¸®½ºÆ® Á¡¼ö Æò±ÕÀ» ±¸ÇÏ¿© Ãâ·ÂÇÕ´Ï´Ù.
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

void printall(student *head)												//ÀúÀåµÈ ¸ðµç ¸®½ºÆ®¸¦ Ãâ·ÂÇÏ´Â ÇÔ¼öÀÔ´Ï´Ù.
{
	student *temp;															//Å½»öÇÏ±â À§ÇØ »ç¿ëµÉ Æ÷ÀÎÅÍÀÔ´Ï´Ù.

	if (head->link == NULL)													//Ã¹³ëµå°¡ Á¸ÀçÇÏÁö ¾Ê´Â°æ¿ì
	{
		printf("Ãâ·ÂÇÒ ÀÚ·á°¡ ¾ø½À´Ï´Ù.\n");
		printf("**********************\n");
	}
	else
	{
		temp = head->link;													//Ã¹³ëµå ÁÖ¼Ò¸¦ temp¿¡ ´ëÀÔÇÕ´Ï´Ù.
		while (temp != head)													//³ëµå ³¡±îÁö Å½»öÇÕ´Ï´Ù.
		{
			printf("Name  :  %s\n", temp->Name);								//°ª Ãâ·Â
			printf("Kor   :  %d\n", temp->kor);
			printf("Math  :  %d\n", temp->math);
			printf("Eng   :  %d\n", temp->eng);
			printf("------------------\n");
			temp = temp->link;												//´ÙÀ½ ¸®½ºÆ® ÁÖ¼Ò¸¦ ´ëÀÔÇÕ´Ï´Ù.
		}
	}
}

void memfree(student *head)													//¸ðµç ¸®½ºÆ®¸¦ ¿î¿µÃ¼Á¦¿¡ ¹ÝÈ¯ÇÏ´Â ÇÔ¼öÀÔ´Ï´Ù.
{
	student *temp1;															//Áö¿öÁú ¸®½ºÆ®ÀÇ ÁÖ¼Ò¸¦ ¹ÞÀ» Æ÷ÀÎÅÍÀÔ´Ï´Ù.
	student *temp2;															//Áö¿öÁú ¸®½ºÆ®ÀÇ ´ÙÀ½ ¸®½ºÆ® ÁÖ¼Ò¸¦ ¹ÞÀ» Æ÷ÀÎÅÍ ÀÔ´Ï´Ù.
	if (head->link == NULL)													//³ëµå°¡ ¾ø´Â »óÅÂ¶ó¸é
		free(head);
	else
	{
		temp1 = head;														//Çìµå¸¦ temp1¿¡ ³Ö°í
		temp2 = head->link;													//Ã¹³ëµåÀÇ ÁÖ¼Ò¿¡ ÇØ´çÇÏ´Â head->link°ªÀ» temp2¿¡ ³Ö½À´Ï´Ù.
		while (temp2->link != head)											//´ÙÀ½ ¸®½ºÆ®°¡ ¾øÀ»¶§±îÁö
		{

			temp1 = temp2;													//Ã¹¹øÂ° ³ëµåÁÖ¼Ò¸¦ °¡Áý´Ï´Ù.
			temp2 = temp1->link;											//µÎ¹øÂ° ³ëµåÁÖ¼Ò¸¦ °¡Áý´Ï´Ù.
			free(temp1);													//Ã¹³ëµå¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.
		}
	}
}




