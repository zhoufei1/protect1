#include "file.h"





void TestTree()
{
	Tree<int> t;
	int data;
	while(cin>>data && data !=-1)
	{
		t.CreateTree(data);
	}
	cout<<"¶þ²æËÑË÷Ê÷ÖÐÐò±éÀú£º";
	t.InOrder();
	cout<<endl;
	t.TreeToList();
}
int main()
{
	TestTree();
	return 0;
}