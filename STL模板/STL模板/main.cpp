#include "file.h"

int *ptr=new int(20);
int *str=new int(30);
void fun()
{
	int i=0;
	int *key=ptr;
	while(i <5)
	{
		if(i==1)
			ptr=str;
		i++;
	}
}
int main()
{
	TestAA();
	//TestList();
	//fun();
	//TestVector();
	return 0;
}