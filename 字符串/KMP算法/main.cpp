#include"String.h"
void main()
{
	int ret=-1;
	int pos=0;
	char *str="abcdeeeefefghk";
	char *p="efg";
	HString T;
	HString P;
	InitHString(&T);
	InitHString(&P);

	ret=StrAssign(&T,str);
	if(ret!=0)
	{
		cout<<"�ڴ治��"<<endl;
	}
	else
		PrintString(&T);

	ret=StrAssign(&P,p);
	if(ret!=0)
	{
		cout<<"�ڴ治��"<<endl;
	}
	else
		PrintString(&P);

	cout<<"������λ�ã�";
	cin>>pos;
	int value=Index(&T,pos,&P);
	if(-1==value)
	{
		cout<<"ƥ��ʧ��"<<endl;
	}
	else
	{
		cout<<"value="<<value<<endl;
	}
}