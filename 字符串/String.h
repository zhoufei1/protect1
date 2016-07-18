#pragma once

#include<iostream.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_SIZE 20

typedef char SString[MAX_STRING_SIZE+1];


void Show();   //�˵���ʾ
void StrAssign(SString T, char *str);//��ʼ���ַ���
void PrintString(char T[]); //��ʾ�ַ���
int Length(SString s);  //���ַ�������
bool StrEmpty(SString S);//�п�
void StrCopy(SString T, SString S);//�����ַ���
void DestroyString(SString S);  //�ݻ��ַ���
void StrDelete(SString T, int pos, int len);  //��λ�úͳ���ɾ���ַ���
void Replace(SString T, SString P, SString V,int pos);//��λ���滻�ַ���
int Index(SString T, int pos, SString P);//��λ��ƥ���ַ���
void StrInsert(SString D, int pos, SString T);//��λ�ò����ַ���
void SubString(SString D, SString S, int pos, int len);//��λ�û�ȡ�ַ���
void ClearString(SString S);   //�����ַ���
int StrCompare(SString T, SString S);//�Ƚ��ַ���
void StringConcat(SString T, SString s1, SString s2);//�����ַ���

