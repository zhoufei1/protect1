#include"String.h"
void main()
{
	char *str = "ABCDEFG";
	char *str1 ="EF";
	char *str2="ab";

	SString RET;
	SString T;
	SString P;
	SString S;

	int length;
	int pos=1;
	while(pos)
	{
		Show();
		cin>>pos;
		switch(pos)
		{
		case 1:
			StrAssign(S,str);
			StrAssign(T,str1);	
			StrAssign(P,str2);
			break;
		case 2:
			StrCopy(RET,T);
			cout<<"拷贝后字符串：";
			PrintString(RET);
			break;
		case 3:
			cout<<"**相等为:0,大于为:1小于为:-1**"<<endl;
			cout<<"比较后的结果："<<StrCompare(S,T)<<endl;			
			break;
		case 4:
			 cout<<"字符串长度："<<Length(S)<<endl;
			break;
		case 5:
			PrintString(S);
			PrintString(T);
			PrintString(P);
			break;
		case 6:
			ClearString(S);
			break;
		case 7:
			StringConcat(RET,S,T);
			cout<<"链接后的字符串:";
			PrintString(RET);
			break;
		case 8:
			cout<<"输入需要获取子串位置的下标和长度："<<endl;
			cin>>pos;
			cin>>length;
			SubString(RET,S,pos,length);
			cout<<"子串:";
			PrintString(RET);
			break;
		case 9:
			pos=Index(S,0,T);
			if(-1==pos)
			{
				cout<<"匹配不成功"<<endl;
			}
			else
				cout<<"在_"<<pos<<"_匹配成功"<<endl;
			break;
		case 10:
			Replace(S,T,P,0);
			PrintString(S);
			break;
		case 11:
			cout<<"输入需要插入位置的下标："<<endl;
			cin>>pos;
			StrInsert(S,pos,P);
			cout<<"插入后的字符串：";
			PrintString(S);
			break;
		case 12:
			cout<<"输入需要删除位置的下标和个数："<<endl;
			cin>>pos;
			cin>>length;
			StrDelete(S,pos,length);
			cout<<"删除后的字符串：";
			PrintString(S);
			break;
		case 13:
			DestroyString(S);
			break;
		default :
			break;
		}
		
	}
}

