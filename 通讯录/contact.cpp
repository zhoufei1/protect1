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
    printf("请输入名字：");
   // scanf("%s\t",pcon->dhb[pcon->count].name);  "%s "后面不要有任何空格符  下面一样

	pcon->dhb[pcon->count].name = (char *)malloc(sizeof(char));//在这里面开辟空间，
													//就相当于每次用之前都得开辟，下面一样
	scanf("%s",pcon->dhb[pcon->count].name);
    printf("请输入年龄：");
	pcon->dhb[pcon->count].age = (int)malloc(sizeof(char));
    scanf("%d",&(pcon->dhb[pcon->count].age));
    printf("请输入性别：");
	pcon->dhb[pcon->count].sex = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].sex);
    printf("请输入电话：");
	pcon->dhb[pcon->count].tele = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].tele);
    printf("请输入地址：");
	pcon->dhb[pcon->count].addr = (char *)malloc(sizeof(char));
    scanf("%s",pcon->dhb[pcon->count].addr);
	pcon->count++;
    printf("添加成功\n");
 }
  else
  {
      printf("电话本已满！"); 
      return;  
  }
}

void del_peo(Pcon *pcon)
{  
   int ret;
   char *name=(char*)malloc(sizeof(char)+1);//要先开辟空间才能输入，你是怎么学的？？
   printf("请输入要删除人的名字:");
   scanf("%s",name);
   ret=find(name,pcon);
   if(ret==-1)
   {
     printf("要删除的人不存在!");
	 return;
   }
   else
   {
     int index=0;
     for(index=ret;index<pcon->count;index++)
	 {
	   pcon->dhb[index]=pcon->dhb[index+1];
	 }
	 pcon->count--;//删完后就必需减一
   }
   //pcon->count--;这是你之前的
}
void search_peo(Pcon *pcon)
{
    int ret;
   char *name=(char*)malloc(sizeof(char)+1);//要先开辟空间才能输入，你是怎么学的？？
   printf("请输入要查找人的名字:");
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
   char *name=(char*)malloc(sizeof(char)+1);//要先开辟空间才能输入，你是怎么学的？？
   printf("请输入要修改人的名字:");
   scanf("%s",name);
   ret=find(name,pcon);
   if(ret!=-1)
  {
   printf("请输入名字:");
   scanf("%s",pcon->dhb[ret].name);
   printf("请输入性别:");
   scanf("%s",pcon->dhb[ret].sex);
   printf("请输入年龄:");
   scanf("%d",&(pcon->dhb[ret]).age);
   printf("请输入电话:");
   scanf("%s",(pcon->dhb[ret]).tele);
   printf("请输入地址:");
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