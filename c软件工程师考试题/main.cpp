#include<iostream>
using namespace std;


/*дһ���������ҳ������ַ����������ַ�
������0������9����10�����֣��ĸ���
�����ַ�����olympic2000���������ַ��ĸ���Ϊ4����
������ԭ��Ϊ��int CalcDigital(char *str);*/
int CalcDigital(char *str)
{
	if(str==NULL)
		return 0;
	int count=0;

	while(*str!='\0')
	{
		if(*str>='0'&& *str<='9')
			count++;
		str++;
	}
	return count;
}
//�õݹ麯������������㣺sum(n)=1^2+2^2+3^2+4^2��+n^2   n>0��

long sum(int n)
{
	if(n==1)
		return 1.0;
	else
	{
		return n*n+sum(n-1);
	}
}
void main()
{
	cout<<sum(4)<<endl;
	cout<<CalcDigital(NULL)<<endl;
}