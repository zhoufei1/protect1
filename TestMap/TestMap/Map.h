#include <iostream>
#include <string>
#include <map>
#include <string.h>
using namespace std;


struct str
{
	bool operator()(const char *des,const char *src)const
	{
		//return strcmp(des,src);
		return true;
	}
};
void TestMap1()
{
	map<const char*,int> t;
	t["change"]=13;
	t["hello"]=14;
	t["hello"]=18;
	t["world"]=15;
	map<const char*,int>::iterator it=t.begin();
	while(it !=t.end())
	{
		cout<<it->first<<"  "<<it->second<<endl;
		++it;
	}
}

void TestMap2()
{
	map<const char*,int> m;
	pair<const char*,int> p;
	m.insert(pair<const char*,int>("hello",1));
	m.insert(pair<const char*,int>("hello",15));
	m.insert(pair<const char*,int>("world",8));
	m.insert(pair<const char*,int>("abd",19));
	m.insert(pair<const char*,int>("ddd",10));
	map<const char*,int>::iterator it=m.begin();
	while(it !=m.end())
	{
		cout<<it->first<<" "<<it->second<<endl;
		++it;
	}
}


void TestMap3()
{
	map<int,const char*> m;
	m.insert(pair<int,const char*>(4,"abcd"));
	m.insert(pair<int,const char*>(1,"ttt"));
	m.insert(pair<int,const char*>(44,"aaaaa"));
	m.insert(pair<int,const char*>(1,"sss"));
	m.insert(pair<int,const char*>(5,"ddd"));
	map<int,const char*>::iterator it=m.begin();
	while(it !=m.end())
	{
		cout<<it->first<<" "<<it->second<<endl;
		++it;
	}
}
struct Node
{
	string name;
	int time;
	Node(string &n,int t):name(n),time(t)
	{}
	bool operator ==(const Node &t)const
	{
		return (name==t.name && time==t.time);
	}
	bool operator < (const Node &t)const
	{
		return time<t.time;
	}
};


struct pNode
{
	string name;
	int time;
	pNode(string &n,int t):name(n),time(t)
	{}
	bool operator ==(const pNode &t)const
	{
		return (name==t.name && time==t.time);
	}
	/*bool operator < (const pNode &t)const
	{
		return time<t.time;
	}*/
};
struct Key
{
	int operator()(const pNode &t)
	{
		return 1;
	}
};
void TestMap4()
{
	string name1="zhofei";
	int time1=100;
	const Node node1(name1,time1);
	string name2="zhofei2";
	int time2=200;
	const pNode node2(name2,time2);
	string name3="zhofei3";
	int time3=300;
	const Node node3(name3,time3);
	//map<Node,pNode,Key> m;
	map<Node,pNode> m;

	m.insert(pair<Node,pNode>(node1,node2));
	m.insert(pair<Node,pNode>(node3,node2));
	m.insert(pair<Node,pNode>(node1,node2));
		/*map<Node*,int> m;
		m.insert(&node1,13);
		m.insert(&node2,33);
		m.insert(&node3,53);*/

	map<Node,pNode>::iterator it=m.begin();
	while(it !=m.end())
	{
		cout<<it->first.name<<" "<<it->first.time<<" | \t";
		cout<<it->second.name<<" "<<it->second.time<<endl;
		++it;
	}
}