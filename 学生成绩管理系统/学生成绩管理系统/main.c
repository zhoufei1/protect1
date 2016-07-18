
#include "student.h"


void main()
{
	char ch='0';
	int index=0;
	char id[ID_SIZE];
	student students;
	student phead;

	FILE *output=fopen("output.txt","w+");
	FILE *input=fopen("input.txt","r");	
	
	if(input==NULL)
	{
		printf("��ʧ��input\n");
		exit(1);
	}
	if(input==NULL)
	{
		printf("��ʧ��output\n");
		exit(1);
	}
	phead.next=NULL;

	InitStudent(&students);

	
	while(1)
	{
		ShowList();
		printf("��ѡ��");
		ch=getchar();
		switch(ch)
		{
		case '1':
			Student_Insert(&students);
			break;
		case '2':
			Student_Display(&students);
			break;
		case '3':
			{
				printf("��������Ҫ���Ҷ��ٸ�ѧ����");
				scanf("%d",&index);
				Student_DisplaySingle(&students,index);
			}
			break;
		case '4':
			{
				printf("��������Ҫɾ����ѧ�ţ�");
				scanf("%s",id);
				Student_Delete(&students,id);
			}
			break;
		case '5':
			Student_Modify(&students);
			break;
		case '6':
			{
				printf("��������Ҫ����ѧ��������");
				scanf("%s",id);
				Student_Select(&students,id);
			}
			break;
		case '7':
			Student_SortByAverage(&students,&phead);
			break;
		case '8':
			{
				IO_ReadInfo(&students,output);
				fclose(output);
			}
			break;
		case '9':
			{
				IO_WriteInfo(&students,output);
				fclose(output);
			}
			break;
		case '0':
			{
				printf("��ӭʹ��ѧ������ɼ�ϵͳ\n");
				exit(1);
			}
		default:
			break;
		}
		getchar();
	}
}