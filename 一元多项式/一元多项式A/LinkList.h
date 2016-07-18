
#include<iostream>
#include<assert.h>
using namespace std;

template<class Type>
class List;

template<class Type>
class Node
{
	friend class List<Type>;
public:
	Node(Type c,int e,Node<Type> *n=NULL)
		:coef(c),expn(e),next(n)
	{}
	~Node()
	{}
private:
	Type coef; //ϵ��
	int expn;  //ָ��
	Node<Type> *next;
};

template<class Type>
class List
{
private:
	size_t size;
	Node<Type> *first;
	Node<Type> *last;
protected:
	Node<Type>* _BuyNode(const Type c=0,const int e=0)
	{
		Node<Type> *s=new Node<Type>(c,e);
		assert(s);
		return s;
	}
public:
	List()
	{
		Node<Type> *s=_BuyNode();
		first=last=s;
		size=0;
	}
	Node<Type>* GetNode()const
	{
		return first;
	}
	Node<Type>* find(int e)const
	{
		Node<Type> *p=first;
		while(p->next!=NULL)
		{
			if(p->next->expn > e)
				return p;
			p=p->next;
		}
		return last;
	}
	void CreatPolyn(Type x,int e)
	{		
		Node<Type> *s=_BuyNode(x,e);	
		Node<Type> *p=find(e);
		
		s->next=p->next;
		p->next=s;
		
		if(p==last)
			last=s;
		size++;
	}
	void show()
	{
		Node<Type> *p=first->next;
		while(p!=NULL)
		{
			if(p->expn==0)
			{
				if(first->next->expn < 0)
					cout<<" + ";
				cout<<p->coef;
			}
			else if(p->expn==1)
				cout<<" + "<<p->coef<<"x";
			else
			{
				if(p->coef > 0)
					cout<<" + ";
				cout<<p->coef<<"x^"<<p->expn;
			}
			p=p->next;
		}
		cout<<endl;
	}
	void Jia(List<Type> *node)
	{
		Node<Type> *p=node->GetNode();
		Node<Type> *q=first;
		while(p->next != NULL && q->next != NULL)
		{
			if(p->next->expn == q->next->expn)
			{
				q->next->coef+=p->next->coef;
				p=p->next;
				q=q->next;
			}
			else if(p->next->expn < q->next->expn)
			{
				Node<Type> *t=p->next;
				p=p->next;
				t->next=q->next;
				q->next=t;
				q=t->next;
			}	
			else
				q=q->next;
		}
		if(q->next==NULL && p->next!=NULL)
		{
			q->next=p;
		}
	}
	
	////////////////////////////////////////////
	void Jian(List<Type> *node)
	{
		Node<Type> *p=node->GetNode();
		Node<Type> *q=first;
		while(p->next != NULL && q->next != NULL)
		{
			if(p->next->expn == q->next->expn)
			{
				q->next->coef-=p->next->coef;
				p=p->next;
				q=q->next;
			}
			else if(p->next->expn < q->next->expn)
			{
				Node<Type> *t=p->next;
				p=p->next;
				t->next=q->next;
				q->next=t;
				q=t->next;
			}	
			else
				q=q->next;
		}
		if(q->next==NULL && p->next!=NULL)
		{
			q->next=p;
		}
	}

	void cheng(List<Type> *node)
	{
		Node<Type> *head=first->next;//Type coef; //ϵ�� expn;ָ��
		while(head!=NULL)
		{
			Node<Type> *p=node->GetNode()->next;
			while(p != NULL)
			{
				head->coef*=p->coef;
				head->expn+=p->expn;
				p=p->next;
			}
			head=head->next;
		}
	}
};

void show_list()
{
	cout<<"*************************************"<<endl;
	cout<<"* [1]:����mylist    [2]:����youlist *"<<endl;
	cout<<"* [3]:��ʾ	       [4]:�ӷ�����    *"<<endl;
	cout<<"* [5]:��������	   [6]:�˳�ϵͳ    *"<<endl;
	cout<<"* [7]:�˷�����	   [8]:�˳�ϵͳ    *"<<endl;
	cout<<"*************************************"<<endl;
	cout<<"��ѡ��";
}

