#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct																//援ъ“泥??뺤떇??student濡??뺤쓽?⑸땲??
{
	char Name[6];
	int kor;
	int math;
	int eng;
	struct student *link;													//?곌껐???ㅼ쓬 援ъ“泥대? 吏?뺥븯???ъ씤?곕? ?뺛뀋?섑빀?덈떎.

}student;

student *search(char name[6], student *head);								//?대떦 由ъ뒪?몄쓽 二쇱냼瑜?李얠뒿?덈떎.
void create(student *head);													//由ъ뒪?몃? ?앹꽦?⑸땲??
void del(student *head);													//由ъ뒪?몃? ??젣?⑸땲??
void calc(student *head);													//由ъ뒪?몃? 李얘퀬 ?대떦 由ъ뒪?몄쓽 ?됯퇏媛믪쓣 援ы빀?덈떎.
void printall(student *head);												//??λ맂 紐⑤뱺 由ъ뒪???댁슜??異쒕젰?⑸땲??
void memfree(student *head);												//由ъ뒪??泥섏쓬遺???앷퉴吏 諛섑솚?쒗궎怨?醫낅즺?⑸땲??


int main()
{

	int input=0;															//硫붾돱?좏깮???꾪븳 input蹂?섎? 0?쇰줈 珥덇린?뷀빀?덈떎.
	student head;															//?ㅻ뱶援ъ“泥대? ?좎뼵?⑸땲??
	memset(&head, NULL, sizeof(student));									//NULL濡?援ъ“泥대? 珥덇린?뷀빀?덈떎.
	
		while (1)															//硫붾돱瑜?諛섎났?곸쑝濡??좏깮?섍린 ?꾪븳 諛섎났臾몄엯?덈떎.
		{
			printf(" 1.insert a student\n 2.delete a student\n 3.calculate average\n 4.print all student\n 5.exit\n");
			printf(">> ");
			scanf("%d", &input);											
			printf("**********************\n");
			switch (input)													
			{
			case 1:															
                create(&head);												//?앹꽦?⑥닔 ?몄텧
				continue;													
			case 2:
				del(&head);													//??젣?⑥닔 ?몄텧
				continue;													
			case 3:
				calc(&head);												//?됯퇏怨꾩궛 ?⑥닔 ?몄텧
				continue;													
			case 4:
				printall(&head);											//?꾩껜異쒕젰 ?⑥닔 ?몄텧
				continue;													
			case 5:
				memfree(&head);												//紐⑤몢 諛섑솚?섎뒗 ?⑥닔 ?몄텧
				break;														
			default:
				puts("check your input number");							//吏?뺣맂 ?レ옄 ?댁쇅??寃껋쓣 ?낅젰?섏???寃쎌슦
			}
			break;															
		}
		return 0;		
}

student *search(char name[6],student *head)									//?대떦 由ъ뒪?몃? 寃?됲븯???⑥닔?낅땲?? 二쇱냼媛믪쓣 諛섑솚?⑸땲??
{
	student *temp;															//援ъ“泥대? 李얘린?꾪빐 媛믪씠 諛붾뚮ŉ 李얜뒗 ?ъ씤?곕? ?좎뼵?⑸땲??
	temp = head;															//?ㅻ뱶援ъ“泥대????쒖옉
	if(temp==NULL)															//?ㅻ뱶援ъ“泥닿? ?ㅼ쓬 泥??몃뱶瑜?媛由ы궎吏 ?딅뒗?ㅻ㈃
	{
		printf("?먮즺媛 ??λ릺???덉? ?딆뒿?덈떎!");							//?먮즺媛 ?녿뒗寃껋쑝濡??먮떒
	}
	else
	{
		temp=head->link;													//泥ル끂?쒖쓽 二쇱냼瑜??ъ씤?곗뿉 ??낇빀?덈떎.
		while(temp!=NULL)													//由ъ뒪?몄쓽 ?앷퉴吏 諛섎났?섎ŉ
		{
			if (strcmp(name, temp->Name) == 0)								//?⑥닔???몄옄濡?諛쏆? name[6]怨??대떦 由ъ뒪?몄쓽 ?대쫫??鍮꾧탳?⑸땲??
			{
				return temp;												//?쇱튂?좊븣???대떦 由ъ뒪??二쇱냼瑜?諛쏄퀬
				break;														//諛섎났臾몄쓣 以묐떒?⑸땲??
			}
			else
				temp = temp->link;											//李얠? 紐삵븯??쇰?濡??ㅼ쓬 由ъ뒪?몃? ?먯깋?⑸땲??
		}
		
		return NULL;														//由ъ뒪?몃궡 李얜뒗 ?대쫫???놁쓣寃쎌슦 NULL??諛섑솚?⑸땲??
	}

}

void create(student *head)													//由ъ뒪???앹꽦 ?⑥닔?낅땲??		
{
	student *temp=NULL;														//1.泥??몃뱶瑜??앹꽦?좊븣 ?ъ슜 2. ?ㅼ쓬留곹겕媛 鍮꾩뼱?덈뒗 由ъ뒪?몃? 李얜뒗 ?⑸룄
	student *n=NULL;														//由ъ뒪???좊떦???꾪빐 ?ъ슜

	if(head->link==NULL)													//泥??몃뱶 ?앹꽦?쒖뿉 
	{
		temp=(student *)malloc(sizeof(student));							//?숈쟻?좊떦
		head->link=temp;													//?ㅻ뱶?ъ씤?곗뿉 泥??몃뱶二쇱냼瑜??ｌ뒿?덈떎.
		temp->link = NULL;													//泥ル끂?쒖쓽 留곹겕??NULL濡?珥덇린?뷀빀?덈떎.

		printf("Name :");												//?먮즺瑜??낅젰諛쏆뒿?덈떎.
		scanf("%s", &temp->Name);
		printf("korean :");
		scanf("%d", &temp->kor);
		printf("math :");
		scanf("%d", &temp->math);
		printf("english :");
		scanf("%d", &temp->eng);
	}
	else																	//泥ル끂?쒓? ?꾨땺寃쎌슦
	{
		temp=head->link;													//temp??泥ル끂?쒖쓽 留곹겕瑜??ｌ뒿?덈떎.
		while(1)															//臾댄븳
		{
			if (temp->link == NULL)											//?ㅼ쓬 ?몃뱶媛 議댁옱?섏? ?딆쓣??
				break;														//諛섎났臾몄쓣 醫낅즺?섍굅??
			else
				temp = (*temp).link;										//?ㅼ쓬 由ъ뒪?몃? ?먯깋?⑸땲??
		}
			n=(student *)malloc(sizeof(student));							//?덈줈??由ъ뒪?몃? ?좊떦?섍퀬
			temp->link=n;													//留곹겕媛 鍮꾩뼱?덈뒗 援ъ“泥댁뿉 ?꾩옱 由ъ뒪?몄쓽 二쇱냼瑜??ｌ뒿?덈떎.
			n->link = NULL;													//??由ъ뒪?몄쓽 留곹겕??珥덇린?뷀빀?덈떎.

			printf("Name :");												//?먮즺瑜??낅젰諛쏆뒿?덈떎.
			scanf("%s",&n->Name);
			printf("korean :");
			scanf("%d",&n->kor);
			printf("math :");
			scanf("%d",&n->math);
			printf("english :");
			scanf("%d",&n->eng);		
	}


}

void del(student *head)														//??젣?⑥닔?낅땲??
{
	student *searchres=NULL;												//?먯깋?⑥닔瑜??몄텧????寃곌낵二쇱냼瑜?諛쏅뒗 ?ъ씤?곗엯?덈떎.
	student *temp=NULL;														//??젣??由ъ뒪??諛붾줈 ?욎쓽 由ъ뒪?몄＜?뚮? ??ν븷 ?ъ씤?곗엯?덈떎.
	char name[6];															//李얠쓣 ?대쫫???낅젰諛쏆쓣 蹂?섏엯?덈떎.
	printf("Enter the name of student :");
	scanf("%s",&name);

	searchres = search(name, head);											//?먯깋?⑥닔瑜??몄텧?섏뿬 ?대떦 由ъ뒪??二쇱냼瑜?諛쏆뒿?덈떎.

	temp=head->link;														//泥??몃뱶二쇱냼瑜?temp???ｌ뒿?덈떎.
	while(temp!=NULL)														//由ъ뒪???앷퉴吏 諛섎났
	{
		if (temp->link == searchres)										//?ㅼ쓬 由ъ뒪??二쇱냼媛 searchres媛믪씤 由ъ뒪?몃씪硫?
		{
			temp->link = searchres->link;									//??젣???댁쟾??由ъ뒪??留곹겕????젣???ㅼ쓬由ъ뒪??留곹겕瑜?臾띠뼱以띾땲??
			break;															//諛섎났臾?以묐떒
		}
		temp=temp->link;													//?ㅼ쓬 由ъ뒪?몃줈 媛湲곗쐞???묒뾽
	}
	
	free(searchres);														//??젣??由ъ뒪?몃? 諛섑솚?⑸땲??
}

void calc(student *head)													//?됯퇏怨꾩궛 ?⑥닔?낅땲??
{
	char inname[6];															//寃?됲븷 ?대쫫??諛쏆쓣 臾몄옄?댁엯?덈떎.
	float res,k,m,e=0;														//?대떦?섎뒗 ?숈깮???됯퇏??援ы븯湲??꾪븳 蹂?섏엯?덈떎.
	student *temp;															//?먯깋?⑥닔 ?몄텧??二쇱냼瑜?諛쏄린?꾪븳 ?ъ씤?곗엯?덈떎.

	printf("Enter the student name:");
	scanf("%s",&inname);
	temp=search(inname,head);												//?먯깋??temp???대떦 由ъ뒪??二쇱냼瑜???낇빀?덈떎.
	if (temp == NULL)														//?먯깋???대떦 寃곌낵瑜?李얠? 紐삵븯??꾧꼍??
	{
		printf("Not Found\n");
		printf("------------------\n");
	}
	else																	//?대떦?섎뒗 由ъ뒪???먯닔 ?됯퇏??援ы븯??異쒕젰?⑸땲??
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

void printall(student *head)												//??λ맂 紐⑤뱺 由ъ뒪?몃? 異쒕젰?섎뒗 ?⑥닔?낅땲??
{
	student *temp;															//?먯깋?섍린 ?꾪빐 ?ъ슜???ъ씤?곗엯?덈떎.

	if(head->link == NULL)													//泥ル끂?쒓? 議댁옱?섏? ?딅뒗寃쎌슦
	{
	printf("異쒕젰???먮즺媛 ?놁뒿?덈떎.\n");
	printf("**********************\n");
	}
	else															
	{
		temp=head->link;													//泥ル끂??二쇱냼瑜?temp????낇빀?덈떎.
		while(temp!=NULL)													//?몃뱶 ?앷퉴吏 ?먯깋?⑸땲??
		{
			printf("Name  :  %s\n",temp->Name);								//媛?異쒕젰
			printf("Kor   :  %d\n",temp->kor);
			printf("Math  :  %d\n",temp->math);
			printf("Eng   :  %d\n",temp->eng);
			printf("------------------\n");
			temp=temp->link;												//?ㅼ쓬 由ъ뒪??二쇱냼瑜???낇빀?덈떎.
		}
	}
}

void memfree(student *head)													//紐⑤뱺 由ъ뒪?몃? ?댁쁺泥댁젣??諛섑솚?섎뒗 ?⑥닔?낅땲??
{
	student *temp1;															//吏?뚯쭏 由ъ뒪?몄쓽 二쇱냼瑜?諛쏆쓣 ?ъ씤?곗엯?덈떎.
	student *temp2;															//吏?뚯쭏 由ъ뒪?몄쓽 ?ㅼ쓬 由ъ뒪??二쇱냼瑜?諛쏆쓣 ?ъ씤???낅땲??
	if (head->link == NULL)													//?몃뱶媛 ?녿뒗 ?곹깭?쇰㈃
		free(head);
	else
	{
		temp1 = head;														//?ㅻ뱶瑜?temp1???ｊ퀬
		temp2 = head->link;													//泥ル끂?쒖쓽 二쇱냼???대떦?섎뒗 head->link媛믪쓣 temp2???ｌ뒿?덈떎.
		while (temp2->link != NULL)											//?ㅼ쓬 由ъ뒪?멸? ?놁쓣?뚭퉴吏
		{
			
			temp1 = temp2;													//泥ル쾲吏??몃뱶二쇱냼瑜?媛吏묐땲??
			temp2 = temp1->link;											//?먮쾲吏??몃뱶二쇱냼瑜?媛吏묐땲??
			free(temp1);													//泥ル끂?쒕? 諛섑솚?⑸땲??
		}
	}
}
