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
	//����
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
	//�ҵ���
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
			//�ȰѸ��ڵ㱣������
			parent=cur;
			if(key < cur->_key)
				cur=cur->leftchild;
			else if(key > cur->_key)
				cur=cur->rightchild;
			else
				return false;
		}
		//���ٵ��½ڵ�
		cur=new RBNode(key,value);
		if(key < parent->_key)
			parent->leftchild=cur;
		else 
			parent->rightchild=cur;
		cur->parent=parent;
		//�����ʱ�򣬽ڵ��Ѿ�����ɹ�����������ʼ����
		//parent=cur->parent;
		//�������һ���������������������ڵ��Ѿ���������
		while(cur !=root && parent->colour !=BLACK)
		{
			RBNode *grand_father=parent->parent;
			//����߲���
			if(grand_father->leftchild==parent)
			{
				//�ڸ��ڵ����߲���
				if(cur==parent->leftchild)
				{
					//����߲����ʱ����������
					//1���游�ڵ����������Ϊ�գ�������ɫΪ��ɫ
					//���游�ڵ���������͸��ڵ����ɫ��ɺ�ɫ��ֱ�ӽ���ѭ��
					if(grand_father->rightchild !=NULL && \
						grand_father->rightchild->colour==RED)
					{
						parent->colour=BLACK;
						grand_father->rightchild->colour=BLACK;

						grand_father->colour=RED;
						//�����ϵ�
						cur=grand_father;
					}else
					{
						//2���游��������Ϊ�ջ�����������ɫΪ��ɫ
						//ֱ�ӽ����ҵ������ҵ���ʱ��������游�ڵ�
						//��ת֮ǰ���游�ڵ�͸��ڵ����ɫ�任
						grand_father->colour=RED;
						parent->colour=BLACK;
						RotateR(grand_father);
					}
				}else //�ڸ��ڵ���ұ߲���
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
						//�Ƚ���������������Ǹ��ڵ�
						RotateL(parent);
						//Ȼ�󽻻��游�ڵ�͸��ڵ����ɫ
						grand_father->colour=RED;
						parent->colour=BLACK;
						//Ȼ�������游�ڵ�Ϊ������ҵ���
						RotateR(grand_father);
					}
				}
			}else//if(grand_father->rightchild==parent) //���ұ߲���
			{
				if(parent->rightchild==cur)//�ڸ��ڵ���ұ߲���
				{
					//1���游�ڵ��������Ϊ��ɫ�ڵ�
					if(grand_father->leftchild && \
						grand_father->leftchild->colour==RED)
					{
						grand_father->leftchild->colour=BLACK;
						parent->colour=BLACK;
						grand_father->colour=RED;

						cur=grand_father;
					}else //2���游�ڵ��������Ϊ�ջ���Ϊ��ɫ
					{
						//�ı���ɫ��������
						grand_father->colour=RED;
						parent->colour=BLACK;
						RotateL(grand_father);
					}
				}else//�ڸ��ڵ����߲���
				{
					//1���游�ڵ��������Ϊ��ɫ�ڵ�
					if(grand_father->leftchild && \
						grand_father->leftchild->colour==RED)
					{
						grand_father->leftchild->colour=BLACK;
						parent->colour=BLACK;
						grand_father->colour=RED;

						cur=grand_father;
					}else //2���游�ڵ��������Ϊ�ջ���Ϊ��ɫ
					{
						//���Ը��ڵ�Ϊ������ҵ���
						RotateR(parent);
						//�ٸı���ɫ��������
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
		//����û�и��ڵ��ʱ�򣬴������ڵ㣬
		if(root==NULL)
		{
			root=new RBNode(key,value);
			//���Ѹ��ڵ����ɫ���óɺ�ɫ����ΪĬ�����ɵĽڵ����ɫ�Ǻ�ɫ
			root->colour=BLACK;
			return true;
		}
		///�Ѿ�����һ���ڵ��ˣ��Ȱѽڵ���뵽���Ȼ����������
		RBNode *cur=root;
		RBNode *parent=cur->parent;
		while(cur !=NULL)
		{
			if(key < cur->_key)//��������Ѱ��
			{
				parent=cur;
				cur=cur->leftchild;
			}else if(key > cur->_key)//��������Ѱ��
			{
				parent=cur;
				cur=cur->rightchild;
			}
			else//��Ⱦͷ��أ��������������������
				return false;
		}
		RBNode *tmp=new RBNode(key,value);
		//��ʼ����ڵ�
		if(key <parent->_key)//���������Ͻ��в���
			parent->leftchild=tmp;		
		else//���������ϲ���
			parent->rightchild=tmp;
		tmp->parent=parent;//������ı�tmp�ĸ��ڵ��ָ��������Ҫ
		//�������Ϳ�ʼ����ƽ����
		cur=tmp;//������curָ���²���Ľڵ�(tmp)
		//Ȼ���¼�����ڵ��λ��
		RBNode *parent=cur->parent;
		RBNode *grend_father=parent->parent;
		//������ڵ�ʱֻ�������ڵ��ʱ��ֱ�Ӳ������ѭ��
		while(cur !=root && parent->colour !=BLACK && grend_father!=NULL)
		{
			//key �����游�ڵ�����ʱ
			if(key <grend_father->_key)
			{
				//1�����ڸ��ڵ�����
				if(key <parent->_key)
				{
					//���ڸ��ڵ����ߵ�ʱ���ҵ÷��������
					//1���游�ڵ��������Ϊ�ա���������Ϊ��ɫ
					if(grend_father->rightchild==NULL || grend_father->rightchild->colur==BLACK)
					{
						//�Ȱ��游�ڵ��ɺ�ɫ
						grend_father->colour=RED;
						//�ٰѸ��ڵ��ɺ�ɫ
						parent->colour=BLACK;
						//ֱ�ӽ����ҵ��������游�ڵ�Ϊ��ת��
						Rrotate(grend_father);
						//��ת��øı丸ָ���ָ��
						parent->parent=grend_father->parent;
						grend_father->parent=parent;
					}else //�游�ڵ��������Ϊ��ɫ
					{
						//ֱ�ӽ����ڵ���游�ڵ����������ɺ�ɫ
						//�ٰ��游�ڵ��ɺ�ɫ,Ȼ���ټ�������
						parent->colour=BLACK;
						grend_father->rightchild->colour=BLACK;
						grend_father->colour=RED;
					}
				}else //2�����ڸ��ڵ���ұ� //if(key >parent->_key)
				{
					//���Ը��ڵ�Ϊ�����������Ȼ�������游�ڵ�Ϊ������ҵ���
						Lrotate(grend_father);
						//����������ı�ڵ�ĸ�ָ��
						cur->parent=parent->parent;
						parent->parent=cur;
					//1������游�ڵ��������Ϊ�ա���Ϊ��ɫ
					if(grend_father->rightchild ==NULL ||grend_father->rightchild->colour==BLACK )
					{				
						//�ٽ����ҵ���֮ǰ����ɫ�ȸı�
						//��Ϊcur��λ�ú�parent��λ���Ѿ����ı䣬
						//��������ʵ������cur���游�ڵ�����ҵ���
						cur->colour=BLACK;
						grend_father->colour=RED;
						//Ȼ�������游�ڵ�����ҵ���
						Rrotate(grend_father);
						//�������ֵøı丸ָ���ָ��
						cur->parent=grend_father->parent;
						grend_father->parent=cur;
					}else //2���游�ڵ��������Ϊ��ɫ
					{
						//�ȸ��ڵ���游�ڵ����������ɺ�ɫ��
						//�ٰ��游�ڵ��ɺ�ɫ���������ϵ�
						grend_father->rightchild->colour=BLACK;
						grend_father->colour=RED;
						//��Ϊ���ڵ��Ѿ���cur������ת��
						cur->colour=BLACK;
					}
				}
			}else //if(key >grend_father->_key)//�����游�ڵ���ұ�
			{
				////
			}
		}
	}
	bool insert_tmp1(const K &key,const V &value)
	{
		//����û�и��ڵ��ʱ�򣬴������ڵ㣬
		if(root==NULL)
		{
			root=new RBNode(key,value);
			//���Ѹ��ڵ����ɫ���óɺ�ɫ����ΪĬ�����ɵĽڵ����ɫ�Ǻ�ɫ
			root->colour=BLACK;
			return true;
		}
		///�Ѿ�����һ���ڵ��ˣ��Ȱѽڵ���뵽���Ȼ����������
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
			//parent->leftchild->parent=parent;//���µ�ǰ�ڵ�ĸ��ڵ�
		}
		else 
		{
			parent->rightchild=tmp;
			tmp->parent=parent;
			//parent->rightchild=new RBNode(key,value);
			//parent->rightchild->parent=parent;//���µ�ǰ�ڵ�ĸ��ڵ�
		}
		//����ڵ��Ѿ����
		//��������ʼ�����ڵ�
		RBNode *grandfather=parent->parent;
		while(cur !=root && cur->colour !=BLACK && grandfather !=NULL)
		{
			//���������ǻ���
			if(cur->parent==grandfather->leftchild)//���游�ڵ���߲���ڵ�
			{
				if(cur->_key <parent->_key)//�ڸ��ڵ���߲���
				{
					grandfather=grandfather->parent;
					parent=grandfather;
					cur=parent;
					if(parent->rightchild==NULL)//�游�ڵ����Ϊ�գ������ҵ���
					{
						//���ȰѸ��ڵ��ɺ�ɫ��cur�ڵ��ɺ�ɫ
						parent->colour=RED;
						cur->colour=BLACK;
						
						Rrotate(parent);//�ҵ���
					}else if(parent->rightchild !=NULL)
					{
						//�游�ڵ������Ů��Ϊ�գ��������游�ڵ�����Ů����߲���ڵ�
						parent->colour=BLACK;
						grandfather->rightchild->colour=BLACK;
					}
				}else if(cur->_key >parent->_key) //�ڸ��ڵ��ұ߲���
				{
					if(parent->rightchild==NULL)
					{
						//�Ƚ����������ٽ����ҵ���
						Lrotate(parent->leftchild);
						//�������˺󻹱���ı丸�ڵ��ָ��
						parent->leftchild->rightchild->parent=parnet;
						parent->leftchild->parent=parent->leftchild->rightchild;
						//�ҵ���
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
	//�������-->��-��-��
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



