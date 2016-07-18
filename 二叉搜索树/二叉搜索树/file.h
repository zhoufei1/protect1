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
		cout<<"ת����˫�����";
		show(head);
	}
	//��ʾ˫����
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
	//ʵ�ֽ�����������ת����˫����
	//ֻҪ֪����������������������������Ĵ����Ķ���û������
	//�����Զ������������������Ϥ���ǽ����ȰѶ��������������Ū������ҵ�ʵ�֣�
	//�������������ڿ���ʱ��о����񲻶�
	TreeNode* TreeToList(TreeNode *root)
	{
		assert(root);
		TreeNode *cur=root;
		TreeNode *ptr=NULL;
		TreeNode *head=NULL;//��Ҫ����ͷ�ڵ�

		stack<TreeNode*> s;
		s.push(root);
		while(!s.empty())
		{
			if(cur !=NULL)//��֤��˫���������Ӹı�ָ��󲻽���
			{
				while(cur->leftchild !=NULL)
				{
					s.push(cur->leftchild);
					cur=cur->leftchild;
				}
			}
			//������һ�������ʺ�Ľڵ㣬
			//�Դ������˴η��ʵĽڵ���������ӵ���һ���ڵ�
			TreeNode *tmp=ptr;

			ptr=s.top();
			s.pop();

			ptr->leftchild=tmp;//�����ڱ����ʵĽڵ����������ӵ���һ���ڵ�
			cur=NULL;  //�ⲽ����Ҫ����ĺ���Ҫ����Ϊ��ǰ�ڵ����ӵ�ָ���Ѿ����ı�
			if(tmp !=NULL)
				tmp->rightchild=ptr;
			else if(tmp ==NULL)//��Ҫ����ͷ�ڵ�
				head=ptr;

			if(ptr->rightchild !=NULL)
			{
				s.push(ptr->rightchild);
				cur=ptr->rightchild;  //�ⲽҲ����Ҫ���ı�cur��ָ��
			}
		}
		return head;
	}
private:
	TreeNode *_root;
};