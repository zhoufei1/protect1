#include"HString.h"

void main()
{
	char *str="abcdefg";
	char *ret="xy";
	char *p="ggg";

	HString S;
	HString TS;
	HString RS;

	InitHString(&S);
	InitHString(&TS);
	InitHString(&RS);
	int pos=1;
	int length=0;
	while(pos)
	{
		Show();
		cin>>pos;
		switch(pos)
		{
		case 1:			
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			break;
		case 2:		
			StrCopy(&TS,&S);
			cout<<"拷贝后的字符串：";
			PrintString(&TS);
			break;
		case 3:
			pos=StrCompare(&S,&TS);
			cout<<"比较后的值："<<pos<<endl;
			break;
		case 4:
			cout<<"字符串长度："<<Length(&S)<<endl;
			break;
		case 5:
			PrintString(&S);
			break;
		case 6:
			ClearString(&S);
			break;
		case 7:
			StringConcat(&RS,&S,&TS);
			cout<<"链接后的字符串："<<RS.ch<<endl;
			break;
		case 8:
			StrAssign(&S,str);
			cout<<"请输入位置：";
			cin>>pos;
			cout<<"输入长度：";
			cin>>length;
			pos=SubString(&RS,&S,pos,length);
			if(pos!=-1)
			    cout<<"子串："<<RS.ch<<endl;
			else
				cout<<"输入位置和长度不合理"<<endl;
			break;
		case 9:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			cout<<"输入位置：";
			cin>>pos;
			pos=Index(&S,pos,&TS);
			if(pos!=-1)
				cout<<"在"<<pos<<"位置匹配成功"<<endl;
			else
				cout<<"匹配不成功"<<endl;
			break;
		case 10:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			StrAssign(&RS,p);
			cout<<"输入位置：";
			cin>>pos;
			Replace(&S,&TS,&RS,pos);
			cout<<S.ch<<endl;
			break;
		case 11:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			cout<<"输入位置：";
			cin>>pos;
			StrInsert(&S,pos,&TS);
			cout<<S.ch<<endl;
			break;
		case 12:
			StrAssign(&S,str);
			cout<<"请输入位置：";
			cin>>pos;
			cout<<"输入长度：";
			cin>>length;
			pos=StrDelete(&S,pos,length);
			if(pos!=-1)
				cout<<S.ch<<endl;
			else
				cout<<"位置或长度不合适，不能完成删除"<<endl;
			break;
		case 13:
			DestroyString(&S);
			cout<<"字符串已被摧毁"<<endl;
			break;
	//	case 0:  exit(-1);
		default:
				break;
		}
	}	
}