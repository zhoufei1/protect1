#include <iostream>
#include <string.h>
#include <assert.h>

using namespace std;

class base
{
public:
	void virtual show()const=0;
	//���붨��ɾ�̬�ģ���Ϊ����Ҫ֧��::��������
	static base *GetPoint()
	{
		//����ʹ��C������malloc������ʵ���ڴ����
		base *tmp=(base*)malloc(sizeof(base));
		assert(tmp !=NULL);
		//�ⲻ��ʹ��new������ռ䣬��Ϊ�ǳ�����
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
	//���붨��ɾ�̬�ģ���Ϊ����Ҫ֧��::��������
	static trans_base* GetBase()
	{
		//1�����������ַ�ʽ����ռ䣬new����malloc
		//trans_base *tmp=new trans_base;
		//2����malloc����ռ�Ҳ�ǿ��Ե�
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