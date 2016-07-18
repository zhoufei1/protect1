#include<iostream>
using namespace std;

template<typename _Ty>

class scopy_ptr
{
private:
	typedef scopy_ptr<_Ty> type;
	_Ty *pt;
	scopy_ptr(const scopy_ptr<_Ty> &);
	scopy_ptr<_Ty>& operator=(const scopy_ptr&);
public:
	scopy_ptr(_Ty* p=0):pt(p){}

	~scopy_ptr()
	{
		delete pt;
	}
	void reset(_Ty * p = 0)
	{
			type(p).swap(*this);
	}
	void swap(scopy_ptr<_Ty> &b)
	{
		_Ty* tmp=b.pt;
		b.pt=pt;
		pt=tmp;
	}
	_Ty& operator*()const
	{return *(pt);}
	_Ty* get()const
	{return pt;}
	_Ty* operator->()const
	{return pt;}
};

void main()
{
	int *p=new int(10);
	int *q=new int(20);
	scopy_ptr<int> pt(p);
	cout<<*pt<<endl;
	pt.reset(q);
	cout<<*pt<<endl;
}