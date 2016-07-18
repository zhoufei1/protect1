#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

enum Colour{RED,BLACK};

template<class K,class V>
struct RBNode
{
	K _key;
	V _value;
	Colour colour;

	struct RBNode<K,V> *leftchild;
	struct RBNode<K,V> *rightchild;
	struct RBNode<K,V> *parent;
	RBNode(const K &key,const V &value)
		:_key(key),_value(value),colour(RED)
		,leftchild(NULL),rightchild(NULL),parent(NULL)
	{}
};

template<class K,class V>
class RBTree
{
	typedef RBNode<K,V> RBNode;
private:
	//左单旋
	void RotateL(RBNode *&parent)
	{
		RBNode *cur=parent->rightchild;
		RBNode *curL=cur->leftchild;

		parent->rightchild=curL;
		if(curL !=NULL)
			curL->parent=parent;
		cur->leftchild=parent;
		cur->parent=parent->parent;
		parent->parent=cur;
		RBNode *father=parent->parent;
		if(father->_key <cur->_key)
			father->leftchild=cur;
		else
			father->rightchild=cur;
		parent=cur;
	}
	//右单旋
	void RotateR(RBNode *&parent)
	{
		RBNode *cur=parent->leftchild;

		parent->leftchild=cur->rightchild;
		if(cur->rightchild !=NULL)
			cur->rightchild->parent=parent;
		cur->rightchild=parent;
		cur->parent=parent->parent;
		parent->parent=cur;
		if(cur->parent==NULL)
			root=cur;
		else
		{
			RBNode *father=cur->parent;
			if(father->_key <cur->_key)
				father->leftchild=cur;
			else
				father->rightchild=cur;
		}
		parent=cur;
	}
public:
	bool insert(const K &key=K(),const V &value=V())
	{
		if(root==NULL)
		{
			root=new RBNode(key,value);
			root->colour=BLACK;
			return true;
		}
		RBNode *cur=root;
		RBNode *parent=NULL;
		while(cur !=NULL)
		{
			//先把父节点保存起来
			parent=cur;
			if(key < cur->_key)
				cur=cur->leftchild;
			else if(key > cur->_key)
				cur=cur->rightchild;
			else
				return false;
		}
		//开辟的新节点
		cur=new RBNode(key,value);
		if(key < parent->_key)
			parent->leftchild=cur;
		else 
			parent->rightchild=cur;
		cur->parent=parent;
		//到这的时候，节点已经插入成功，接下来开始调整
		//parent=cur->parent;
		//这个条件一定可以满足至少有两个节点已经在树中了
		while(cur !=root && parent->colour !=BLACK)
		{
			RBNode *grand_father=parent->parent;
			//在左边插入
			if(grand_father->leftchild==parent)
			{
				//在父节点的左边插入
				if(cur==parent->leftchild)
				{
					//在左边插入的时候分两种情况
					//1、祖父节点的右子树不为空，并且颜色为红色
					//将祖父节点的右子树和父节点的颜色变成黑色，直接结束循环
					if(grand_father->rightchild !=NULL && \
						grand_father->rightchild->colour==RED)
					{
						parent->colour=BLACK;
						grand_father->rightchild->colour=BLACK;

						grand_father->colour=RED;
						//继续上调
						cur=grand_father;
					}else
					{
						//2、祖父的右子树为空或者右子树颜色为黑色
						//直接进行右单旋，右单旋时传入的是祖父节点
						//旋转之前先祖父节点和父节点的颜色变换
						grand_father->colour=RED;
						parent->colour=BLACK;
						RotateR(grand_father);
					}
				}else //在父节点的右边插入
				{
					if(grand_father->rightchild !=NULL &&\
						grand_father->rightchild->colour==RED)
					{
						grand_father->rightchild->colour=BLACK;
						parent->colour=BLACK;
						grand_father->colour=RED;

						cur=grand_father;
					}else
					{
						//先进行左单旋，传入的是父节点
						RotateL(parent);
						//然后交换祖父节点和父节点的颜色
						grand_father->colour=RED;
						parent->colour=BLACK;
						//然后在以祖父节点为轴进行右单旋
						RotateR(grand_father);
					}
				}
			}else//if(grand_father->rightchild==parent) //在右边插入
			{
				if(parent->rightchild==cur)//在父节点的右边插入
				{
					//1、祖父节点的左子树为红色节点
					if(grand_father->leftchild && \
						grand_father->leftchild->colour==RED)
					{
						grand_father->leftchild->colour=BLACK;
						parent->colour=BLACK;
						grand_father->colour=RED;

						cur=grand_father;
					}else //2、祖父节点的左子树为空或者为黑色
					{
						//改变颜色进行左单旋
						grand_father->colour=RED;
						parent->colour=BLACK;
						RotateL(grand_father);
					}
				}else//在父节点的左边插入
				{
					//1、祖父节点的左子树为红色节点
					if(grand_father->leftchild && \
						grand_father->leftchild->colour==RED)
					{
						grand_father->leftchild->colour=BLACK;
						parent->colour=BLACK;
						grand_father->colour=RED;

						cur=grand_father;
					}else //2、祖父节点的左子树为空或者为黑色
					{
						//先以父节点为轴进行右单旋
						RotateR(parent);
						//再改变颜色进行左单旋
						grand_father->colour=RED;
						parent->colour=BLACK;
						RotateL(grand_father);
					}
				}
			}
		}
		root->colour=BLACK;
		return true;
	}
	bool insert_tmp2(const K &key,const V &value)
	{
		//当还没有根节点的时候，创建根节点，
		if(root==NULL)
		{
			root=new RBNode(key,value);
			//并把根节点的颜色设置成黑色，因为默认生成的节点的颜色是红色
			root->colour=BLACK;
			return true;
		}
		///已经有了一个节点了，先把节点插入到树里，然后再来调整
		RBNode *cur=root;
		RBNode *parent=cur->parent;
		while(cur !=NULL)
		{
			if(key < cur->_key)//往左子树寻找
			{
				parent=cur;
				cur=cur->leftchild;
			}else if(key > cur->_key)//往右子树寻找
			{
				parent=cur;
				cur=cur->rightchild;
			}
			else//相等就返回，满足二叉搜索树的性质
				return false;
		}
		RBNode *tmp=new RBNode(key,value);
		//开始插入节点
		if(key <parent->_key)//在左子树上进行插入
			parent->leftchild=tmp;		
		else//在右子树上插入
			parent->rightchild=tmp;
		tmp->parent=parent;//出来后改变tmp的父节点的指向，这点很重要
		//接下来就开始调节平衡了
		cur=tmp;//首先让cur指向新插入的节点(tmp)
		//然后记录三个节点的位置
		RBNode *parent=cur->parent;
		RBNode *grend_father=parent->parent;
		//当插入节点时只有两个节点的时候，直接不进这个循环
		while(cur !=root && parent->colour !=BLACK && grend_father!=NULL)
		{
			//key 插在祖父节点的左边时
			if(key <grend_father->_key)
			{
				//1、插在父节点的左边
				if(key <parent->_key)
				{
					//插在父节点的左边的时候右得分两种情况
					//1、祖父节点的右子树为空、或右子树为黑色
					if(grend_father->rightchild==NULL || grend_father->rightchild->colur==BLACK)
					{
						//先把祖父节点变成红色
						grend_father->colour=RED;
						//再把父节点变成黑色
						parent->colour=BLACK;
						//直接进行右单旋，以祖父节点为旋转轴
						Rrotate(grend_father);
						//旋转后得改变父指针的指向
						parent->parent=grend_father->parent;
						grend_father->parent=parent;
					}else //祖父节点的右子树为红色
					{
						//直接将父节点和祖父节点的右子树变成黑色
						//再把祖父节点变成红色,然后再继续回溯
						parent->colour=BLACK;
						grend_father->rightchild->colour=BLACK;
						grend_father->colour=RED;
					}
				}else //2、插在父节点的右边 //if(key >parent->_key)
				{
					//先以父节点为轴进行左单旋，然后再以祖父节点为轴进行右单旋
						Lrotate(grend_father);
						//左单旋出来后改变节点的父指针
						cur->parent=parent->parent;
						parent->parent=cur;
					//1、如果祖父节点的右子树为空、或为黑色
					if(grend_father->rightchild ==NULL ||grend_father->rightchild->colour==BLACK )
					{				
						//再进行右单旋之前把颜色先改变
						//因为cur的位置和parent的位置已经被改变，
						//所以现在实际上是cur和祖父节点进行右单旋
						cur->colour=BLACK;
						grend_father->colour=RED;
						//然后再以祖父节点进行右单旋
						Rrotate(grend_father);
						//出来后又得改变父指针的指向
						cur->parent=grend_father->parent;
						grend_father->parent=cur;
					}else //2、祖父节点的右子树为红色
					{
						//先父节点和祖父节点的右子树变成黑色，
						//再把祖父节点变成红色，继续往上调
						grend_father->rightchild->colour=BLACK;
						grend_father->colour=RED;
						//因为父节点已经和cur进行旋转了
						cur->colour=BLACK;
					}
				}
			}else //if(key >grend_father->_key)//插在祖父节点的右边
			{
				////
			}
		}
	}
	bool insert_tmp1(const K &key,const V &value)
	{
		//当还没有根节点的时候，创建根节点，
		if(root==NULL)
		{
			root=new RBNode(key,value);
			//并把根节点的颜色设置成黑色，因为默认生成的节点的颜色是红色
			root->colour=BLACK;
			return true;
		}
		///已经有了一个节点了，先把节点插入到树里，然后再来调整
		RBNode *cur=root;
		RBNode *parent=cur->parent;
		while(cur !=NULL)
		{
			if(key < cur->_key)
			{
				parent=cur;
				cur=cur->leftchild;
			}else if(key > cur->_key)
			{
				parent=cur;
				cur=cur->rightchild;
			}
			else
				return false;
		}
		RBNode *tmp=new RBNode(key,value);
		if(key < parent->_key)
		{
			parent->leftchild=tmp;
			tmp->parent=parent;
			//parent->leftchild=new RBNode(key,value);
			//parent->leftchild->parent=parent;//更新当前节点的父节点
		}
		else 
		{
			parent->rightchild=tmp;
			tmp->parent=parent;
			//parent->rightchild=new RBNode(key,value);
			//parent->rightchild->parent=parent;//更新当前节点的父节点
		}
		//插入节点已经完成
		//接下来开始调整节点
		RBNode *grandfather=parent->parent;
		while(cur !=root && cur->colour !=BLACK && grandfather !=NULL)
		{
			//首先让他们回退
			if(cur->parent==grandfather->leftchild)//在祖父节点左边插入节点
			{
				if(cur->_key <parent->_key)//在父节点左边插入
				{
					grandfather=grandfather->parent;
					parent=grandfather;
					cur=parent;
					if(parent->rightchild==NULL)//祖父节点的右为空，进行右单旋
					{
						//首先把父节点变成红色，cur节点变成黑色
						parent->colour=RED;
						cur->colour=BLACK;
						
						Rrotate(parent);//右单旋
					}else if(parent->rightchild !=NULL)
					{
						//祖父节点的右子女不为空，并且在祖父节点左子女的左边插入节点
						parent->colour=BLACK;
						grandfather->rightchild->colour=BLACK;
					}
				}else if(cur->_key >parent->_key) //在父节点右边插入
				{
					if(parent->rightchild==NULL)
					{
						//先进行左单旋，再进行右单旋
						Lrotate(parent->leftchild);
						//单旋完了后还必须改变父节点的指向
						parent->leftchild->rightchild->parent=parnet;
						parent->leftchild->parent=parent->leftchild->rightchild;
						//右单旋
						Rrotate(parent->leftchild);
					}
				}
			}
		}
		if(tmp->colour)
	}
public:
	RBTree():root(NULL)
	{}
	~RBTree()
	{}
	void Inorder()
	{
		Inorder(root);
		cout<<endl;
	}
public:
	//中序遍历-->左-根-右
	void Inorder(RBNode *parent)
	{
		if(parent==NULL)
			return;
		Inorder(parent->leftchild);
		cout<<parent->_key<<" ";
		Inorder(parent->rightchild);
	}
private:
	RBNode *root;
};



