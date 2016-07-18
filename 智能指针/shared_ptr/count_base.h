
#ifndef _BB_H_
#define _BB_H_

#include<iostream>
using namespace std;
class count_base
{
private:
	count_base(const count_base &);
	count_base& operator=(const count_base& );
	
	long user_count_;
	long weak_count_;    
public:
	count_base():user_count_(1),weak_count_(1){}

	virtual ~count_base()
	{}

	virtual void dispose() = 0;

	virtual void destroy() // nothrow
    {
        delete this;
    }

	void add_ref_copy()
    {
		++user_count_;
	}
	 void release() 
	 {
		 if(--user_count_==0)
		 {
			 dispose();
			  weak_release();
		 }
	 }
	 void weak_add_ref()
	 {
		 ++weak_count_;
	 }

	 void weak_release() 
	 {
		 if(--weak_count_==0)
			 destroy();
	 }

	long _user_count_()const
	{return user_count_;}
};
#endif