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
		cout<<"���ļ�ʧ��"<<endl;
		return;
	}
	fout=fopen("outputfile.c","w");
	if(NULL==fout)
	{
		cout<<"���ļ�ʧ��"<<endl;
		return;
	}

	Comment(fin,fout);

	cout<<"ת���ɹ���"<<endl;
	fclose(fin);
	fclose(fout);
}