

//编写函数 当输入一个小写字母a,输出一个大写字母Z,当输入一个小写b 输出一个大写字母Y


#include<string.h>
#include<stdlib.h>

#include<stdio.h>
int add(int a,int b)
{
	if(b==0)
		return a;
	int sum,ret;
	sum=a^b;
	ret=(a & b)<<1;
	return add(sum,ret);
}
void main()
{
	int a=4;
	int b=5;
	int sum=0;
	sum=add(a,b);
	printf("%d\n",sum);
}
/*void main()
{
	int a=5;
	int b=(a>>1)+1;
	printf("%d\n",b);
}
/*
void main()
{
	unsigned char a=0xA5;
	unsigned char b=~a>>4+1;
	printf("%d\n",b);
	
}
/*
void main()
{
	unsigned int a=0x12ff43aa;
//	unsigned int a=0xfffffff7;
	unsigned char i=(unsigned char)a;
	char *b=(char*)&a;
	printf("0x%x\n",a);
	printf("0x%x  0x%x\n",i,*b);
}
/*
void main()
{
	int i=0;
	int arr[]={6,7,8,9};
	int *p=arr;
	*p+++=123;
	printf("-->%d\n",*(p-1));
	printf("%d  %d\n",*p,*(++p));
}
/*void main()
{
	int a,x;
	for(a=0,x=0;a<=1 && !x++;)
	{
		a++;
	}
	printf("x=%d a=%d\n",x,a);
}
/*int i=1;
void main()
{
	int i=i;
	printf("%d\n",i);
}
/*
void change(char *str,char *value)
{
	int a=strlen(str);
	char *p=&str[a-1];
	char *q=(char*)malloc(sizeof(char));
	char *ret=(char*)malloc(sizeof(char));
	while(*p!=*str)
	{
		q=p;
		while(*p!=' ' && *p!=*str)
		{
			p--;
		}
		ret=p;
		while(p!=q)
		{
			*value=*p;
			p++;
			value++;
		}
		*value++=*p;
		*value++=' ';
		if(*ret==*str)
			break;
		p=--ret;
	}	
	*(value)='\0';
}

void main()
{
	char str[]="ABCDE am student";
	char *value=(char*)malloc(strlen(str)+1);
	change(str,value);
	printf(" %s\n",str);
	printf(" %s\n",value);
}
/*
#define d 3.1;
typedef struct Node
{
	int a[100];
}Node;

typedef struct pNode
{
	int b[100];
}pNode;


void change(char *str,Node *arr,pNode *parr)
{
	int length=strlen(str);
	char *left=str;
	char *rith;
	int i=0;
	int count=0;
	int lag=0;
	int pcount=0;
	int plag=0;

	while(*str!='\0')
	{
		while(1)
		{
			if(*left>='a' && *left<='z' || *left>='A' && *left<='Z')
			{
//				arr.a[i++]=*left++;
				count++;
			}
			else 
			{
				lag++;
				break;
			}
		}
		while(1)
		{
			if(*rith>='a' && *rith<='z' || *rith>='A' && *rith<='Z')
			{
//				parr.b[i++]=*rith--;
				pcount++;
			}
			else 
			{
				plag++;
				break;
			}
		}
	}
}
void main()
{
	char str[]="student a am i";
//	sort(str);
	printf("st=%s\n",str);
}

/*
#include<stdio.h>
#include<string.h>
void sort(char *st)
{
	char *left=st;
	char *right;
	char temp;
	int i=0;
	int count=0;
	while(*st!='\0')
	{
		count++;
		st++;
	}
	right=--st;
	count=count/2;
	while(i<count)
	{
		temp=*left;
		*left=*right;
		*right=temp;
		left++;
		right--;
		i++;
	}
}
void main()
{
	char st[]="student a am i";
	sort(st);
	printf("st=%s\n",st);
}


/*
//统计一个无符号整数的二进制数中的1的个数
#include<stdio.h>
void main()
{
	unsigned int Number;
	unsigned int count=0;
	unsigned int data=1;
	printf("请输入一个正整数：");
	scanf("%d",&Number);
	for(int i=0;i<32;i++)
	{
		if((Number & data)==1)
			count++;
		Number>>=1;
	}
	printf("count=%d\n",count);
}

/*#include<stdio.h>
void main()
{
	int y=0;
	int i=0;
	for(i=2;i<=20;i=i+2)
	{
		y+=3;
	}
	printf("y=%d\n",y);
}
*/