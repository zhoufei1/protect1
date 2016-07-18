#include "list.h"

int main()
{
	/*node *head=NULL;
	node *tmp=NULL;
	init(head);
	for(int i=0; i<10; ++i)
		push_back(head,i+10);
	init(tmp);
	for(int i=0; i<10; ++i)
		push_back(tmp,i+1);
	//int key=10;//
	//int key=15;
	//int key=19;
	//int key=100;
	//insert(head,key);
	//show(head);
	//reserve(head);
	show(head);
	int key=190;
	bool flag=remove(head,key);
	if(flag)
	{
		cout<<"true"<<endl;
		show(head);
	}else
	{	
		cout<<"false"<<endl;
		show(head);
	}
	//show(head);
	//show(tmp);
	//node *Key=merger(head,tmp);
	//show(Key);
	node *phead=NULL;
	for(int i=0; i<5; ++i)
		create_ring(phead,3+i);
	bool flag=IsRing(phead);
	if(flag)
		cout<<"yes"<<endl;
	else
		cout<<"No"<<endl;
	int arr[]={1,2,3,4,5,6,7,8};
	int size=sizeof(arr)/sizeof(*arr);

	int key=6;
	int pos=search(arr,size,key);
	cout<<"pos :"<<pos<<endl;*/

	int key=20;
	both_node *both_head=NULL;
	for(int i=0; i<2; ++i)
		insert_both(both_head,key+i);
	show_both(both_head);
	int value=20;
	if(remove_both(both_head,value))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	show_both(both_head);
	return 0;
}