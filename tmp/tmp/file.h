#include <iostream>
#include <assert.h>
#include <string.h>
#include <stack>
using namespace std;
#define SIZE 10


void Test()
{
	char buf[]="\\123456\123456\t";
	char *p=buf;
	int k=0;
	while( *p !='\0')
	{
		k++;
		p++;
	}

	for(int i=0; i<15; ++i)
		cout<<buf[i]<<" ";
	cout<<endl;
	cout<<strlen(buf)<<endl;
}

/*
static void fun()
{
	 int a;
	cout<<"********************************"<<endl;
	cout<<"*     杨丽丽是个可爱的大傻逼   *"<<endl;
	cout<<"********************************"<<endl;
}

void Test()
{
	fun();
}
/*
#include<stdio.h>
int inc(int a)
{
   return (++a);
}
int multi(int *a,int *b,int *c)
{ 
  return (*c=*a* *b);
}
typedef int (FUNC1)(int in);
typedef int (FUNC2)(int*,int*,int*);
void show(FUNC2 fun,int arg1,int *arg2)
{
  FUNC1 *p=&inc;
  int temp=p(arg1);
  fun(&temp,&arg1,arg2);
  printf("%d\n",*arg2);
}
int Test()
{ 
   int a;
   show(multi,10,&a);
   return 0;
}


/*class TestAA
{
public:
	void fun(float key)
	{
		cout<<"1"<<endl;
	}
};
class TestBB:public TestAA
{
public:
	void fun(int x)
	{
		cout<<"2"<<endl;
	}
};
void Test()
{
	TestAA *a=new TestAA;
	TestBB *b=new TestBB;
	a=b;
	a->fun(1);
}


/*
class BSS
{
public:
	int GetData()const
	{
		return data;
	}
	void fun()
	{
		static int key;
		cout<<"key :"<<key<<endl;
	}
private:
	static int data;
};
int BSS::data=10;

void Test()
{
	BSS b;
	cout<<b.GetData()<<endl;
	b.fun();
	//static int a=10;
	//cout<<a<<endl;
}
class Base
{
public:
    Base()
    {
        Init();
    }
    virtual void Init()
    {
        printf("Base Init\n");
    }
    void func()
    {
        printf("Base func\n");
    }
};
class Derived: public Base
{
public:
    virtual void Init()
    {
        printf("Derived Init\n");
    }
    void func()
    {
        printf("Derived func\n");
    }
};
 
int mainTest()
{
    Derived d;
    ((Base *)&d)->func();
     
    return 0;
}

//打印1到最大的n位数
bool print_number(char *str,int n)
{
	int top=0;
	//从个位开始算起
	for(int i=n-1; i>=0; --i)
	{
		int sum=str[i]-'0'+top;
		if(i==n-1)
			sum++;
		//当相加的值大于10时，向前进1，当i！=0时，把当前位置置0
		if(sum >=10)
		{
			if(i==0)
				return true;
			//else
			sum-=10;
			top=1;
			str[i]='0';
		}else
		{
			str[i]='0'+sum;//从最后一位开始相加
			return false;
		}
	}
	return false;
}
void print_result(char *str,int n)
{
	bool flag=true;
	for(int i=0; i<n; ++i)
	{
		//主要保证前面位数是零的就不输入
		//例如：001-->只让它输出1前面的00不输出
		if(flag && str[i] !='0')
			flag=false;
		if(! flag)
			cout<<str[i];
	}
	cout<<" ";
}
void print_str(int n)
{
	char *buf=new char[n+1];
	memset(buf,'0',n);
	buf[n]='\0';//这个是必须要的，保证字符串能结束
	while(!print_number(buf,n))
	{
		print_result(buf,n);
	}
	delete []buf;
	buf=NULL;
}
int get_len(int n)
{
	int len=1;
	for(int i=0; i<n; ++i)
	{
		if(len >=INT_MAX)
			return INT_MAX;
		len*=10;
	}
	return len;
}
void print(int n)
{
	if(n <=0)
		return;
	int len=get_len(n);
	//#define INT_MAX       2147483647   
	//这是系统里自带的
	if(len >= INT_MAX)
	{
		print_str(n);
		return;
	}
	for(int i=1; i<len; ++i)
		cout<<i<<" ";
	cout<<endl;
}



void Test2()
{
	char buf[5];
	//gets(buf);
	cout<<buf<<endl;
}

void Test1()
{
	int arr[SIZE]={0};
	for(int i=0; i<SIZE; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//字符串的全排列实现
void permutition(char *ptr,char *begin)
{
	if(*begin =='\0')
		cout<<ptr<<endl;
	else
	{
		for(char *ch=begin; *ch !='\0'; ++ch)
		{
			swap(*begin,*ch);
			permutition(ptr,begin+1);
			swap(*begin,*ch);
		}
	}
}
void permutition(char *ptr)
{
	assert(ptr);
	permutition(ptr,ptr);
}
void TestPtr()
{
	char str[]="123";
	permutition(str);
}

//输入一个整数数组，判断该数组是不是一颗二叉搜索树的后续遍历的结果
//如果是返回true,否则返回false
//分析：由于二叉搜索树的特性，左子树一定小于根节点，右子树一定大于根节点
//所以在一颗二叉搜索树中不会出现两个相同的节点，
bool IsBST(int arr[],int len)
{
	assert(arr !=NULL);
	if(len < 0)
		return false;
	//首先由于二叉树的特性，所以根节点是最后一个节点
	int root=arr[len-1];
	int i=0;
	while(i <len-1)
	{
		//找到第一个比根节点大的节点,从这一分为二
		//小于i的是根节点左子树，大于i的是右子树
		if(arr[i] >root)
			break;
		++i;
	}
	int j=i+1;
	while(j <len-1)
	{
		//由于二叉搜索树的性质，所以如果找到右子树中有比root小的树
		//那就不是二叉搜索树,返回false
		if(arr[j] <root)
			return false;
	}
	//否则就递归的去从左右子树中继续找
	bool leftchild=true;
	//从i下标隔开，小于i的是根节点左子树
	//大于i下标的是右子树
	if(i >0)
		leftchild=IsBST(arr,i);
	//递归右子树
	bool rightchild=true;
	if(i < len-1)
		rightchild=IsBST(arr,len-i-1);

	//最后返回左右子树相 && 的结果
	return (leftchild && rightchild);
}


//10、有一个类c继承自a和b。有一个b类型的指针指向c
//现在用dynamiccast将b转成a后，转换前后地址是否一致。
class AA
{
public:
	virtual void showa()
	{
		cout<<"show AA"<<endl;
	}
private:
	int a;
};
class BB
{
public:
	virtual void showb()
	{
		cout<<"show BB"<<endl;
	}
private:
	int b;
};
class CC:virtual public AA,virtual public BB
{
public:
	virtual void showc()
	{
		cout<<"show CC"<<endl;
	}
	virtual void fun()
	{}
private:
	int c;
};
void TestClass()
{
	CC *pc=new CC;
	BB *pB=new BB;
	BB *pb=pc;
	AA *pA=new AA;
	AA *pa=dynamic_cast<AA*>(pb);
}

//输入两个整数m和n,计算m需要改变多少位才能得到n？
//这个题我最开始是没有思路的，想了很久才有点思路
//思路的来源是把他们转化成二进制后才有的
//例如：（5）的二进制：0101  （3）的二进制：0011
//如果要把5变成3的话，需要改变：2次，因为第一位0和最后一位1都相同
//所以不需要改变，做法，先将两个数异或，然后求异或后1的个数
int GetCount(int N,int M)
{
	int value=N^M;//先将两个数异或
	int count=0;
	while(value)
	{
		count++;
		value=(value&(value-1));//求异或后1的个数
	}
	return count;
}

void TestGetCount()
{
	int n=5;  //0101
	int m=3; //1010
	//题目的意思本意是将：1010-->0101
	cout<<"count is :"<<GetCount(n,m)<<endl;
}



//旋转数组的最小值
//3,4,5,6,7,1,2--->情况1
//6,7,1,2,3,4,5--->情况1
//[]闭区间
int min_key(int *arr,int low,int heigh)
{
	int begin=arr[low];
	int end=arr[heigh];
	while(low <= heigh)
	{
		int mid=low+(heigh-low)/2;
		//1,1,1,1,0,0
		if(arr[low] <= arr[mid] && arr[low] >= arr[heigh])//可以确定最小的数一定在右边
		{
			low=mid;
			if(heigh-low == 1)
				return arr[heigh] <arr[low] ? arr[heigh]:arr[low];
		}//可以确定最小的数一定在左边，而且这是一个连续递增的序列
		else if(arr[low] < arr[mid] && arr[low] < arr[heigh])
			return arr[low];
		//可以确定最小的数一定在右边，而且这是一个连续递减的序列
		else if(arr[low] > arr[mid] && arr[mid] > arr[heigh])
			return arr[heigh];
		//可以确定最小的数一定在左边
		else if(arr[low] >= arr[mid] && arr[mid] <= arr[heigh])
		{
			heigh=mid;
			if(heigh-low == 1)
				return arr[heigh] <arr[low] ? arr[heigh]:arr[low];
		}
	}
	return -1;
}
int min_value(int *arr,int len)
{
	assert(arr !=NULL);
	return min_key(arr,0,len-1);
}

void test_min_value()
{
	//int arr[]={3,4,5,6,7,1,2};
	//int arr[]={1,2,3,4,5,6,7};
	//int arr[]={7,6,5,4,3,2};
	//int arr[]={6,7,1,2,3,4};
	//int arr[]={1,1,1,1,0,0};
	//int arr[]={0,1,1,1,0,0};
	int arr[]={1,1,0,1,1,1};
	int len=sizeof(arr)/sizeof(*arr);
	int min=min_value(arr,len);
	cout<<"min is :"<<min<<endl;
}


*/