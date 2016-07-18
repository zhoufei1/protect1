#include<iostream>
using namespace std;

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
	}
};
AA t;