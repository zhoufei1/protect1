#include "Malloc.h"

//#define n 1000000000000 ���ܷ���ɹ�   1T
//#define n 100000000000   �����ܷ���ɹ��ļ��ޣ���100G
#define n 10
int main()
{
	Malloc<int> t;
	//int *p=t.MallocAllocate(12);
	//t.MallocDeAllocate(p);
	int *q=t.MallocAllocate(n);
	t.MallocDeAllocate(q,n);
	return 0;
}