#include<iostream>
using namespace std;

void fun()
{
	cout<<"fun"<<endl;
}
class AA
{
public:
	AA()
	{
		cout<<"构造函数"<<endl;
	}
	~AA()
	{
		cout<<"析构函数"<<endl;
		fun();
	}
};
AA t;