

#ifndef _CC_H_
#define _CC_H_

#include"count_base.h"

template<class X>
class counted_implp_p:public count_base
{
private:
	X *px_;
	counted_implp_p(const counted_implp_p&);
	counted_implp_p& operator=(const counted_implp_p&);
public:

	counted_implp_p(X *px):px_(px){}

	virtual ~counted_implp_p()
	{
		delete px_;
	}
	virtual void dispose() 
	 {
		 delete this;
	 }
};
#endif