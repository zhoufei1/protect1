#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <list>
const int N=5;
#include <new>


class AA
{
public:
	int c;
	virtual void fun()
	{}
	static int fun(int key)
	{return 0;}
	
	void print()
	{
		cout<<" &c:"<<&c<<endl;
		cout<<" &a:"<<&a<<endl;
		cout<<" &b:"<<&b<<endl;
		cout<<"value:"<<&value<<endl;
		//cout<<"fun: "<<fun()<<endl;
	}
	
private:
	int a;
	int b;
	static int value;
};
int AA::value=0;
void TestAA()
{
	AA t;
	t.print();
}

/*
void TestList()
{
	list<int> mylist;
	for(int i=0; i<N; ++i)
		mylist.push_back(i+10);
	list<int>::iterator it=mylist.begin();
	while(it !=mylist.end())
	{
		
		if((*it & 0x01)==0)
			it=mylist.erase(it);
		else
		{
			cout<<*it<<" ";
			++it;
		}
	}
	cout<<endl;
}
void TestVector()
{
	//int k=0;
	//int *p=new int;
	vector<int> v;
	for(int i=0; i<N; ++i)
	{
		v.push_back(i+10);
	}
	for(int i=0; i<N; ++i)
		cout<<v[i]<<" ";
	cout<<endl;
	cout<<"size :"<<v.size ()<<endl;
	cout<<"captity £º"<<v.capacity()<<endl;
	vector<int>::iterator it=find(v.begin(),v.end(),13);
	if(it !=v.end())
	{
		cout<<*it<<endl;
		v.erase(it++);
		//cout<<*it<<endl;
	}
	cout<<"size :"<<v.size ()<<endl;
	cout<<"captity £º"<<v.capacity()<<endl;
}
*/