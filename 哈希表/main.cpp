#include<iostream>
using namespace std;

#include"hh.h"

AA z;
void main()
{
	//AA x;
	cout<<"ennen"<<endl;
}
/*#define L 3
#define N 7
#define ElemType int

typedef struct hash_node
{
	ElemType data[L];
	struct hash_node *link;
}hash_node;

typedef hash_node* hash_table[N];


void main()
{
	//int a[10];
	int *p;
	int *arr[10]=&p;
	for(int i=0;i<10;++i)
	{
		arr[i]=new int(i+10);
	}
//	hash_table ht;
//	init(ht);
}

/*int hash(ElemType x)
{
	return x%N;
}

void init(hash_table &ht)
{
	for(int i=0;i<N;++i)
	{
		ht[i]=new hash_node;////????
		for(int j=0;j<L;++j)
		{
			ht[i]->data[j]=0;
		}
		ht[i]->link=NULL;
	}
}

int hash_data(hash_table &ht,ElemType x)
{
	int index=hash(x);

	hash_node* p=ht[index];
	while(p->link!=NULL)
			p=p->link;

	for(int i=0;i<L;++i)
	{
		if(p->data[i]==0)
			return i;
	}
	return -1;
}

void InitNode(hash_node* Node)
{
	for(int k=0;k<L;++k)
		Node->data[k]=0;
	Node->link=NULL;
}
void inithashtable(hash_table &ht,ElemType x)
{
	int i=hash(x);
	hash_node* p=ht[i];
	int index=hash_data(ht,x);

	if(index==-1)
	{
		hash_node *Node=new hash_node;////????
		InitNode(Node);
	
		while(p->link!=NULL)
			p=p->link;
		p->link=Node;
		p=Node;
		++index;
	}
	while(p->link!=NULL)
		p=p->link;
	p->data[index]=x;
}
void show(hash_table &ht)
{
	hash_node *p=NULL;
	for(int i=0;i<N;++i) 
	{
		cout<<" �� "<<i<<" ��: ";
		p=ht[i];
		while(p!=NULL)
		{
			for(int j=0;j<L;++j)
				cout<<p->data[j]<<"-->";
			p=p->link;
		}
		cout<<"NULL"<<endl;
	}
}




void init(hash_table &ht)
{
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<L;++j)
		{
			ht[i].data[j]=0;
		}
		ht[i].link=NULL;
	}
}
void main()
{
	hash_table ht;
	init(ht);
	int arr[]={1,8,15,23,44,66,77,99,9,8,5,6,3,700,770,777,777777777,777,7777};
	for(int i=0;i<sizeof(arr)/sizeof(*arr);++i)
	{
//		inithashtable(ht,arr[i]);
	}
//	show(ht);
}*/