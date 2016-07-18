#include<iostream>
#include<string>
using namespace std;
int GetValue(const string &ch)
{	
	int length=ch.length();
	if(length<0)
	{
		return -1;
	}
	int sum=0;
	int t=0;
	for(int i=0;i<length;++i)
	{
		t=ch[i]-'A';
		if(t>=26 || t<0)
		{
			return -1;
		}
		sum=sum*26+t+1;
	}
	return sum;
}
void main()
{
//	char *ch=new char;
	string ch;
	getline(cin,ch,'#');
	int value=GetValue(ch);
	if(value==-1)
	{
		cout<<"不存在"<<endl;
	}
	else
	{
		cout<<"当前在"<<value<<"列"<<endl;
	}
}