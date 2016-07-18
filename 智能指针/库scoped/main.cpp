#include<iostream>
using namespace std;
#include<list>
#include<boost/smart_ptr/shared_ptr.hpp>
using namespace boost;



void main()
{
	int *p=new int(10);
	shared_ptr<int> pt(p);
	cout<<*pt<<endl;
	cout<<pt.user_count()<<endl;
}

/*template<class T>
void fun(T a)
{
	cout<<"类型："<<typeid(a).name()<<endl;
}

template<class T>
void sun(T &a)
{
	cout<<"类型："<<typeid(a).name()<<endl;
}

void main()
{
	int a[20];
	const int  b=2;
	cout<<"b="<<typeid(b).name()<<endl;
	fun(a);
	sun(a);
	fun(b);
	sun(b);
	fun(3);
	//sun(3);
	system("pause");
}
/*void main()
{
	int *p=new int(10);
	void *q=p;
	cout<<*(int*)q<<endl;
	delete q;
	cout<<*(int*)q<<endl;
	//cout<<sizeof(void)<<endl;
	//list<int>x;
	//int *p=new int(19);
//	scoped_ptr<int> pt(p);

}*/