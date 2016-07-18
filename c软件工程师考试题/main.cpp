#include<iostream>
using namespace std;


/*写一个函数，找出给定字符串中数字字符
（即’0’—‘9’这10个数字）的个数
（如字符串”olympic2000”中数字字符的个数为4个。
函数的原型为：int CalcDigital(char *str);*/
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
//用递归函数完成以下运算：sum(n)=1^2+2^2+3^2+4^2…+n^2   n>0。

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