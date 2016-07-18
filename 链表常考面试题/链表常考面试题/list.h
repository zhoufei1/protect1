#include <iostream>
using namespace std;
#include <assert.h>

struct node
{
	int value;
	struct node *next;
	node(int key=0):value(key){}
};
//无头的单链表
void init(node *&head)
{
	if(NULL==head)
		head=NULL;
}
//两种情况，head==NULL或者没有找到都返回NULL
//否则返回找到的节点
node* find(node *head,int key)
{
	node *cur=head;
	while(cur !=NULL && cur->value !=key)
		cur=cur->next;
	return cur;
}
void push_back(node *&head,int key)
{
	if(head==NULL)
	{
		head=new node(key);
		head->next=NULL;
	}else
	{
		node *tmp=new node(key);
		tmp->next=NULL;
		node *cur=head;
		while(cur->next !=NULL && cur->next->value !=key)
			cur=cur->next;
		tmp->next=cur->next;
		cur->next=tmp;
	}
}
void insert(node *&head,int key)
{
	node *cur=find(head,key);
	if(cur==NULL)//会出现head==NULL或者没有找到
		push_back(head,key);
	else
	{
		node *tmp=new node(key);
		tmp->next=NULL;
		tmp->next=cur->next;
		cur->next=tmp;
	}
}
void show(node *head)
{
	node *cur=head;
	while(cur !=NULL)
	{
		cout<<cur->value<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
//翻转
void reserve(node *&head)
{
	node *cur=head;
	head=NULL;
	while(cur !=NULL)
	{
		node *tmp=cur;
		cur=cur->next;
		//
		tmp->next=head;
		head=tmp;
	}
}
//删除
bool remove(node *&head,int key)
{
	if(head==NULL)
		return false;
	if(head->value==key)
	{
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}else
		{
			node *del=head;
			head=head->next;
			delete del;
			del=NULL;
		}
		return true;
	}
	///接下来就key就不会和head->value相等，所以就可以从head->next->value开始比较
	node *cur=head;
	while(cur->next !=NULL && cur->next->value !=key)
		cur=cur->next;
	if(cur->next==NULL)
		return false;
	node *del=cur->next;
	cur->next=del->next;
	delete del;
	del=NULL;
	return true;
}
//合并两个有序链表
node* merger(node *&des,node *&src)
{
	if(des==NULL)
		return src;
	if(src==NULL)
		return des;
	node *head=new node(0);
	node *cur=head;

	while(des !=NULL && src !=NULL)
	{
		if(des->value >src->value)
		{
			cur->next=src;
			src=src->next;
		}
		else
		{
			cur->next=des;
			des=des->next;
		}
		cur=cur->next;
	}
	if(des==NULL)
		cur->next=src;
	else
		cur->next=des;
	cur=head->next;
	delete head;
	head=NULL;
	return cur;
}
//判断是否有环
bool IsRing(node *head)
{
	if(head==NULL || head->next==NULL)
		return false;
	node *fast=head;
	node *slow=head;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}
//创建有环链表，并实现头插
void create_ring(node *&head,int key)
{
	if(head==NULL)
	{
		head=new node(key);
		head->next=head;
	}else
	{
		node *tmp=new node(key);
		node *cur=head;
		while(cur->next !=head)
			cur=cur->next;
		tmp->next=cur->next;
		cur->next=tmp;
	}
}
//二分查找  [ )
//1,2,3,4,5,6,7
int search(int *arr,int size,int key)
{
	assert(arr !=NULL);
	assert(size>0);
	int high=size-1;
	int low=0;
	while(low <=high)
	{
		int mod=low+(high-low)/2;
		if(arr[mod]==key)
			return mod;
		if(key <arr[mod])
			high=mod;
		else
			low=mod+1;
	}
	return -1;
}
//双链表插入
struct both_node
{
	int key;
	struct both_node *prev;
	struct both_node *next;
	both_node(int k)
		:key(k),prev(NULL),next(NULL)
	{}
};
//插入
void insert_both(both_node *&head,int key)
{
	if(head==NULL)
	{
		head=new both_node(key);
	}else
	{
		both_node *tmp=new both_node(key);
		if(head->next==NULL)
		{
			head->next=tmp;
			tmp->prev=head;
		}else
		{
			tmp->next=head->next;
			head->next->prev=tmp;

			head->next=tmp;
			tmp->prev=head;
		}
	}
}
//删除
bool remove_both(both_node *&head,int key)
{
	if(head==NULL)
		return false;
	if(head->key==key)
	{
		if(head->next==NULL)
		{
			delete head;
			head=NULL;
		}else
		{
			both_node *tmp=head;
			head=head->next;
			head->prev=NULL;
			delete tmp;
			tmp=NULL;
		}
		return true;
	}
	both_node *cur=head->next;
	while(cur !=NULL && cur->key !=key)
		cur=cur->next;
	if(cur==NULL)
		return false;
	if(cur->next !=NULL)
	{
		cur->prev->next=cur->next;
		cur->next->prev=cur->prev;
	}else
	{
		cur->prev->next=NULL;
	}
	
	delete cur;
	cur=NULL;
	return true;
}
void show_both(both_node *head)
{
	both_node *cur=head;
	while(cur !=NULL)
	{
		cout<<cur->key<<" ";
		cur=cur->next;
	}
	cout<<endl;
}
//两个链表是否相交？
//常规解法，但时间复杂度为O(N1*N2)
bool intersct(node *des,node *src)
{
	if(des==NULL || src==NULL)
		return false;
	node *cur_des=des;
	
	while(cur_des !=NULL)
	{
		node *cur_src=src;
		while(cur_src !=NULL)
		{
			if(cur_src==cur_des)
				return true;
			cur_src=cur_src->next;
		}
		cur_des=cur_des->next;
	}
}
//第二中解法，如果两个链表相交，他们的地址当然相等
//做法：将src链表链接到des最后，如果链表有环，出现环的位置刚好是两链表相交的地方
//用两个快慢指针进行遍历des链表
//时间复杂度O(N1+N1+N2)
bool intersct_quick(node *des,node *src)
{
	if(des==NULL)
		des=src;
	else
	{
		node *cur=des;
		while(cur->next !=NULL)
			cur=cur->next;
		cur->next=src;
	}
	node *fast=des;
	node *slow=des;
	while(fast !=NULL && fast->next !=NULL)
	{
		fast=fast->next->next;
		slow=slow->next;
		if(fast==slow)
			return true;
	}
	return false;
}