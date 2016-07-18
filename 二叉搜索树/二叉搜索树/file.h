#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

template<class Type>
struct TreeNode
{
	Type _data;
	struct TreeNode<Type> *leftchild;
	struct TreeNode<Type> *rightchild;

	TreeNode(Type data=Type())
		:_data(data),leftchild(NULL),rightchild(NULL)
	{}
};

template<class Type>
class Tree
{
	typedef struct TreeNode<Type> TreeNode;
public:
	Tree():_root(NULL)  {}
public:
	void CreateTree(Type x)
	{
		CreateTree(_root,x);
	}
	void InOrder()
	{
		InOrder(_root);
	}
	void TreeToList()
	{
		TreeNode *head=TreeToList(_root);
		cout<<"转化成双链表后：";
		show(head);
	}
	//显示双链表
	void show(TreeNode *root)
	{
		TreeNode *cur=root;
		while(cur !=NULL)
		{
			cout<<cur->_data<<" ";
			cur=cur->rightchild;
		}
		cout<<endl;
	}
public:
	void CreateTree(TreeNode *&root,Type x)
	{
		if(root ==NULL)
		{
			root=new TreeNode(x);
			return;
		}
		TreeNode *cur=root;
		TreeNode *parent=root;
		while(cur !=NULL)
		{
			parent=cur;
			if(x < cur->_data)
				cur=cur->leftchild;
			else if(x > cur->_data)
				cur=cur->rightchild;
			else
				return;
		}
		TreeNode *tmp=new TreeNode(x);
		if(x < parent->_data)
			parent->leftchild=tmp;
		else
			parent->rightchild=tmp;
	}
	void InOrder(TreeNode *root)
	{
		if(root==NULL)
			return;
		InOrder(root->leftchild);
		cout<<root->_data<<" ";
		InOrder(root->rightchild);	
	}
public:
	//实现将二叉搜索树转化成双链表
	//只要知道二叉搜索树中序遍历，接下来的代码阅读将没有问题
	//如果你对二叉树的中序遍历不熟悉，那建议先把二叉树的中序遍历弄清楚再我的实现，
	//这样不会让你在看的时候感觉心神不定
	TreeNode* TreeToList(TreeNode *root)
	{
		assert(root);
		TreeNode *cur=root;
		TreeNode *ptr=NULL;
		TreeNode *head=NULL;//主要保存头节点

		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty())
		{
			if(cur !=NULL)//保证将双二叉树左孩子改变指向后不进入
			{
				while(cur->leftchild !=NULL)
				{
					s.push(cur->leftchild);
					cur=cur->leftchild;
				}
			}
			//保存上一个被访问后的节点，
			//以此来将此次访问的节点的左孩子链接到上一个节点
			TreeNode *tmp=ptr;

			ptr=s.top();
			s.pop();

			ptr->leftchild=tmp;//将正在被访问的节点左子树链接到上一个节点
			cur=NULL;  //这步很重要，真的很重要，因为当前节点左孩子的指向已经被改变
			if(tmp !=NULL)
				tmp->rightchild=ptr;
			else if(tmp ==NULL)//主要保存头节点
				head=ptr;

			if(ptr->rightchild !=NULL)
			{
				s.push(ptr->rightchild);
				cur=ptr->rightchild;  //这步也很重要，改变cur的指向
			}
		}
		return head;
	}
private:
	TreeNode *_root;
};