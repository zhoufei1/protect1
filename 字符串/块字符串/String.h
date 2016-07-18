#pragma once

#include<iostream.h>
#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define SIZE 5
typedef struct Chunk
{
	char ch[SIZE];
	struct Chunk *next;
}Chunk;

typedef struct
{
	Chunk *head,*tail;
	int length;
}LString;

void Show();   //�˵���ʾ
void InitHString(LString *T);//��ʼ��
void StrAssign(LString *T, char *str);//��ʼ������
void PrintString(LString *T); //��ʾ�ַ���
int GetLength(LString *T);  //���ַ�������
bool StrEmpty(LString *S);//�п�
//bool STrFull(LString *S);//��������Ҫ
//void StrCopy(LString *T, LString *S);//�����ַ���
void DestroyString(LString *T);  //�ݻ��ַ���
void StrDelete(LString *T, int pos);  //��λ�úͳ���ɾ���ַ���
void Replace(LString *T, LString *D,int pos);//��λ���滻�ַ���
int Index(LString *T, int pos, LString *P);//��λ��ƥ���ַ���
void StrInsert(LString *D, int pos, LString *T);//��λ�ò����ַ���
//int SubString(LString *D,LString *S, int pos, int len);//��λ�û�ȡ�ַ���
void ClearString(LString *T);   //�����ַ���
int StrCompare(LString *T, LString *S);//�Ƚ��ַ���
void StringConcat(LString *T, LString *S);//�����ַ���

