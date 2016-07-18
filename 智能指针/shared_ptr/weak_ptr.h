

//#include"shared_count.h"

/*
template<class T>
class shared_count;

template<class T>
class weak_count
{
private:
	friend class shared_count<T>;
    count_base * pi_;
public:
	weak_count(): pi_(0){}
	weak_count(shared_count<T> const & r): pi_(r.pi_)
	{
		 if(pi_ != 0) pi_->weak_add_ref();
	}
	weak_count(weak_count<T> const & r): pi_(r.pi_) 
	{
		 if(pi_ != 0) pi_->weak_add_ref();
	}
	~weak_count() // nothrow
    {
        if(pi_ != 0) pi_->weak_release();
	}
	weak_count<T> & operator= (shared_count<T> const & r) // nothrow
    {
        count_base<T> * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if(tmp != 0) tmp->weak_add_ref();
            if(pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }

        return *this;
    }

	 weak_count<T> & operator= (weak_count<T> const & r) // nothrow
    {
        count_base<T> * tmp = r.pi_;

        if( tmp != pi_ )
        {
            if(tmp != 0) tmp->weak_add_ref();
            if(pi_ != 0) pi_->weak_release();
            pi_ = tmp;
        }
        return *this;
    }

	 void swap(weak_count<T> & r) // nothrow
    {
        count_base<Type> * tmp = r.pi_;
        r.pi_ = pi_;
        pi_ = tmp;
    }

	 long _use_count() const // nothrow
    {
        return pi_ != 0? pi_->_use_count(): 0;
    }

    bool empty() const // nothrow
    {
        return pi_ == 0;
    }
};*/