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
		cout<<"ÄÚ´æ²»¹»"<<endl;
	}
	else
		PrintString(&T);

	ret=StrAssign(&P,p);
	if(ret!=0)
	{
		cout<<"ÄÚ´æ²»¹»"<<endl;
	}
	else
		PrintString(&P);

	cout<<"ÇëÊäÈëÎ»ÖÃ£º";
	cin>>pos;
	int value=Index(&T,pos,&P);
	if(-1==value)
	{
		cout<<"Æ¥ÅäÊ§°Ü"<<endl;
	}
	else
	{
		cout<<"value="<<value<<endl;
	}
}