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


void Show();   //�˵���ʾ
void InitHString(HString *T);//��ʼ��
void StrAssign(HString *T, char *str);//��ʼ���ַ���
void PrintString(HString *T); //��ʾ�ַ���
int Length(HString *S);  //���ַ�������
bool StrEmpty(HString *S);//�п�
bool STrFull(HString *S);//����
void StrCopy(HString *T, HString *S);//�����ַ���
void DestroyString(HString *S);  //�ݻ��ַ���
int StrDelete(HString *T, int pos, int len);  //��λ�úͳ���ɾ���ַ���
void Replace(HString *T, HString *P, HString *V,int pos);//��λ���滻�ַ���
int Index(HString *T, int pos, HString *P);//��λ��ƥ���ַ���
void StrInsert(HString *D, int pos, HString *T);//��λ�ò����ַ���
int SubString(HString *D,HString *S, int pos, int len);//��λ�û�ȡ�ַ���
void ClearString(HString *S);   //�����ַ���
int StrCompare(HString *T, HString *S);//�Ƚ��ַ���
void StringConcat(HString *T, HString *s1,HString *s2);//�����ַ���

