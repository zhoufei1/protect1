#include "file.h"
//#include <boost/shared_ptr.hpp>
//using namespace boost;
#include <list>
#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;


void main()
{
	 Test();
}

/*
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
		if(arr[low] < arr[mid] && arr[low] > arr[heigh])//����ȷ����С����һ�����ұ�
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
		else if(arr[low] > arr[mid] && arr[mid] < arr[heigh])
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

int main()
{
	int arr[]={3,4,5,6,7,1,2};
	int len=sizeof(arr)/sizeof(*arr);
	int min=min_value(arr,len);
	cout<<"min is :"<<min<<endl;
	//list<int> mylist;
	//int *p=new int(10);	
	//shared_ptr<int*> pt(p);
	return 0;
}


/*
int main()
{
	int n=0;
	cout<<"�����룺";
	while(cin>>n && n!=-1)
	{
		//print_int(n);
		print_max(n);
	}
	//list<int> mylist;
	//AA n(30);
	//AA tmp=n;
	//BB t(10);
	//BB k=t;
	//BB a(20);
	//t=a;
	return 0;
}*/