
/*
дһ���������жϵ�ǰϵͳ�Ĵ�С��ģʽ
����1�����ˣ�����0����С��
int GetSystemType()
{

}
*/
//�û��������һ���ַ�����ͳ���ַ����������֣���ĸ�������ַ��ĳ��ִ���
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
	printf("ͳ�ƺ�Ľ��:\n");
	printf("%d\t%d\t%d\n",digitNumber,letterNumber,otherNumber);

	return 0;
}