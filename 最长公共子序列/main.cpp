#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#define LENGTH 10
                //�ҳ�����λ�ӵ�������еĳ��ȣ�����¼���ݵ�
void findMax(int *arr, int *str, int *ret,int length)
{	
	for(int i = 0; i < length; i++)//��ʼ��ʱ�������Ϊһ,���ݾ���Ϊ-1		
	{						
		str[i] = 1;		
		ret[i] = -1;				
		int temp = 1;	//��ʱ������������г��ȵı���
		
		for(int j = 0; j < i; j++)//�������ŵݹ��ϵ�����������ӽ������i���������				
		{									
			if(arr[j] <= arr[i] && (str[j] + 1) >= temp)	//�ݹ�������			
			{										
				temp = str[j] + 1;  //�����޸���������еĳ���												
				ret[i] = j;     //��¼��һ�����ݵ�				
			}			
		}			
		str[i] = temp;		
	}	
}

void trackBack(int *arr, int *str, int *ret,int length)//����������
{		
	int get[LENGTH];  //�������������		
	int j = 0;	    //��¼��������е��±�	
	int k = 0;	    //�����±���ʱ�������		
	int max = 0;	//��ʱ����ӵ��������е�λ��		
	
	for(int i = 0; i < length; i++)	//��������s[]�ҳ�λ��		
	{		
		max = (str[i] > max) ? i : max;		
	}		
	get[j] = max;	//���ݻ�ý��
	k = ret[max];	//�����±�ʱ�������
	j++;	
	while(k >= 0)		
	{		
		get[j] = k;		
		k = ret[k];		
		j++;		
	}	
	j--;	
	while(get[j] >= 0)		//������		
	{		
		printf("%d ", arr[get[j]]);		
		j--;		
	}	
	printf("\n");	
}

void main()
{		
	int length;  
	printf("���볤�ȣ�");
	scanf("%d", &length);
	
	int *str=(int *)malloc(sizeof(int) * length);    //�洢ÿ��λ�õ��������	
		assert(str!=NULL);
	int *arr=(int *)malloc(sizeof(int) * length);	//�������������	
		assert(arr!=NULL);
	int *ret=(int *)malloc(sizeof(int) * length);	//������ݵ�,Ĭ����-1
		assert(ret!=NULL);

	for(int i = 0; i < length; i++)	//5 1 3 5 2 9
	{	
		scanf("%d", &arr[i]);	
	}
	findMax(arr, str, ret, length);//�ҳ�����λ�ӵ�������еĳ��ȣ�����¼���ݵ�			
	
	trackBack(arr, str, ret, length);//����������	
}

