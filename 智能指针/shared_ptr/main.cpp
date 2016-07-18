
#include"shared.h"
#include<vld.h>

#include"shared_count.h"

void main()
{
	shared_ptr<int> sp(new int(10));
	weak_ptr<int> pu;
	system("pause");
}
/*void main()
{
	int *p=new int(10);
	int *q=new int(110);
	shared_ptr<int> pt(p);
	cout<<*pt<<endl;
	cout<<pt.user_count()<<endl;
	shared_ptr<int> ps=pt;

	{
		weak_ptr<int> pu(q);
		cout<<"pu-->"<<pu._use_count()<<endl;
	}

	{
		shared_ptr<int> ps(q);
		cout<<pt.user_count()<<endl;
		ps=pt;
	}
		cout<<pt.user_count()<<endl;
}*/