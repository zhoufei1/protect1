#include "sort.h"

int main()
{
	int arr[]={1,8,9,3,2,5,1,6,3,7,8};
	int len=sizeof(arr)/sizeof(*arr);
	print_log(arr,len);
	//shell_sort(arr,0,len);
	//insert_sort(arr,0,len);
	//bubble_sort(arr,len);
	//select_sort(arr,len);
	print_log(arr,len);
	return 0;
}