#include <iostream>
#include <string.h>
#include <assert.h>
using namespace std;



void Test()
{
	char dest[1024]="abcdefd";
	char *src="hello";
	strcpy(dest,src);
	cout<<dest<<endl;
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


//��ӡ1������nλ��
//�ʼ�ǿ���ָofferʵ�ֵģ��������е��Σ������Լ��������Ժ��ܽ������
//�������������ô����ʱ�򽫴���д����Ȼ����ԣ����Ժ��֪��������ô���е�
//ע�͵Ĳ����ǽ�ָoffer��ʵ�ֵģ�
bool increment(char *str)
{
	//bool is_over_flow=false;
	int tmp=0;
	//int nTake=0;
	int len=strlen(str);
	for(int i=len-1; i>=0; --i)
	{
		int sum=str[i]-'0'+tmp;
		//int sum=str[i]-'0'+nTake;
		if(i==len-1)
			sum++;
		if(sum >=10)
		{
			if(i==0)   
				return true;
				//is_over_flow=true;
			else
			{
				sum-=10;
				tmp=1;
				//nTake=1;
				str[i]='0';
			}
		}else
		{
			str[i]='0'+sum;
			return false;
			//break;
		}
	}
	return true;
	//return is_over_flow;
}
void print_str(char *str)
{
	bool flag=true;
	int len=strlen(str);
	for(int i=0; i<len; ++i)
	{
		if(flag && str[i] !='0')
			flag=false;
		if(!flag)
			printf("%c",str[i]);
	}
	printf("\t");
}
void print_max(int n)
{
	if(n<=0)
		return;
	char *str=new char[n+1];
	memset(str,'0',sizeof(str));
	str[n]='\0';
	while(!increment(str))
	{
		print_str(str);
	}
	delete []str;
}

//û�п���n�ܴ��ʱ��
void print_int(int n)
{
	int number=1;
	int i=0;
	while(i++ <n)
		number*=10;
	for(i=1;i<number; ++i)
		printf("%d ",i);
}
/*
class AA
{
private:
	int number;
public:
	explicit AA(int n=0):number(n)
	{
		cout<<"AA ���캯��"<<endl;
	}
	AA(const AA &t):number(t.number)
	{
		//number=t.number;
		cout<<"AA �������캯��"<<endl;
	}
	AA& operator=(const AA &t)
	{
		if(this !=&t)
		{
			number=t.number;
		}
		cout<<"AA ��ֵ���캯��"<<endl;
		return *this;
	}
};					
class BB:public AA
{
private:
	int key;
public:
	explicit BB(int k=0):AA(k),key(k)
	{
		cout<<"BB ���캯��"<<endl;
	}
	BB(const BB &t):AA(t)
	{
		//AA(t.key);
		key=t.key;
		cout<<"BB �������캯��"<<endl;
	}
	BB& operator=(const BB &t)
	{
		AA::operator =(t);
		key=t.key;
		cout<<"BB ��ֵ���캯��"<<endl;
		return *this;
	}
};

/*
//�����������С����
void show(int *arry,int len)
{
	assert(arry !=NULL);
	assert(len > 0);

	int index=0;
	//{12,4,5,17};-->124567
	//4,5,12,17-->1245-->124517==171245
	
	char *str=new char[len+1];
	sprintf(str,"%d",arry[index]);
	char *tmp=new char[len+1];
	while(index < len)
	{									
		sprintf(str,"%d",arry[index+1]);
		tmp=send_str(str,str);
	}
}


/*
//��1��n����������1�ĸ���
int GetNumber(char *str)
{
	if(str==NUll || *str<'0' || *str >'9' || *str=='\0')
		return 0;
	int len=strlen(str);
	if(len==1 && *str=='1')
		return 1;
	if(len==1 && *str !='1')
		return 0;

	int sum=*str-'0';
	int two_sum=0;
	int san_sum=0;
	if(sum >1)
		two_sum=power(len-1);
	else if(sum==1)
		san_sum=atoi(str+1)+1;

}
int get_number(int n)
{
	if(n <=0)
		return 0;
	char buf[SIZE];
	memset(buf,'\0',sizeof(buf));
	sprintf(buf,"%d",n);
	return GetNumber(buf);
}
*/