#include <iostream>
#include <assert.h>
using namespace std;

void bubble_sort(int *arr,int len)
{
	for(int i=1; i<len; ++i)
	{
		for(int j=0; j<len-i; ++j)
			if(arr[j] >arr[j+1])
				swap(arr[j],arr[j+1]);
	}
}
void shell_sort(int *arr,int low,int high)	
{
	assert(arr);
	assert(low <high);
	int grep=high-low+1;
	while(grep >1)
	{
		grep=grep/3+1;
		for(int i=low+grep; i<high; ++i)
		{
			if(arr[i] < arr[i-grep])
			{
				int tmp=arr[i];
				int j=i-grep;
				for(; j>=low && arr[j] >tmp; j=j-grep)
					arr[j+grep]=arr[j];
				arr[j+grep]=tmp;
			}
		}
	}
}

void insert_sort(int *arr,int low,int high)
{
	assert(arr);
	assert(low <high);
	for(int i=low+1; i<high; ++i)
	{
		if(arr[i]<arr[i-1])
		{
			int tmp=arr[i];
			int j=i-1;
			for(; j>=low && arr[j]>tmp; --j)
				arr[j+1]=arr[j];
			arr[j+1]=tmp;
		}
	}
}
void select_sort(int *arr,int len)
{
	assert(arr !=NULL);
	assert(len> 0);
	for(int i=0; i<len; ++i)
	{
		for(int j=i+1; j<len; ++j)
		{
			if(arr[i] > arr[j])
				swap(arr[i],arr[j]);	
		}
	}
}

void print_log(int *arr,int len)
{
	for(int i=0; i<len; ++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}