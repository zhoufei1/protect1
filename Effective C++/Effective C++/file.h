#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class base
{
public:
	void virtual show()const=0;
	//必须定义成静态的，因为它需要支持::这样访问
	static base *GetPoint()
	{
		//可以使用C语言中malloc函数来实现内存分配
		base *tmp=(base*)malloc(sizeof(base));
		assert(tmp !=NULL);
		//这不能使用new来分配空间，因为是抽象类
		//base *tmp=new base;
		return tmp;
	}
	void fun()const
	{
		cout<<"base fun"<<endl;
	}
};
class trans_base
{
private:
	trans_base()
	{}
public:
	//必须定义成静态的，因为它需要支持::这样访问
	static trans_base* GetBase()
	{
		//1、可以用两种方式申请空间，new或者malloc
		//trans_base *tmp=new trans_base;
		//2、用malloc申请空间也是可以的
		trans_base *tmp=(trans_base*)malloc(sizeof(trans_base));
		assert(tmp !=NULL);
		return tmp;
	}
	void show()const
	{
		cout<<"trans_base show"<<endl;
	}
};
class child:public base
{
public:
	void show1()const
	{
		cout<<"show"<<endl;
	}
private:
	int number;
};
class father
{
private:
	int a;
	//base key;
};


void test()
{
	//base bs;//error
	base *pbs=base::GetPoint();
	pbs->fun();
	//trans_base tb; //error
	trans_base *ptb=trans_base::GetBase();
	ptb->show();
}
void test1()
{
	//base bs;
	//child ch;
	//cout<<"bs size is :"<<sizeof(bs)<<endl;
	//cout<<"ch size is :"<<sizeof(ch)<<endl;
	//cout<<"father size is :"<<sizeof(father)<<endl;
}