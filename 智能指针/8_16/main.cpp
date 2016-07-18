#include<iostream>
using namespace std;
#include<vld.h>
#include<memory>


void main()
{
	int *p=new int(190);
	int *q=new int(200);

	
	auto_ptr<int> pt(p);
	auto_ptr<int> qt=pt;
	qt=pt;
	cout<<"*pt="<<*pt<<endl;
	cout<<"*qt="<<*qt<<endl;
	//delete p;
}