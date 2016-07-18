#include<iostream>
using namespace std;
#include<string.h>

void* memmove(void *result,const void *str,size_t size)
{
	if(result==NULL || str==NULL ||size==0)
		return NULL;

	char *Result=(char*)result;//bcdefgh
	char *Str=(char*)str;   //abcdefgh

	if(Str+size > Str+strlen(Str))
		return NULL;

	if(Result != (Str+1))
	{
		while(size--)
		{
			*Result++=*Str++;
		}
	}
	else
	{
		Result=Result+size-1;
		Str=Str+size-1;
		while(size--)
		{
			*Result--=*Str--;
		}
	}
	return result;
}

/*void *memmove(void* dst,const void* src, size_t count)  
{  
//    assert((dst!=NULL)&&(src!=NULL));  
    char *pDst=(char *)dst;  
     char *pSrc=(char *)src;  
    //不存在重叠的内存区域  
    if((pDst<=pSrc)||(pDst>=pSrc+count))  
    {  
        while(count--)  
        {  
            *pDst++=*pSrc++;  
        }  
    }  
    else  
    //存在重叠区域，从尾部开始  
    {  
        pDst+=count-1;  
        pSrc+=count-1;  
        while(count--)  
        {  
            *pDst--=*pSrc--;  
          
        }  
    }  
    return dst;  
} */
void main()
{
	char str[]="abcdefgh";
	int length=strlen(str);
	char *result=new char[length+1];

	memmove(str+1,str,5);
//	memmove(str,str+1,5);
	cout<<str<<endl;
	//cout<<(char*)result<<endl;
}