#include<iostream>
using namespace std;
#include<vld.h>

#define N 10

template<typename _Ty>
class scoped_array
{
private:
	_Ty *pt;
	scoped_array(const scoped_array<_Ty> &);
	scoped_array& operator=(const scoped_array<_Ty> &);
	void operator==(const scoped_array<_Ty> &);
	void operator!=(const scoped_array<_Ty> &);
public:
	scoped_array(_Ty *p=0):pt(p){cout<<"构造函数"<<endl;}
	~scoped_array()
	{
		cout<<"析构函数"<<endl;
		delete []pt;
	}

	typedef scoped_array<_Ty> type;
	void reset(_Ty * p = 0)
	{
			type(p).swap(*this);
	}
	void swap(scoped_array<_Ty> &b)
	{
		_Ty* tmp=b.pt;
		b.pt=pt;
		pt=tmp;
	}
	
	_Ty* operator+(size_t i)
	{
		return pt+i;
	//	return (&pt[i]);
	}
	
	_Ty* operator*()const
	{return pt;}
	
	_Ty& operator[](size_t i)const
	{return pt[i];}
};


void main()
{
	int *p=new int[N];
	for(int i=0;i<N;++i)
	{
		p[i]=i+10;
	}
	
	scoped_array<int> pt(p);
	for(i=0;i<N;++i)
	{
	//	cout<<p[i]<<" ";
	//	cout<<pt[i]<<" ";
		cout<<*(pt+i)<<" ";
	}
	cout<<endl;
}