
#include <iostream>
#include <string.h>
using namespace std;

class Singleton
{
public:
	static Singleton* Get()
	{
		if(ptr ==NULL)
		{
			lock(mutex);
			ptr=new Singleton;
		}
		return ptr;
	}
	void show()const
	{
		cout<<"show"<<endl;
	}
private:
	Singleton(int x=10)
	{
	}
private:
	static Singleton *ptr;
	pthread_mutex_t mutex;
};

Singleton* Singleton::ptr=NULL;

void Test()
{
	Singleton *t=Singleton::Get();
	t->show();
	cout<<"t :"<<t<<endl;
	Singleton *tmp=Singleton::Get();
	cout<<"tmp :"<<tmp<<endl;
}