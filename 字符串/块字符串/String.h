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

void Show();   //菜单显示
void InitHString(LString *T);//初始化
void StrAssign(LString *T, char *str);//初始化链表
void PrintString(LString *T); //显示字符串
int GetLength(LString *T);  //求字符串长度
bool StrEmpty(LString *S);//判空
//bool STrFull(LString *S);//判满不需要
//void StrCopy(LString *T, LString *S);//复制字符串
void DestroyString(LString *T);  //摧毁字符串
void StrDelete(LString *T, int pos);  //按位置和长度删除字符串
void Replace(LString *T, LString *D,int pos);//按位置替换字符串
int Index(LString *T, int pos, LString *P);//按位置匹配字符串
void StrInsert(LString *D, int pos, LString *T);//按位置插入字符串
//int SubString(LString *D,LString *S, int pos, int len);//按位置获取字符串
void ClearString(LString *T);   //清理字符串
int StrCompare(LString *T, LString *S);//比较字符串
void StringConcat(LString *T, LString *S);//链接字符串

