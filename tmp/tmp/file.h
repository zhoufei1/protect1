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
	cout<<"*     �������Ǹ��ɰ��Ĵ�ɵ��   *"<<endl;
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

//��ӡ1������nλ��
bool print_number(char *str,int n)
{
	int top=0;
	//�Ӹ�λ��ʼ����
	for(int i=n-1; i>=0; --i)
	{
		int sum=str[i]-'0'+top;
		if(i==n-1)
			sum++;
		//����ӵ�ֵ����10ʱ����ǰ��1����i��=0ʱ���ѵ�ǰλ����0
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
			str[i]='0'+sum;//�����һλ��ʼ���
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
		//��Ҫ��֤ǰ��λ������ľͲ�����
		//���磺001-->ֻ�������1ǰ���00�����
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
	buf[n]='\0';//����Ǳ���Ҫ�ģ���֤�ַ����ܽ���
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
	//����ϵͳ���Դ���
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

//�ַ�����ȫ����ʵ��
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

//����һ���������飬�жϸ������ǲ���һ�Ŷ����������ĺ��������Ľ��
//����Ƿ���true,���򷵻�false
//���������ڶ��������������ԣ�������һ��С�ڸ��ڵ㣬������һ�����ڸ��ڵ�
//������һ�Ŷ����������в������������ͬ�Ľڵ㣬
bool IsBST(int arr[],int len)
{
	assert(arr !=NULL);
	if(len < 0)
		return false;
	//�������ڶ����������ԣ����Ը��ڵ������һ���ڵ�
	int root=arr[len-1];
	int i=0;
	while(i <len-1)
	{
		//�ҵ���һ���ȸ��ڵ��Ľڵ�,����һ��Ϊ��
		//С��i���Ǹ��ڵ�������������i����������
		if(arr[i] >root)
			break;
		++i;
	}
	int j=i+1;
	while(j <len-1)
	{
		//���ڶ��������������ʣ���������ҵ����������б�rootС����
		//�ǾͲ��Ƕ���������,����false
		if(arr[j] <root)
			return false;
	}
	//����͵ݹ��ȥ�����������м�����
	bool leftchild=true;
	//��i�±������С��i���Ǹ��ڵ�������
	//����i�±����������
	if(i >0)
		leftchild=IsBST(arr,i);
	//�ݹ�������
	bool rightchild=true;
	if(i < len-1)
		rightchild=IsBST(arr,len-i-1);

	//��󷵻����������� && �Ľ��
	return (leftchild && rightchild);
}


//10����һ����c�̳���a��b����һ��b���͵�ָ��ָ��c
//������dynamiccast��bת��a��ת��ǰ���ַ�Ƿ�һ�¡�
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

//������������m��n,����m��Ҫ�ı����λ���ܵõ�n��
//��������ʼ��û��˼·�ģ����˺ܾò��е�˼·
//˼·����Դ�ǰ�����ת���ɶ����ƺ���е�
//���磺��5���Ķ����ƣ�0101  ��3���Ķ����ƣ�0011
//���Ҫ��5���3�Ļ�����Ҫ�ı䣺2�Σ���Ϊ��һλ0�����һλ1����ͬ
//���Բ���Ҫ�ı䣬�������Ƚ����������Ȼ��������1�ĸ���
int GetCount(int N,int M)
{
	int value=N^M;//�Ƚ����������
	int count=0;
	while(value)
	{
		count++;
		value=(value&(value-1));//������1�ĸ���
	}
	return count;
}

void TestGetCount()
{
	int n=5;  //0101
	int m=3; //1010
	//��Ŀ����˼�����ǽ���1010-->0101
	cout<<"count is :"<<GetCount(n,m)<<endl;
}



//��ת�������Сֵ
//3,4,5,6,7,1,2--->���1
//6,7,1,2,3,4,5--->���1
//[]������
int min_key(int *arr,int low,int heigh)
{
	int begin=arr[low];
	int end=arr[heigh];
	while(low <= heigh)
	{
		int mid=low+(heigh-low)/2;
		//1,1,1,1,0,0
		if(arr[low] <= arr[mid] && arr[low] >= arr[heigh])//����ȷ����С����һ�����ұ�
		{
			low=mid;
			if(heigh-low == 1)
				return arr[heigh] <arr[low] ? arr[heigh]:arr[low];
		}//����ȷ����С����һ������ߣ���������һ����������������
		else if(arr[low] < arr[mid] && arr[low] < arr[heigh])
			return arr[low];
		//����ȷ����С����һ�����ұߣ���������һ�������ݼ�������
		else if(arr[low] > arr[mid] && arr[mid] > arr[heigh])
			return arr[heigh];
		//����ȷ����С����һ�������
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