#include <iostream>
using namespace std;
#include <assert.h>

struct node
{
	int value;
	struct node *next;
	node(int key=0):value(key){}
};
//��ͷ�ĵ�����
void init(node *&head)
{
	if(NULL==head)
		head=NULL;
}
//���������head==NULL����û���ҵ�������NULL
//���򷵻��ҵ��Ľڵ�
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
	if(cur==NULL)//�����head==NULL����û���ҵ�
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
//��ת
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
//ɾ��
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
	///��������key�Ͳ����head->value��ȣ����ԾͿ��Դ�head->next->value��ʼ�Ƚ�
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
//�ϲ�������������
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
//�ж��Ƿ��л�
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
//�����л�������ʵ��ͷ��
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
//���ֲ���  [ )
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
//˫�������
struct both_node
{
	int key;
	struct both_node *prev;
	struct both_node *next;
	both_node(int k)
		:key(k),prev(NULL),next(NULL)
	{}
};
//����
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
//ɾ��
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
//���������Ƿ��ཻ��
//����ⷨ����ʱ�临�Ӷ�ΪO(N1*N2)
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
//�ڶ��нⷨ��������������ཻ�����ǵĵ�ַ��Ȼ���
//��������src�������ӵ�des�����������л������ֻ���λ�øպ����������ཻ�ĵط�
//����������ָ����б���des����
//ʱ�临�Ӷ�O(N1+N1+N2)
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