#pragma once

#include<iostream.h>
#include<assert.h>
#include<string.h>

#define MAX_STRING_SIZE 20

typedef char SString[MAX_STRING_SIZE+1];


void Show();   //菜单显示
void StrAssign(SString T, char *str);//初始化字符串
void PrintString(char T[]); //显示字符串
int Length(SString s);  //求字符串长度
bool StrEmpty(SString S);//判空
void StrCopy(SString T, SString S);//复制字符串
void DestroyString(SString S);  //摧毁字符串
void StrDelete(SString T, int pos, int len);  //按位置和长度删除字符串
void Replace(SString T, SString P, SString V,int pos);//按位置替换字符串
int Index(SString T, int pos, SString P);//按位置匹配字符串
void StrInsert(SString D, int pos, SString T);//按位置插入字符串
void SubString(SString D, SString S, int pos, int len);//按位置获取字符串
void ClearString(SString S);   //清理字符串
int StrCompare(SString T, SString S);//比较字符串
void StringConcat(SString T, SString s1, SString s2);//链接字符串

