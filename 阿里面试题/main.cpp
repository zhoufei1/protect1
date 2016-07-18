#include<iostream>
using namespace std;




//#define  __int64 long long
struct aa
{
	__int64 a;
	char b;
	int c;
	char arr[2];
	static int d;
};
int aa::d;
void main()
{
	cout<<sizeof(aa)<<endl;
}
/*int i=0;
int fun(int n)
{
	static int a=2;
	a++;
	return n+a;
}
void main()
{
	int k=5;
	{
		int i=2;
		k+=fun(i);//k=5+fun(2)
	}
	k+=fun(i);//k=10+fun(0)
	cout<<k<<endl;
}
/*class base
{

public:
	~base()
	{cout<<"基类构造函数"<<endl;}
};
class Derived:public base
{
public:
	~Derived()
	{cout<<"子类构造函数"<<endl;}
};
void main()
{
	Derived d;
}
/*class base
{
private:
	int a;
public:
	base(int x):a(x)
	{cout<<"基类构造函数"<<endl;}
	virtual void show()
	{cout<<"a="<<a<<endl;}
};
class Derived:public base
{
private:
	int b;
public:
	Derived(int x):base(x),b(x)
	{cout<<"子类构造函数"<<endl;}
	void show()
	{cout<<"b="<<b<<endl;}
};
void main()
{
	base b(2);
	Derived d(3);
	b.show();
	d.show();
	base *p=&d;
	p->show();
}
/*class test
{
public:
	test()
	{cout<<"构造函数"<<endl;}
	~test()
	{cout<<"析构函数"<<endl;}
};
void main()
{
//	test arr[5];
	test *a[2];
}
*/