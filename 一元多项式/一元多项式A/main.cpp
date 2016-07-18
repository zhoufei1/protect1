#include"LinkList.h"


void main()
{
	List<int> mylist;
	List<int> youlist;
	int e=0;
	int c;
	int select=1;
	while(select)
	{
		show_list();
		cin>>select;
		switch(select)
		{
		case 1:
			while(1)
			{
				cout<<"输入系数:";
				cin>>c;
				cout<<"输入指数：";
				cin>>e;
				mylist.CreatPolyn(c,e);
				if(e==0)
					break;
			}
			break;
		case 2:
		while(1)
			{
				cout<<"输入系数:";
				cin>>c;
				cout<<"输入指数：";
				cin>>e;
				youlist.CreatPolyn(c,e);
				if(e==0)
					break;
			}
			break;
		case 3:
			cout<<"[1]:mylist [2]:youlist"<<endl;
			cout<<"请选择显示";
			cin>>select;
			if(select==1)
				mylist.show();
			else
				youlist.show();
			break;
		case 4:
			mylist.Jia(&youlist);
			break;
		case 5:
			mylist.Jian(&youlist);
			break;
		case 7:
			mylist.cheng(&youlist);
			break;
		default:
			break;
		}
	}
}