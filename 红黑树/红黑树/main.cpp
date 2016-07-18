#include "RBTree.h"

int main()
{
	RBTree<int,int> t;
	t.insert(30,0);
	t.insert(20,0);
	t.insert(10,0);
	t.insert(15,0);
	t.insert(6,0);
	t.insert(11,0);
	t.Inorder();
	return 0;
}