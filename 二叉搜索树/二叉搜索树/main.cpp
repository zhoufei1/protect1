#include "file.h"





void TestTree()
{
	Tree<int> t;
	int data;
	while(cin>>data && data !=-1)
	{
		t.CreateTree(data);
	}
	cout<<"�������������������";
	t.InOrder();
	cout<<endl;
	t.TreeToList();
}
int main()
{
	TestTree();
	return 0;
}