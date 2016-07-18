#include "contact.h"

void menu()
{
	printf("************************\n");
	printf("*   1>add      2>del   *\n");
	printf("*   3>search   4>modify*\n");
	printf("*   5>show     6>clear *\n");
	printf("************************\n");
}


int find(char *p, Pcon *pcon)
{
  int i=0;
  for(i=0;i<pcon->count;i++)
   {
     if(strcmp(p,(pcon->dhb[i].name))==0)
          return i;
   }
  return -1;
}
void add_peo(Pcon *pcon)
{
 if(pcon->count<1000)
  {
    printf("���������֣�");
   // scanf("%s\t",pcon->dhb[pcon->count].name);  "%s "���治Ҫ���κοո��  ����һ��

	pcon->dhb[pcon->count].name = (char *)malloc(sizeof(char));//�������濪�ٿռ䣬
													//���൱��ÿ����֮ǰ���ÿ��٣�����һ��
	scanf("%s",pcon->dhb[pcon->count].name);
    printf("���������䣺");
	pcon->dhb[pcon->count].age = (int)malloc(sizeof(char));
    scanf("%d",&(pcon->dhb[pcon->count].age));
    printf("�������Ա�");
	pcon->dhb[pcon->count].sex = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].sex);
    printf("������绰��");
	pcon->dhb[pcon->count].tele = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].tele);
    printf("�������ַ��");
	pcon->dhb[pcon->count].addr = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].addr);
	pcon->count++;
    printf("��ӳɹ�\n");
 }
  else
  {
      printf("�绰��������"); 
      return;  
  }
}

void del_peo(Pcon *pcon)
{  
   int ret;
   char *name=(char*)malloc(sizeof(char)+1);//Ҫ�ȿ��ٿռ�������룬������ôѧ�ģ���
   printf("������Ҫɾ���˵�����:");
   scanf("%s",name);
   ret=find(name,pcon);
   if(ret==-1)
   {
     printf("Ҫɾ�����˲�����!");
	 return;
   }
   else
   {
     int index=0;
     for(index=ret;index<pcon->count;index++)
	 {
	   pcon->dhb[index]=pcon->dhb[index+1];
	 }
	 pcon->count--;//ɾ���ͱ����һ
   }
   //pcon->count--;������֮ǰ��
}
void search_peo(Pcon *pcon)
{
    int ret;
   char *name=(char*)malloc(sizeof(char)+1);//Ҫ�ȿ��ٿռ�������룬������ôѧ�ģ���
   printf("������Ҫ�����˵�����:");
   scanf("%s",name);
   ret=find(name,pcon);
   if(ret!=-1)
  {
   printf("%12s ",pcon->dhb[ret].name);
   printf("%12s ",pcon->dhb[ret].sex);
   printf("%12d ",pcon->dhb[ret].age);
   printf("%12s ",pcon->dhb[ret].tele);
   printf("%12s ",pcon->dhb[ret].addr);
  }
}
void modify_peo(Pcon *pcon)
{
   int ret;
   char *name=(char*)malloc(sizeof(char)+1);//Ҫ�ȿ��ٿռ�������룬������ôѧ�ģ���
   printf("������Ҫ�޸��˵�����:");
   scanf("%s",name);
   ret=find(name,pcon);
   if(ret!=-1)
  {
   printf("����������:");
   scanf("%s",pcon->dhb[ret].name);
   printf("�������Ա�:");
   scanf("%s",pcon->dhb[ret].sex);
   printf("����������:");
   scanf("%d",&(pcon->dhb[ret]).age);
   printf("������绰:");
   scanf("%s",(pcon->dhb[ret]).tele);
   printf("�������ַ:");
   scanf("%s",(pcon->dhb[ret]).addr);
  }
}
void show_peo(Pcon *pcon)
{
	int i=0;
   for(i=0;i<pcon->count;i++)
   {
      printf("%8s",pcon->dhb[i].name);
	  printf("%8s",pcon->dhb[i].sex);
	  printf("%8d",pcon->dhb[i].age);
	  printf("%8s",pcon->dhb[i].tele);
	  printf("%8s\n",pcon->dhb[i].addr);
   }
   
}
void clear_peo(Pcon *pcon)
{
   pcon->count=0;
}