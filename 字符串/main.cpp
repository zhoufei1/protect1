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
			cout<<"�������ַ�����";
			PrintString(RET);
			break;
		case 3:
			cout<<"**���Ϊ:0,����Ϊ:1С��Ϊ:-1**"<<endl;
			cout<<"�ȽϺ�Ľ����"<<StrCompare(S,T)<<endl;			
			break;
		case 4:
			 cout<<"�ַ������ȣ�"<<Length(S)<<endl;
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
			cout<<"���Ӻ���ַ���:";
			PrintString(RET);
			break;
		case 8:
			cout<<"������Ҫ��ȡ�Ӵ�λ�õ��±�ͳ��ȣ�"<<endl;
			cin>>pos;
			cin>>length;
			SubString(RET,S,pos,length);
			cout<<"�Ӵ�:";
			PrintString(RET);
			break;
		case 9:
			pos=Index(S,0,T);
			if(-1==pos)
			{
				cout<<"ƥ�䲻�ɹ�"<<endl;
			}
			else
				cout<<"��_"<<pos<<"_ƥ��ɹ�"<<endl;
			break;
		case 10:
			Replace(S,T,P,0);
			PrintString(S);
			break;
		case 11:
			cout<<"������Ҫ����λ�õ��±꣺"<<endl;
			cin>>pos;
			StrInsert(S,pos,P);
			cout<<"�������ַ�����";
			PrintString(S);
			break;
		case 12:
			cout<<"������Ҫɾ��λ�õ��±�͸�����"<<endl;
			cin>>pos;
			cin>>length;
			StrDelete(S,pos,length);
			cout<<"ɾ������ַ�����";
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

