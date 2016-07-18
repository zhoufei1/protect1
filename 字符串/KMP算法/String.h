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

int Index(HString *T, int pos, HString *P)//��λ��ƥ���ַ���  ***KMP�㷨**
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
		while(TRet[i]==PRet[j] && PRet[j]!='\0')//��ʼƥ��
		{
			i++;
			j++; 
		}
		if(PRet[j]=='\0')//������� ˵��ƥ��ɹ���ֱ������ѭ��
				break;
		while(j!=0 && TRet[i]!=PRet[j])//��j����
		{
			j--;  
		}
		if(j==0 && TRet[i]!=PRet[j])//ֱ��j���˵��㶼����ƥ��ʱ i++��TRet[i]�ƶ�����һ�������Ƚ�
		{
			i++;
		}	
	}
	if( PRet[j]=='\0')//�Ƚϳɹ� i-j�ص�ƥ��ɹ����±� �ټ���pos���ܵõ��ַ���ƥ��ɹ����±�
		return (i-j+pos);
	else
		return -1;
}
void InitHString(HString *T)//��ʼ��
{
	T->ch=(char*)malloc(sizeof(char)*SIZE);
	T->length=0;
}
int StrAssign(HString *T, char *str)//��ʼ���ַ���
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
void PrintString(HString *T) //��ʾ�ַ���
{
	char *ch=T->ch;
	while(*ch!='\0')
	{
		cout<<*ch++;
	}
	cout<<endl;
}