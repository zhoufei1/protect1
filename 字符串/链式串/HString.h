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


void Show();   //菜单显示
void InitHString(HString *T);//初始化
void StrAssign(HString *T, char *str);//初始化字符串
void PrintString(HString *T); //显示字符串
int Length(HString *S);  //求字符串长度
bool StrEmpty(HString *S);//判空
bool STrFull(HString *S);//判满
void StrCopy(HString *T, HString *S);//复制字符串
void DestroyString(HString *S);  //摧毁字符串
int StrDelete(HString *T, int pos, int len);  //按位置和长度删除字符串
void Replace(HString *T, HString *P, HString *V,int pos);//按位置替换字符串
int Index(HString *T, int pos, HString *P);//按位置匹配字符串
void StrInsert(HString *D, int pos, HString *T);//按位置插入字符串
int SubString(HString *D,HString *S, int pos, int len);//按位置获取字符串
void ClearString(HString *S);   //清理字符串
int StrCompare(HString *T, HString *S);//比较字符串
void StringConcat(HString *T, HString *s1,HString *s2);//链接字符串

