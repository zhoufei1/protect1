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
			cout<<"��������ַ�����";
			PrintString(&TS);
			break;
		case 3:
			pos=StrCompare(&S,&TS);
			cout<<"�ȽϺ��ֵ��"<<pos<<endl;
			break;
		case 4:
			cout<<"�ַ������ȣ�"<<Length(&S)<<endl;
			break;
		case 5:
			PrintString(&S);
			break;
		case 6:
			ClearString(&S);
			break;
		case 7:
			StringConcat(&RS,&S,&TS);
			cout<<"���Ӻ���ַ�����"<<RS.ch<<endl;
			break;
		case 8:
			StrAssign(&S,str);
			cout<<"������λ�ã�";
			cin>>pos;
			cout<<"���볤�ȣ�";
			cin>>length;
			pos=SubString(&RS,&S,pos,length);
			if(pos!=-1)
			    cout<<"�Ӵ���"<<RS.ch<<endl;
			else
				cout<<"����λ�úͳ��Ȳ�����"<<endl;
			break;
		case 9:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			cout<<"����λ�ã�";
			cin>>pos;
			pos=Index(&S,pos,&TS);
			if(pos!=-1)
				cout<<"��"<<pos<<"λ��ƥ��ɹ�"<<endl;
			else
				cout<<"ƥ�䲻�ɹ�"<<endl;
			break;
		case 10:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			StrAssign(&RS,p);
			cout<<"����λ�ã�";
			cin>>pos;
			Replace(&S,&TS,&RS,pos);
			cout<<S.ch<<endl;
			break;
		case 11:
			StrAssign(&S,str);
			StrAssign(&TS,ret);
			cout<<"����λ�ã�";
			cin>>pos;
			StrInsert(&S,pos,&TS);
			cout<<S.ch<<endl;
			break;
		case 12:
			StrAssign(&S,str);
			cout<<"������λ�ã�";
			cin>>pos;
			cout<<"���볤�ȣ�";
			cin>>length;
			pos=StrDelete(&S,pos,length);
			if(pos!=-1)
				cout<<S.ch<<endl;
			else
				cout<<"λ�û򳤶Ȳ����ʣ��������ɾ��"<<endl;
			break;
		case 13:
			DestroyString(&S);
			cout<<"�ַ����ѱ��ݻ�"<<endl;
			break;
	//	case 0:  exit(-1);
		default:
				break;
		}
	}	
}