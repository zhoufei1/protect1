#include<iostream.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h> 
#include<stdio.h>
typedef struct Term
{
	int cole;
	int expn;
	bool operator==(const  Term &it) const
	{
		return (expn == it.expn);
	}
	bool operator!=(const Term &it) const
	{
		return !(*this == it);
	}
}Term;

typedef Term ElemType;
typedef unsigned int u_int;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*NodePtr;

typedef struct
{
	NodePtr head;
	u_int size;
}List;
NodePtr _Buynode()
{
	NodePtr s = (NodePtr)malloc(sizeof(Node));
	if(NULL == s) exit(1);
	s->next = NULL;
	return s;
}
void _Freenode(NodePtr q)
{
	free(q);
}
void InitList(List &it)//c99
{
	it.head = _Buynode();
	it.size = 0;
}
void Push_Back(List &it,ElemType x)
{
	NodePtr p = it.head;
	while(p->next != NULL)
	{
		p = p->next;
	}
	NodePtr s = _Buynode();
	s->data = x;
	s->next = p->next;
	p->next = s;
	it.size+=1;
}
void Push_Front(List &it,ElemType x)
{
	NodePtr s = _Buynode();
	s->data = x;
	s->next = it.head->next;
	it.head->next = s;
	it.size+=1;
}

NodePtr FindValue(List &it,ElemType x)
{ 
	NodePtr p = it.head->next;
	while(p != NULL && p->data != x)
	{
		p = p->next;
	}
	return p;
}
NodePtr FindValuePrev(List &it,ElemType x)
{// not NULL;
	NodePtr p = it.head;
	while(p != NULL && p->next != NULL && p->next->data != x)
	{
		p = p->next;
	}
	if(p->next == NULL) return NULL;
	else return p;
}
void RemoveList(List &it,ElemType x)
{
	NodePtr p = FindValuePrev(it,x);
	if(p == NULL) return ;
	NodePtr q = p->next;
	p->next = q->next;
	_Freenode(q);
	it.size-=1;
}
void RemoveList_All(List &it,ElemType x)
{

}
void PrintList(List &it)
{
	NodePtr p = it.head->next;
	while(p != NULL)
	{
		printf("%d*X%d  ",p->data.cole,p->data.expn);
		p = p->next;
	}
	printf("\n");
}

void main()
{
	ElemType ar[]={7,0,3,1,9,8,5,17};
	ElemType item;
	NodePtr p=NULL;
	int n = sizeof(ar)/sizeof(ar[0]);
	List mylist;
	InitList(mylist);
	for(int i = 0;i<n;++i)
	{
		Push_Back(mylist,ar[i]);
	}

	PrintList(mylist);


}