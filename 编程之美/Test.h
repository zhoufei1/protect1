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
		cout<<"���캯��"<<endl;
	}
	~AA()
	{
		cout<<"��������"<<endl;
		fun();
	}
};
AA t;