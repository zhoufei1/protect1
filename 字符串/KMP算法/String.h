#pragma once

#include<iostream.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 255
typedef struct HString
{
	char *ch;
	int length;
}HString;

int Index(HString *T, int pos, HString *P)//按位置匹配字符串  ***KMP算法**
{
	if(T->ch==NULL || P->ch==NULL)
		return 0;

	int TLength=strlen(T->ch);
	int PLength=strlen(P->ch);
	if(pos+PLength>TLength)
		return -1;

	char *TRet=&(T->ch[pos]);
	char *PRet=P->ch;

	int i=0;
	int j=0;

	while(TRet[i]!='\0')
	{
		while(TRet[i]==PRet[j] && PRet[j]!='\0')//开始匹配
		{
			i++;
			j++; 
		}
		if(PRet[j]=='\0')//如果满足 说明匹配成功，直接跳出循环
				break;
		while(j!=0 && TRet[i]!=PRet[j])//让j回退
		{
			j--;  
		}
		if(j==0 && TRet[i]!=PRet[j])//直到j回退到零都不能匹配时 i++即TRet[i]移动到下一个继续比较
		{
			i++;
		}	
	}
	if( PRet[j]=='\0')//比较成功 i-j回到匹配成功的下标 再加上pos就能得到字符串匹配成功的下标
		return (i-j+pos);
	else
		return -1;
}
void InitHString(HString *T)//初始化
{
	T->ch=(char*)malloc(sizeof(char)*SIZE);
	T->length=0;
}
int StrAssign(HString *T, char *str)//初始化字符串
{
	if(str==NULL)
		return -1;
	char *ch=T->ch;
	if(T->length>=SIZE)
	{
		return -1;
	}
	while((*ch++=*str++)!='\0')//efg
	{
		T->length++;
	}
	return 0;
}
void PrintString(HString *T) //显示字符串
{
	char *ch=T->ch;
	while(*ch!='\0')
	{
		cout<<*ch++;
	}
	cout<<endl;
}