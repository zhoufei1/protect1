#include<iostream>
using namespace std;



void Swap(char &a,char &b)
{
	char ch=a;
	a=b;
	b=ch;
}
void reverse(char *str,int low,int higth)
{
	if(low<higth)
	{
		Swap(str[low],str[higth]);
		reverse(str,low+1,higth-1);
	}
}
void reverse(char *str,int length)
{
	reverse(str,0,length-1);
}
void main()
{
	char *str=new char;
	cout<<"please Enter:";
	cin>>str;
	cout<<"逆制前："<<str<<endl;
	int length=strlen(str);
	reverse(str,length);
	cout<<"逆制后："<<str<<endl;
}