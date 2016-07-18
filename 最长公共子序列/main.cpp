#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#define LENGTH 10
                //找出所有位子的最长子序列的长度，并记录回溯点
void findMax(int *arr, int *str, int *ret,int length)
{	
	for(int i = 0; i < length; i++)//初始化时最长子序列为一,回溯矩阵为-1		
	{						
		str[i] = 1;		
		ret[i] = -1;				
		int temp = 1;	//暂时存放最大的子序列长度的变量
		
		for(int j = 0; j < i; j++)//根据最优递归关系，基于最优子解来求得i的最长子序列				
		{									
			if(arr[j] <= arr[i] && (str[j] + 1) >= temp)	//递归条件是			
			{										
				temp = str[j] + 1;  //重新修改最大子序列的长度												
				ret[i] = j;     //记录上一个回溯点				
			}			
		}			
		str[i] = temp;		
	}	
}

void trackBack(int *arr, int *str, int *ret,int length)//回溯输出结果
{		
	int get[LENGTH];  //保存最大子序列		
	int j = 0;	    //记录最大子序列的下标	
	int k = 0;	    //回溯下标暂时保存变量		
	int max = 0;	//暂时保存拥有最长子序列的位置		
	
	for(int i = 0; i < length; i++)	//遍历数组s[]找出位置		
	{		
		max = (str[i] > max) ? i : max;		
	}		
	get[j] = max;	//回溯获得结果
	k = ret[max];	//回溯下标时保存变量
	j++;	
	while(k >= 0)		
	{		
		get[j] = k;		
		k = ret[k];		
		j++;		
	}	
	j--;	
	while(get[j] >= 0)		//输出结果		
	{		
		printf("%d ", arr[get[j]]);		
		j--;		
	}	
	printf("\n");	
}

void main()
{		
	int length;  
	printf("输入长度：");
	scanf("%d", &length);
	
	int *str=(int *)malloc(sizeof(int) * length);    //存储每个位置的最长子序列	
		assert(str!=NULL);
	int *arr=(int *)malloc(sizeof(int) * length);	//给定的随机数组	
		assert(arr!=NULL);
	int *ret=(int *)malloc(sizeof(int) * length);	//保存回溯点,默认是-1
		assert(ret!=NULL);

	for(int i = 0; i < length; i++)	//5 1 3 5 2 9
	{	
		scanf("%d", &arr[i]);	
	}
	findMax(arr, str, ret, length);//找出所有位子的最长子序列的长度，并记录回溯点			
	
	trackBack(arr, str, ret, length);//回溯输出结果	
}

