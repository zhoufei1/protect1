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
	char Id[ID_SIZE];  //学生学号
	char Name[NAME_SIZE]; //学生姓名
	float Math;   //数学
	float English; //英语
	float Chinese;  //语文
	float TotalScore; //总分
	float AverageScore; //平均分
	int PassStudent;  //及格人数
	struct student *next;
}student;

static float PassRate=0.0;   //及格率

//初始化学生信息
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

//插入学生成绩
void Student_Insert(student *head)
{
	int flag=0;
	student *cur=head;
	student *tmp=(student *)malloc(sizeof(student));
	tmp->next=NULL;
	assert(tmp !=NULL);

	printf("请输入学号：");
	scanf("%s",tmp->Id);
	printf("请输入姓名：");
	scanf("%s",tmp->Name);
	printf("请输入数学成绩：");
	scanf("%f",&tmp->Math);
	printf("请输入英语成绩：");
	scanf("%f",&tmp->English);
	printf("请输入语文成绩：");
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

	printf("\t学生及格人数：%d\n",flag);
	
	while(cur->next !=NULL)
		cur=cur->next;
	cur->next=tmp;
}
/*删除学生信息*/
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
			printf("***删除成功***\n");
			return;
		}
		cur=cur->next;
	}
	printf("***删除失败***\n");
}
/*修改学生信息*/
void Student_Modify(student *head)
{
	char number[ID_SIZE];
	int flag=0;
	student *cur=head->next;
	assert(cur !=NULL);
	printf("\t请输入学生学号：");
	scanf("%s",number);
	printf("***开始查找***\n");
	while(cur !=NULL)
	{
		if(strcmp(cur->Id,number)==0)
		{
			printf("请输入准备修改的语文成绩：");
			scanf("%f",&cur->Chinese);
			printf("请输入准备修改的数学成绩：");
			scanf("%f",&cur->Math);
			printf("请输入准备修改的英语成绩：");
			scanf("%f",&cur->English);
			flag=1;
			break;
		}
		cur->next;
	}
	if(flag)
		printf("***修改成功***\n");
	else
		printf("***修改失败***\n");
}
/*按姓名查询*/
void Student_Select(student *head,char *name)
{
	student *cur=head->next;
	while(cur!=NULL)
	{
		if(strcmp(cur->Name,name)==0)
		{
			printf("***存在这个学生***\n");
			return;
		}
		cur=cur->next;
	}
	printf("***按姓名查找失败***\n");
}
/*显示单条学生记录*/
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
		printf("***没有这个学生***\n");
	else
	{
		printf("%s\t%s\t%f\t%f\t%f\t",cur->Id,cur->Name,cur->Chinese,cur->Math,cur->English);
		printf("%f\t%f\n",cur->AverageScore,cur->TotalScore);
	}	
}


//显示所有学生成绩
void Student_Display(student *head)
{
	int count=0;
	int number=0;
	student *cur=head->next;
	printf("| 学号 |\t| 姓名 |\t| 语文 |\t| 数学 |\t| 英语 |\t| 平均分 |\t| 总分 |\n");
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
	printf("及格率：%.1f%%\n",PassRate);
}

/*按平均值排序*/
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

/*将学生信息从文件读出*/
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
	printf(" |*读入数据成功*|\n");
	printf(" |**************|\n");
}
/*将学生信息写入文件*/
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
	printf(" |*写入数据成功*|\n");
	printf(" |**************|\n");
}

//显示列表
void ShowList()
{
	printf("**********************************************\n");
	printf("**【1】插入学生成绩 【2】显示全部学生信息   **\n");
	printf("**【3】显示单个学生 【4】删除学生信息       **\n");
	printf("**【5】修改学生信息 【6】按姓名查询         **\n");
	printf("**【7】按平均值排序 【8】从文件读出学生信息 **\n");
	printf("**【9】写入文件     【0】退出学生管理系统   **\n");
	printf("**********************************************\n");

}