#include <iostream>
using namespace std;
#include <list>
#include <algorithm>
int main()
{
	list<int> mylist;
	mylist.push_back(10);
	mylist.push_back(11);
	mylist.push_back(12);
	mylist.push_back(13);
	list<int>::iterator it=mylist.begin();
	int i=0;
	while(it !=mylist.end())
	{
		cout<<*it<<" ";
		if(i==1)
			*it=100;
		i++;
		it++;
	}
	cout<<endl;
	it=find(mylist.begin(),mylist.end(),13);
	list<int>::iterator key=mylist.erase(it);
	//*it=300;
	it=mylist.begin();
	while(it !=mylist.end())
	{
		cout<<*it<<" ";
		it++;
	}
	cout<<endl;
	return 0;
}