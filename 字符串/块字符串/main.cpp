#include"String.h"

void main()
{
	char *str="abcdefghixy";
	char *p="efgh";

	LString S;
	LString TS;
	LString RS;

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
			break;
		case 2:
			StrAssign(&TS,p);
			StringConcat(&S,&TS);
			cout<<"���Ӻ���ַ�����"<<endl;
			PrintString(&S);
			break;
		case 3:
			StrAssign(&RS,p);
			pos=StrCompare(&S,&RS);
			cout<<"�ȽϺ��ֵ��"<<pos<<endl;
			break;
		case 4:
			cout<<"�ַ������ȣ�"<<GetLength(&S)<<endl;
			break;
		case 5:
			PrintString(&S);
			break;
		case 6:
			ClearString(&S);
			break;
		case 7:
			StrAssign(&RS,p);
			cout<<"������λ�ã�";
			cin>>pos;
			pos=Index(&S,pos,&RS);
			cout<<"ƥ��ɹ���λ�ã�"<<pos<<endl;
			break;
		case 8:
			StrAssign(&TS,p);
			cout<<"������λ�ã�";
			cin>>pos;
			Replace(&S,&TS,pos);
			break;	
		case 9:
			StrAssign(&TS,p);
			cout<<"����λ�ã�";
			cin>>pos;
			StrInsert(&S,pos,&TS);
			break;
		case 10:
			cout<<"����λ�ã�";
			cin>>pos;
			StrDelete(&S,pos);
			break;		
		case 11:
			DestroyString(&S);
			break;
		default:
				break;
		}
	}	
}