
/*
写一个函数，判断当前系统的大小端模式
返回1代表大端，返回0代表小端
int GetSystemType()
{

}
*/
//用户随机输入一段字符串，统计字符串里面数字，字母，其他字符的出现次数
#include <stdio.h>
#define MAX 1024

int main(int argc, char **argv)
{
	int letterNumber=0;
	int digitNumber=0;
	int otherNumber=0;
	char input[MAX]={0};
	
	puts("please input strings:");
	gets(input);
    for(int i=0;(input[i])!='\0';i++)
	{
		if(input[i]>='A' && input[i]<='Z' || input[i]>='a' && input[i]<='z')
		{
			++digitNumber;
		}
		else if(input[i]>='0' && input[i]<='9')
		{
			++letterNumber;
		}
		else
			++otherNumber;
	}
	printf("统计后的结果:\n");
	printf("%d\t%d\t%d\n",digitNumber,letterNumber,otherNumber);

	return 0;
}