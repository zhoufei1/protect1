#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#define ID_SIZE 512
#define NAME_SIZE 512
#define SIZE 100

typedef struct student
{
	char Id[ID_SIZE];  //ѧ��ѧ��
	char Name[NAME_SIZE]; //ѧ������
	float Math;   //��ѧ
	float English; //Ӣ��
	float Chinese;  //����
	float TotalScore; //�ܷ�
	float AverageScore; //ƽ����
	int PassStudent;  //��������
	struct student *next;
}student;

static float PassRate=0.0;   //������

//��ʼ��ѧ����Ϣ
void InitStudent(student *head)
{
	strcpy(head->Id,"");
	strcpy(head->Name,"");
	head->Chinese=0.0;
	head->English=0.0;
	head->Math=0.0;
	head->PassStudent=0;
	head->TotalScore=0;
	head->next=NULL;
}

//����ѧ���ɼ�
void Student_Insert(student *head)
{
	int flag=0;
	student *cur=head;
	student *tmp=(student *)malloc(sizeof(student));
	tmp->next=NULL;
	assert(tmp !=NULL);

	printf("������ѧ�ţ�");
	scanf("%s",tmp->Id);
	printf("������������");
	scanf("%s",tmp->Name);
	printf("��������ѧ�ɼ���");
	scanf("%f",&tmp->Math);
	printf("������Ӣ��ɼ���");
	scanf("%f",&tmp->English);
	printf("���������ĳɼ���");
	scanf("%f",&tmp->Chinese);
	tmp->TotalScore=tmp->Chinese+tmp->English+tmp->Math;
	tmp->AverageScore=tmp->TotalScore/3;

	tmp->PassStudent=0;
	if(tmp->Chinese >=60)
		tmp->PassStudent++;
	if(tmp->English >=60)
		tmp->PassStudent++;
	if(tmp->Math >=60)
		tmp->PassStudent++;

	if(tmp->PassStudent==3)
		flag++;
	tmp->AverageScore=tmp->TotalScore/3;

	printf("\tѧ������������%d\n",flag);
	
	while(cur->next !=NULL)
		cur=cur->next;
	cur->next=tmp;
}
/*ɾ��ѧ����Ϣ*/
void Student_Delete(student *head,char *id)
{
	student *del=NULL;
	student *cur=head;
	while(cur->next !=NULL)
	{
		if(strcmp(cur->next->Id,id)==0)
		{
			del=cur->next;
			cur->next=del->next;
			free(del);
			printf("***ɾ���ɹ�***\n");
			return;
		}
		cur=cur->next;
	}
	printf("***ɾ��ʧ��***\n");
}
/*�޸�ѧ����Ϣ*/
void Student_Modify(student *head)
{
	char number[ID_SIZE];
	int flag=0;
	student *cur=head->next;
	assert(cur !=NULL);
	printf("\t������ѧ��ѧ�ţ�");
	scanf("%s",number);
	printf("***��ʼ����***\n");
	while(cur !=NULL)
	{
		if(strcmp(cur->Id,number)==0)
		{
			printf("������׼���޸ĵ����ĳɼ���");
			scanf("%f",&cur->Chinese);
			printf("������׼���޸ĵ���ѧ�ɼ���");
			scanf("%f",&cur->Math);
			printf("������׼���޸ĵ�Ӣ��ɼ���");
			scanf("%f",&cur->English);
			flag=1;
			break;
		}
		cur->next;
	}
	if(flag)
		printf("***�޸ĳɹ�***\n");
	else
		printf("***�޸�ʧ��***\n");
}
/*��������ѯ*/
void Student_Select(student *head,char *name)
{
	student *cur=head->next;
	while(cur!=NULL)
	{
		if(strcmp(cur->Name,name)==0)
		{
			printf("***�������ѧ��***\n");
			return;
		}
		cur=cur->next;
	}
	printf("***����������ʧ��***\n");
}
/*��ʾ����ѧ����¼*/
void Student_DisplaySingle(student *head,int index)
{
	int count=1;
	student *cur=head->next;
	while(count <index && cur !=NULL)
	{
		cur=cur->next;
		count++;
	}
	if(count >index)
		printf("***û�����ѧ��***\n");
	else
	{
		printf("%s\t%s\t%f\t%f\t%f\t",cur->Id,cur->Name,cur->Chinese,cur->Math,cur->English);
		printf("%f\t%f\n",cur->AverageScore,cur->TotalScore);
	}	
}


//��ʾ����ѧ���ɼ�
void Student_Display(student *head)
{
	int count=0;
	int number=0;
	student *cur=head->next;
	printf("| ѧ�� |\t| ���� |\t| ���� |\t| ��ѧ |\t| Ӣ�� |\t| ƽ���� |\t| �ܷ� |\n");
	while(cur !=NULL)
	{
		printf("%s\t%s\t%f\t%f\t%f\t",cur->Id,cur->Name,cur->Chinese,cur->Math,cur->English);
		printf("%f\t%f\n",cur->AverageScore,cur->TotalScore);
		if(cur->Chinese >=60 && cur->English>=60 && cur->Math>=60)
			count++;
		cur=cur->next;
		number++;
	}
	PassRate=(float)count/number*100;
	printf("�����ʣ�%.1f%%\n",PassRate);
}

/*��ƽ��ֵ����*/
void Student_SortByAverage(student *head,student *phead)
{
	student *pcur=NULL;
	student *tmp=NULL;
	student *ptmp=NULL;

	student *cur=head->next;

	while(cur !=NULL)
	{
		pcur=cur;
		while(pcur !=NULL && pcur->AverageScore ==-1)
				pcur=pcur->next;
		if(pcur==NULL)
			break;
		tmp=pcur;
		while(pcur !=NULL)
		{	
			if(pcur->AverageScore > tmp->AverageScore && pcur->AverageScore !=-1)
			{
				tmp=pcur;
			}
			pcur=pcur->next;
		}

		if(tmp->AverageScore !=INT_MAX)
		{
			ptmp=(student *)malloc(sizeof(student));
			assert(ptmp !=NULL);

			strcpy(ptmp->Id,tmp->Id);
			strcpy(ptmp->Name,tmp->Name);

			ptmp->Chinese=tmp->Chinese;
			ptmp->English=tmp->English;
			ptmp->Math=tmp->Math;

			ptmp->AverageScore=tmp->AverageScore;
			ptmp->PassStudent=tmp->PassStudent;
			ptmp->TotalScore=tmp->TotalScore;

			ptmp->next=phead->next;
			phead->next=ptmp;

			tmp->AverageScore=-1;
		}
	}
	Student_Display(phead);
}

/*��ѧ����Ϣ���ļ�����*/
void IO_ReadInfo(student *head,FILE *path)
{
	student *cur=head->next;
	while(cur !=NULL)
	{
		if(fread(cur,sizeof(student),1,path) < 0)
		{
			printf("fread failed\n");
			break;
		}
		cur=cur->next;
	}
	printf(" |**************|\n");
	printf(" |*�������ݳɹ�*|\n");
	printf(" |**************|\n");
}
/*��ѧ����Ϣд���ļ�*/
void IO_WriteInfo(student *head,FILE *path)
{
	student *cur=head->next;
	while(cur !=NULL)
	{
		fprintf(path,"%s %s %f %f %f %f %f %d %s",\
			cur->Id,cur->Name,cur->Math,cur->English,cur->Chinese,\
			cur->TotalScore,cur->AverageScore,cur->PassStudent,"\n");
		cur=cur->next;
	}
	printf(" |**************|\n");
	printf(" |*д�����ݳɹ�*|\n");
	printf(" |**************|\n");
}

//��ʾ�б�
void ShowList()
{
	printf("**********************************************\n");
	printf("**��1������ѧ���ɼ� ��2����ʾȫ��ѧ����Ϣ   **\n");
	printf("**��3����ʾ����ѧ�� ��4��ɾ��ѧ����Ϣ       **\n");
	printf("**��5���޸�ѧ����Ϣ ��6����������ѯ         **\n");
	printf("**��7����ƽ��ֵ���� ��8�����ļ�����ѧ����Ϣ **\n");
	printf("**��9��д���ļ�     ��0���˳�ѧ������ϵͳ   **\n");
	printf("**********************************************\n");

}