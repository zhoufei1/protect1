#pragma once

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#include <stdarg.h>//��trace log����



/////////////////////////////////////////////////////////////////////
//��ӡtrace�������ڴ�������
#define _DEBUG_
static string GetFileName(const string &path)
{
	char ch='/';
#ifdef _WIN32
	ch='\\';
#endif
	size_t pos=path.rfind(ch);
	if(pos==string::npos)
		return path;
	else
		return path.substr(pos+1);
}
inline void __trace_bug(const char *Function,const char *FileName,int line,char *format,...)
{
#ifdef _DEBUG_
	fprintf(stdout," �� %s  %d��: %s",GetFileName(FileName).c_str(),line,Function);
	va_list args;
	va_start(args,format);
	vfprintf(stdout,format,args);
	va_end(args);
#endif
}
#define __TRACE_DEBUG(...)\
	__trace_bug(__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__);
//__FUNCTION__����ǰ����
//__FILE__    �������ļ�
//__LINE__    �������ļ��к�
//__VA_ARGS__ :��һ���ɱ�����ĺ�
/////////////////////////////////////////////////////////////////////

//��ӡ��û���ڴ�����
static inline void print_log()
{
	cerr<<"out of memory"<<endl;
	abort();
}

//һ���ռ�������
template<int inst>
class malloc_alloc
{
private:
	//��Ҫ��Ϊ�˷����ڴ�ʧ�ܺ󲻶ϵĽ����ڴ���䡣ֱ�������ڴ�û��Ϊֹ
	//��ΪҪ�漰�����ڴ���һЩ��ʱ���õ��ڴ�����ͷţ��������л��漰������ϵͳ�ĵ����㷨
	//�����������û�б�����ʵ�֣���������ڴ�ʧ�ܾ�ֱ���˳�����
	static void* oom_malloc(size_t n); 
	//��Ҫ�Ƕ��ڴ�ռ��С���·��䣬ͬ��Ҳû��ʵ��
	static void* oom_realloc(void* ,size_t n);
	//��Ҫ�����þ���������ǵ��ڴ���û���㹻������ڴ�ʱ���ã�ͬ��Ҳû�б�ʵ��
	static void* (*__malloc_alloc_oom_handler)();
public:
	//�����ڴ�
	static void* allocate(size_t n)
	{
		__TRACE_DEBUG("һ���ռ������������ڴ�����%d bit\n", n);
		void *result=(void*)malloc(n);
		if(0 == result)
		{
			//������������ֱ���׳��쳣,ģ��c++��ʵ�ַ�ʽ
			print_log();
		}
		return result;
	}
	//�ͷ��ڴ�ռ�
	static void dellocate(void *p,size_t n)
	{
		__TRACE_DEBUG("һ���ռ��������ͷ��ڴ�飺%p\t%dbit\n",p,n);
		free(p);
		//��ֹҰָ��
		p=NULL;
	}
	//���·����ڴ�
	static void* reallocate(void *p,size_t n)
	{
		__TRACE_DEBUG("һ���ռ����������·����ڴ�����%d bit\n", n);
		void *result=realloc(p,n);
		if(0 == result)
		{
			print_log();
		}
		return result;
	}
};


//�����ռ�������
template<bool Threads,int inst>
class DefaultAllocTemplate
{
private:
	enum {ALIGN=8};      //С��������ϵ��߽�
	enum {MAX_BYTES=128};//С�����������
	enum {NFREELISTS=MAX_BYTES/ALIGN};//��������ĸ���,���ֻ��Ҫ16�������С������
private:
	//�ϵ�������ֽ�����8�ı���
	static size_t ROUND_UP(size_t bytes)
	{
		//�������5���ֽ�--��(5+8-1) & ~(8-1)
		return ( ((bytes)+ALIGN-1) & ~(ALIGN-1) );
	}
	//Ѱ�ҵ�n������������±���0~n��ʼ
	static size_t FREELIST_INDEX(size_t bytes)
	{
		//����Ѱ�ҵ��ֽ�����С��35bytes,�� (35+8-1)/8 -1=4
		return ((bytes + ALIGN-1)/ALIGN -1);
	}
private:
	//��������
	union obj
	{
		union obj *FreeListLink;
		char ClientData[1];
	};
private:
	//�ڴ�صĽṹ
	static char *StartFree;
	static char *EndFree;
	static size_t HeapSize;
private:
	//�����������飬��СΪ16
	static obj* volatile FreeList[NFREELISTS];
	//����һ����СΪn�Ķ��󣬲����ܼ����СΪn���������鵽����������
	static void* ReFill(size_t n);
	//����һ���ռ䣬�����ɴ�СΪsize������
	static char* ChunkAlloc(size_t size,size_t &nobjs);
private:
	class lock
	{
		HANDLE m_mutex;
	public:
		 lock() 
		 { 
			 cout<<"[************ lock ************]"<<endl;
			 m_mutex=::CreateMutex(NULL,false,NULL);
		 }
         ~lock() 
		 {
			 cout<<"[************ unlock ************]"<<endl;
			 ::ReleaseMutex(m_mutex);
		 }
    };
    friend class lock;
public:
	//�����ڴ�
	static void* Allocate(size_t n);
	//�ͷ��ڴ�
	static void DeAllocate(void *p,size_t);
	//���·����ڴ�
	static void* ReAllocate(void *p,size_t old_size,size_t new_size);
};

template<bool Threads,int inst>
char* DefaultAllocTemplate<Threads,inst>::StartFree=0;

template<bool Threads,int inst>
char* DefaultAllocTemplate<Threads,inst>::EndFree=0;

template<bool Threads,int inst>
size_t DefaultAllocTemplate<Threads,inst>::HeapSize=0;

template<bool Threads,int inst>
typename DefaultAllocTemplate<Threads,inst>::obj* volatile
DefaultAllocTemplate<Threads,inst>::FreeList[NFREELISTS]={0};


template<bool Threads,int inst>
void* DefaultAllocTemplate<Threads,inst>::Allocate(size_t n)
{
	//��������ڴ����128�ֽڣ������һ���ռ�������
	if(n > (size_t)MAX_BYTES)
		return malloc_alloc<0>::allocate(n);
	__TRACE_DEBUG("�����ռ������������ڴ�����%d bit\n",ROUND_UP(n));
	void *result=0;//��Ҫ���ص�������ڴ�

	//��Ѱ���ֽ�����λ�õ��±�
	size_t index=FREELIST_INDEX(n);

	lock lock_instance;
	//��ʾ���������л�û���ڴ棬��ʱ����������������ڴ棬����ʼ���ڴ��
	if(FreeList[index]==0)
		result=ReFill(ROUND_UP(n));
	else
	{
		//ȡ�������ͷ����
		result=FreeList[index];
		//�������ͷָ���������һ���ڵ�
		//FreeList[index]=((obj*)result)->FreeListLink;
		FreeList[index]=(FreeList[index])->FreeListLink;
	}
	return result;
}

template<bool Threads,int inst>
void DefaultAllocTemplate<Threads,inst>::DeAllocate(void *p,size_t n)
{
	//�������128����һ���ռ�����������
	if(n > (size_t)MAX_BYTES)
		malloc_alloc<0>::dellocate(p,n);
	else
	{
		__TRACE_DEBUG("�����ռ������������ڴ�أ�%dbit\n",ROUND_UP(n));
		//�ò��õ��ڴ����������������ȥ
		//�����ҵ���Ҫ�����λ��
		size_t index=FREELIST_INDEX(n);
		//����
		lock lock_instance;
		//���ҵ�λ�õ�ָ�����ӵ�p��next�ϣ�����pָ���ҵ�λ�õĵ�ַ��
		((obj*)p)->FreeListLink=FreeList[index];
		FreeList[index]=(obj*)p;
	}
}

//���·����ڴ�
template<bool Threads,int inst>
void* DefaultAllocTemplate<Threads,inst>::ReAllocate(void *p,size_t old_size,size_t new_size)
{
	//�����Ҫ���ӵ��ڴ��֮ǰ���ڴ���Ҵ���128ʱ����һ���ռ�������
	if(old_size > (size_t)MAX_BYTES && new_size > (size_t)MAX_BYTES)
		return malloc_alloc<0>::reallocate(p,new_size);
	//����ϵ��������ֽڴ�С��ȣ���ֱ�ӷ��أ��������������ԭ���ǰ�8�ı�������
	if(ROUND_UP(old_size) == ROUND_UP(new_size))
		return p;
	__TRACE_DEBUG("�����ռ����������·����ڴ�����%d bit\n", ROUND_UP(n));
	void *result=0;
	size_t copy_size=0;
	//������ռ��С
	result=Allocate(new_size);
	//�������Ҫ�������ֽ���������ע��
	copy_size=new_size > old_size?old_size : new_size;
	memcpy(result,p,copy_size);
	//�ͷ�֮ǰ���ڴ�
	DeAllocate(p,old_size);
	return result;
}


//�����������������ĵĺ������е��˴����ڴ�ص�����
template<bool Threads,int inst>
char* DefaultAllocTemplate<Threads,inst>::ChunkAlloc(size_t size, size_t &nobjs)
{
	char *result=0;
	size_t total_bytes=size * nobjs; //�ܹ����ֽ���
	size_t bytes_left=EndFree-StartFree;//�ڴ���л�ʣ����ڴ��С
	//���ʣ���ڴ��㹻��ֱ�ӷ���
	if(bytes_left >=total_bytes)
	{
		result=StartFree;
		StartFree+=total_bytes;
		return result;
	}else if(bytes_left >=size)//��Ȼʣ���ڴ治�㣬���������size��С��
	{
		nobjs=bytes_left/size;//����ڴ�Ӧ�ñ����䵽�������±�
		total_bytes=size *nobjs;//�ܹ����ֽ���

		//�����������������ʼλ�ã����ı������������ʼλ��
		result=StartFree;
		StartFree+=total_bytes;
		return result;
	}else
	{	
		//�����л�û�����������ٵ��ڴ��ʱ�����Ѿ�����������ʱ
		size_t bytes_to_get=2*total_bytes+ROUND_UP(HeapSize>>4);
		__TRACE_DEBUG("�ڴ��û�пռ䣬���ڷ���ռ��С��%d bit\n", bytes_to_get);
		//���ſ�������û�в�����õ��ڴ��
		if(bytes_left >0)
		{
			size_t index=FREELIST_INDEX(bytes_left);
			((obj*)StartFree)->FreeListLink=FreeList[index];
			FreeList[index]=(obj*)StartFree;
			EndFree=StartFree+bytes_left;
		}
		//����һ���µ��ڴ��
		StartFree=(char*)malloc(bytes_to_get);
		//�������ʧ��
		if(StartFree ==0)
		{
			//��������л���û�п��õ��ڴ��
			for(size_t i=size; i<=MAX_BYTES; i+=ALIGN)
			{
				size_t index=FREELIST_INDEX(i);
				if(FreeList[index])
				{
					//��ʾ�ҵ��ˣ�Ȼ��ı����������ͷ��β��Ȼ��ݹ��ȥ�����ڴ�
					//���Ǵ�һ������ڴ�����һ�����ʹ��
					obj *start=FreeList[index];
					StartFree=(char*)start;
					FreeList[index]=start->FreeListLink;
					EndFree=StartFree+i;
					return ChunkAlloc(size,nobjs);
				}
			}
			//���û���ҵ���ֱ�ӵ���һ���ռ�������ȥ����
			StartFree=(char*)malloc_alloc<0>::allocate(bytes_to_get);
		}
		//��ʾ�����ڴ�ɹ�
		//�ı����������βָ�룬Ȼ��ݹ�����ڴ�
		EndFree=StartFree + bytes_to_get;
		HeapSize+=bytes_to_get;
		return ChunkAlloc(size,nobjs);
	}
}


template<bool Threads,int inst>
void* DefaultAllocTemplate<Threads,inst>::ReFill(size_t n)
{
	size_t nobjs=20;//����SGI��ϵͳ�趨�ĳ�ʼֵ
	char *chunk=ChunkAlloc(n,nobjs);//����Ѱ���ڴ��
	__TRACE_DEBUG("�����ռ��������ҵ��ڴ�ط��䣺n: %d bit  nobjs : %d \n", n,nobjs);
	if(1==nobjs)
		return chunk;
	obj *cur=(obj*)(chunk+n);
	//Ѱ���ֽ��������е��±�
	size_t index=FREELIST_INDEX(n);
	FreeList[index]=cur;
	//����ϵͳ�����뵽���ڴ�����ӵ�����������
	for(size_t i=2; i<nobjs; ++i)
	{
		//���õ�β��ķ�ʽ���������Ա�֤���ǵĵ�ַ����
		obj *next=(obj*)(chunk+n*i);
		cur->FreeListLink=next;
		cur=next;
	}
	//������������Ϊ0
	cur->FreeListLink=0;
	//���ص��ǵ�һ���ڴ棬�ӵڶ������ڴ����ӵ�����������
	return chunk;
}