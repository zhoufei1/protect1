#include<iostream>
using namespace std;
#include<vld.h>
#include<memory>



template<typename _Ty>
class Auto_ptr
{
public:
	Auto_ptr(_Ty *_P=0):_Ptr(_P){}

	Auto_ptr( Auto_ptr<_Ty> &_Y):_Ptr(recepe(_Y)){}

	Auto_ptr<_Ty>& operator=( Auto_ptr<_Ty> &_P)
	{
		if(this!=&_P)
		{
			delete _Ptr;
			_Ptr=recepe(_P);
		}
		return *this;
	}

	_Ty* get()
	{return _Ptr;}
	_Ty operator*()const
	{ return *_Ptr;}
	_Ty* operator->()const
	{return _Ptr;}
	~Auto_ptr()
	{
		delete _Ptr;
	}

	_Ty* recepe( Auto_ptr<_Ty>&_P)//Auto_ptr<_Ty>* (_S._Ptr)=new Auto_ptr<_Ty>;
	{
		//delete _Ptr;
		_Ptr=NULL;
		_Ptr=new _Ty;
		*(_Ptr)=*(_P._Ptr);
		delete _P._Ptr;
		return _Ptr;
	}

private:
	_Ty* _Ptr;
};

void main()
{
	int *p=new int(10);
	int *q=new int(20);

	//Auto_ptr<int> pt(p); auto_ptr<int> qt=pt;  qt=pt; 这种方式的话这两句就不能被执行

	Auto_ptr<int> pt(p);
	Auto_ptr<int> qt(q);
	qt=pt;
	cout<<"*pt="<<*pt<<endl;
	cout<<"*qt="<<*qt<<endl;
	//delete p;
}
/*

template<typename _Ty>
class Auto_ptr
{
public:
	Auto_ptr(_Ty *_P=0):_Ptr(_P),_Owns(_P!=0){}
	//Auto_ptr(const Auto_ptr<_Ty> &_Y):_Ptr(_Y.recepe()),_Owns(_Y._Owns){}

	Auto_ptr(const Auto_ptr<_Ty> &_Y):_Ptr(_Y.recepe()),_Owns(_Y._Owns){}

	Auto_ptr<_Ty>& operator=(const Auto_ptr<_Ty> &_P)
	{
		if(this!=&_P)
		{
			if(this!=&_P)
			{
				if(_Owns)
					delete _Ptr;
				_Owns=_P._Owns;
			}
			else if(_P._Owns)
				_Owns=true;
			_Ptr=_P.recepe();
		}
		return *this;
	}
	_Ty* get()const
	{return _Ptr;}
	_Ty operator*()const
	{ return *_Ptr;}
	_Ty* operator->()const
	{return _Ptr;}

	~Auto_ptr()
	{
		if(_Owns)
			delete _Ptr;
	}

	_Ty* recepe()const
	{
	((Auto_ptr<_Ty> *)this)->_Owns=false;return _Ptr;}
private:
	_Ty* _Ptr;
	bool _Owns;
};

void main()
{
	int *p=new int(10);
	int *q=new int(20);

	
	Auto_ptr<int> pt(p);
	Auto_ptr<int> qt(q);
	qt=pt;
	cout<<"*pt="<<*pt<<endl;
	cout<<"*qt="<<*qt<<endl;
}*/