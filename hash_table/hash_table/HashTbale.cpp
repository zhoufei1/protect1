#include <iostream>
#include <hash_set>
#include <hash_map>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(13);
	v.push_back(23);
	v.push_back(113);
	v.push_back(75);
	
	vector<int>::iterator vcur=find(v.begin(),v.end(),123);
	if(vcur !=v.end())
		cout<<"find vcur is :"<<*vcur<<endl;
	else
		cout<<"not find vcur 23"<<endl;
	set<int> s;
	s.insert(3);
	s.insert(4);

	set<int>::iterator cur=s.begin();
	for(; cur !=s.end(); ++cur)
		cout<<*cur<<" ";
	cout<<endl;
	set<int>::iterator ret=s.find(4);
	if(ret !=s.end())
		cout<<"find is :"<<*ret<<endl;
	else
		cout<<"not find 4"<<endl;
	//	s.

	//map<int> m;
	//hash_set<int> t;
	//hashtable<int,int,hash<int>,identity<int>,equal_to<int>,alloc> iht(50,hash<int>(),equal_to<int>());
	return 0;
}