
#pragma once
#pragma warning( disable : 4996) 

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <map>
#include <assert.h>
#include <stdarg.h>
//#include <unordered_map>

using namespace std;

const int BUF_SIZE=128;
typedef long long LongType;

struct SaveAdapter
{
	virtual  void SaveFile(char *format,...)=0;
};
struct ConsoleSaveAdapterBase:public SaveAdapter
{
	void SaveFile(char *format,...)
	{
		va_list arges;
		va_start(arges,format);
		vfprintf(stdout,format,arges);
		va_end(arges);
	}
};

struct ConsoleSaveAdapter:public ConsoleSaveAdapterBase
{
public:
	void FopenFile(const char *path)
	{
		out=fopen(path,"w");
		assert(out);
	}
	void SaveFile(char *format,...)
	{
		va_list arges;
		va_start(arges,format);
		vfprintf(out,format,arges);
		va_end(arges);
	}
private:
	FILE *out;
};


//����������Node
struct PerformanceNode
{
	string FileName; //�ļ���
	size_t Line;     //�к�
	string Function; //����
	string Desc;     //Դ�ļ�
public:
	PerformanceNode(const char*file,size_t line,const char *fun,const char *desc)
		:FileName(file)
		,Line(line)
		,Function(fun)
		,Desc(desc)
	{}
public:
	bool operator==(const PerformanceNode& t)const
	{
		return (Line==t.Line && FileName==t.FileName);
	}
	bool operator <(const PerformanceNode& t)const
	{
		return true;
		//return Line<t.Line;
	}
	void SaveFile(SaveAdapter &s)
	{
		s.SaveFile("desc:%s\n FileName:%s Line:%d function:%s\n",Desc.c_str(),FileName.c_str()\
			,Line,Function.c_str());
	}
};
//��������ε�ͳ����Ϣ
class PerformanceSection
{
public:
	PerformanceSection()
		:CurTime(0)
		,CostTime(0)
		,CallCount(0)
		,RefCount(0)
	{}
public:
	bool operator==(const PerformanceSection& t)const
	{
		return CurTime==t.CostTime && CostTime==t.CostTime && CallCount==t.CallCount;
	}
	bool operator <(const PerformanceSection& t)const
	{
		return true;
	}
public:
	void Begin()
	{
		if(RefCount==0)
			CurTime=clock();//��ȡ��ǰʱ��
		++RefCount;
		++CallCount;
	}
	void End()
	{
		if(RefCount <=0)
			cout<<"������û��"<<endl;
		if(--RefCount==0)
			CostTime+=clock()-CurTime;
	}
public:
	void SaveFile(SaveAdapter &s)
	{
		s.SaveFile("Curtime:%f Costtime:%f callcount:%f\n",CurTime,CostTime,CallCount);
	}
	void begin(int id)
	{
		if(ref_count[id]++==0)
			start_time[id]=clock();
		call_count[id]++;
	}
protected:
	//������̵߳Ķ������
	//�߳�id��
	map<int,LongType> start_time;
	map<int,LongType> cost_time;
	map<int,LongType> call_count;
	map<int,LongType> ref_count;
protected:
	LongType CurTime;  //��ǰʱ��
	LongType CostTime; //����ʱ��
	LongType CallCount;//���ô���
	size_t RefCount;   //���ü���--������ݹ�ĳ���
};


//�º���
struct PerformanceHash
{
public:
	static size_t SerachFunc(const char *str)
	{
		assert(str !=NULL);
		size_t seed=131;
		size_t hash=0;
		while(*str)
		{
			hash=hash*seed+(*str++);
		}
		return (hash &0x7fffffff);
	}
	size_t operator()(const PerformanceNode &node)
	{
		static char buf[BUF_SIZE];
		memset(buf,'\0',sizeof(buf)*BUF_SIZE);
		string hash=node.FileName;
		hash+=node.Line;
		return SerachFunc(hash.c_str());
	}
};




//��������������,�õ���ʵ��
template<class Type>
class PerformanceBase
{
public:
	static Type* GetInsert()
	{
		return Inserce;
	}
protected:
	static Type* Inserce;
protected:
	PerformanceBase()
	{}
	PerformanceBase(const PerformanceBase&);
	PerformanceBase& operator=(const PerformanceBase&);
};
template<class Type>
Type* PerformanceBase<Type>::Inserce=new Type;

//������������
class Performance:public PerformanceBase<Performance>
{
	friend class PerformanceBase<Performance>;
	typedef map<PerformanceNode,PerformanceSection*> Map;
	//typedef map<PerformanceNode,PerformanceSection*,PerformanceHash> Map;
private:
	Map MapNode;
	Performance()
	{}
public:
	PerformanceSection* GetSection(const char *file,size_t line,const char *fun,const char *desc)
	{
		//�ȹ������
		PerformanceNode node(file,line,fun,desc);
		PerformanceSection* Senction=NULL;
		//Ȼ���ȥ�����Ƿ�������
		Map::iterator it=MapNode.begin();
		if(it !=MapNode.end())
			Senction=it->second;
		else
		{
			Senction=new PerformanceSection;
			//��֤�������ظ�
			MapNode.insert(pair<PerformanceNode,PerformanceSection*>(node,Senction));
			//MapNode[node]=Senction;
		}
		//PerformanceSection* &Senction=MapNode[node];
		//if(Section ==NULL)
		//	Section=new PerformanceSection;
		return Senction;		
	}
	void OutPut()
	{

	}
};



void Test()
{
	Performance *p;
}

//���⣿��
//1���ݹ���---�������ü������
//2�����̴߳��ڵ����⣿---������