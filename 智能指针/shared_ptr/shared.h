

#ifndef _DD_H_
#define _DD_H_

#include"shared_count.h"
#include"weak_ptr.h"

template<class T>
class weak_ptr;

template<class T>
class shared_ptr
{
private:
	friend class weak_ptr<T>;
	typedef shared_ptr<T> this_type;
	T *pt;
	shared_count<T> pn;
public:
	shared_ptr():px(0),pn(){}

	shared_ptr(T *p):pt(p),pn(p){}

	~shared_ptr()
	{}
	shared_ptr(const shared_ptr<T>& t):pt(t.pt),pn(t.pn){}

	shared_ptr & operator=( shared_ptr const & r ) // never throws
    {
        this_type(r).swap(*this);
        return *this;
    }
public:
	shared_ptr(weak_ptr<T> const & r): pn(r.pn),pt(r.pt){}

	void reset(T * p) 
    {
        assert(p == 0 || p != px);
        this_type(p).swap(*this);
    }

	bool unique() const // never throws
    {
        return pn.unique();
    }
public:
	void reset() // never throws in 1.30+
    {
        this_type().swap(*this);
    }

	
	void swap(shared_ptr<T> & other) // never throws
    {
        std::swap(pt, other.pt);
        pn.swap(other.pn);
    }

	T* get()const
	{return pt;}
	T& operator*()const
	{return *(get());}
	T* operator->()const
	 {return get();}

	long user_count()const
	 {return pn._user_count();}
};


#endif