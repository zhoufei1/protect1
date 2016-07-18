#pragma once

#include<iostream>
using namespace std;
#include<stack>

template<class Type>
class BinTree;

template<class Type>
class BinTreeNode;
typedef enum{L,R}Tag_Type;
template<class Type>
class Node
{
public:
	Tag_Type  Falg;
	BinTreeNode<Type> *Newptr;
};

template<class Type>
class BinTreeNode
{
	friend class BinTree<Type>;
private:
	Type data;
	BinTreeNode<Type> *leftChild;
	BinTreeNode<Type> *rightChild;
public:
	BinTreeNode():data(Type()),leftChild(NULL),rightChild(NULL)
	{}
	BinTreeNode(const Type &d,BinTreeNode<Type> *left=NULL,BinTreeNode<Type> *right=NULL)
		:data(d),leftChild(left),rightChild(right)
	{}
};

template<class Type>
class BinTree
{
private:
	Type value;
	BinTreeNode<Type>*root;
protected:
	void CreateBinTree(BinTreeNode<Type> *&t,const char *&str)
	{
		if(*str==value)
			t=NULL;
		else
		{
			t=new BinTreeNode<Type> (*str);
			CreateBinTree(t->leftChild,++str);
			CreateBinTree(t->rightChild,++str);
		}
	}
	void PreOrder(BinTreeNode<Type> *t)//前序遍历
	{
		if(t==NULL)
			return;
		stack<BinTreeNode<Type>* > r;
		BinTreeNode<Type> *p;
		r.push(t);
		while(!r.empty())
		{
			p=r.top();
			r.pop();
			cout<<p->data<<" ";
			if(p->rightChild !=NULL)
				r.push(p->rightChild);
			if(p->leftChild !=NULL)
				r.push(p->leftChild);
		}
	}
	void InOrder(BinTreeNode<Type> *t)//中序遍历
	{
		if(t==NULL)
			return;
		stack<BinTreeNode<Type> *> r;
		BinTreeNode<Type> *p;
		
		r.push(t);
		while(!r.empty())
		{
			while(t->leftChild !=NULL)
			{
				r.push(t->leftChild);
				t=t->leftChild;
			}
			p=r.top();
			r.pop();
			cout<<p->data<<" ";
			if(p->rightChild !=NULL)
			{
				t=p->rightChild;
				r.push(t);
			}
		}
	}
	void PostOrder(BinTreeNode<Type> *t)//后序遍历
	{
		if(t==NULL)
			return;
		stack< Node<Type> > r;
		Node<Type> node;
		node.Newptr=t;
		node.Falg=L;
		r.push(node);
		while(!r.empty())
		{
			while(t->leftChild !=NULL)
			{
				node.Newptr=t->leftChild;
				node.Falg=L;
				r.push(node);
				t=t->leftChild;
			}
			bool falg=true;
			while(falg && !r.empty())
			{
				node=r.top();
				r.pop();
				switch(node.Falg)
				{
				case L:
					node.Falg=R;
					falg=false;
					t=node.Newptr;
					r.push(node);
					break;
				case R:
					cout<<node.Newptr->data<<" ";
					break;
				}
				if(t->rightChild==NULL)
				{
					node.Falg=R;
					falg=true;
				}
			}
			if(t->rightChild !=NULL)
			{
				node.Newptr=t->rightChild;
				node.Falg=L;
				r.push(node);
				t=t->rightChild;
			}
		}
	}
	void CreatBinTree_Pre(BinTreeNode<Type> *&t,const char *VLR,const char *LVR,int n)
	{
		if(0==n)
			return;
		int k=0;             //A B D E F C G  -->VLR
		while(*VLR != LVR[k])//D B F E A C G  -->LVR
			k++;
		t=new BinTreeNode<Type> (*VLR);
		CreatBinTree_Pre(t->leftChild,VLR+1,LVR,k);
		CreatBinTree_Pre(t->rightChild,VLR+k+1,LVR+k+1,n-k-1);
	}


	void CreatBinTree_Post(BinTreeNode<Type> *&t,const char *LVR,const char *LRV,int n)
	{
		if(n==0)
			return; //D B F E A C G  LVR 中
		int k=0;   // D F E B G C A  LRV 后
		while(LRV[n-1] !=LVR[k])
			k++;
		t=new BinTreeNode<Type> (LRV[n-1]);
		CreatBinTree_Post(t->leftChild,LVR,LRV,k);
		CreatBinTree_Post(t->rightChild,LVR+k+1,LRV+n,n-k-1);
	}
public:
	void CreatBinTree_Post(const char *LVR,const char *LRV,int n)
	{
		CreatBinTree_Post(root,LVR,LRV,n);
	}
	void CreatBinTree_Pre(const char *VLR,const char *LVR,int n)
	{
		CreatBinTree_Pre(root,VLR,LVR,n);
	}
	void PreOrder()//前序遍历
	{
		PreOrder(root);
	}
	void InOrder()//中序遍历
	{
		InOrder(root);
	}
	void PostOrder()//后序遍历
	{
		PostOrder(root);
	}
	BinTree():value(Type()),root(NULL)
	{}
	BinTree(const Type &v):value(v),root(NULL)
	{}
	void CreateBinTree(const char *str)
	{
		CreateBinTree(root, str);
	}
	
};