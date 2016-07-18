#include<iostream>
using namespace std;

extern int Comment(FILE *inputfile,FILE *outputfile);

void main()
{
	FILE *fin=NULL;
	FILE *fout=NULL;
	fin=fopen("inputfile.c","r");
	if(NULL==fin)
	{
		cout<<"打开文件失败"<<endl;
		return;
	}
	fout=fopen("outputfile.c","w");
	if(NULL==fout)
	{
		cout<<"打开文件失败"<<endl;
		return;
	}

	Comment(fin,fout);

	cout<<"转换成功！"<<endl;
	fclose(fin);
	fclose(fout);
}