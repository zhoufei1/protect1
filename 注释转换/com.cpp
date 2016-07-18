#include<iostream>
using namespace std;

int Comment(FILE *inputfile,FILE *outputfile);

typedef enum
{
	ON_START,
	C_START,
	CPP_START,
	STR_START,
	OFF_START
}START_ENUM;

typedef struct
{
	FILE *inputfile;
	FILE *outputfile;
	START_ENUM start;
}START_COMMENT;

START_COMMENT g_start={0};
/////////////////////////////
void EnvertPro(char ch);//环境状态
void EnvertProNo(char ch);//开始环境状态
void EnvertProC(char ch);//C环境状态
void EnvertProCPP(char ch);//C++环境状态
void EnvertProSTR(char ch);//字符串环境状态


int Comment(FILE *inputfile,FILE *outputfile)
{
	if(NULL==inputfile || NULL==outputfile)
	{
		cout<<"失败"<<endl;
		return -1;
	}
	g_start.inputfile=inputfile;
	g_start.outputfile=outputfile;
	g_start.start=ON_START;
	char ch;
	while(g_start.start!=OFF_START)
	{
		ch=fgetc(g_start.inputfile);
		EnvertPro(ch);
	}
	return 0;
}
void EnvertPro(char ch)//环境状态
{
	switch(g_start.start)
	{
	case ON_START:
		EnvertProNo(ch);
		break;
	case C_START:
		EnvertProC(ch);
		break;
	case CPP_START:
		EnvertProCPP(ch);
		break;
	case STR_START:
		EnvertProSTR(ch);
		break;
	case OFF_START:
		break;
	}
}
void EnvertProNo(char ch)//开始状态
{
	char nextch;
	switch(ch)
	{
	case '/':
		nextch=fgetc(g_start.inputfile);
		if(nextch=='/')
		{
			fputc('/',g_start.outputfile);
			fputc('*',g_start.outputfile);
			g_start.start=CPP_START;
		}
		else if(nextch=='*')
		{
			fputc(ch,g_start.outputfile);
			fputc(nextch,g_start.outputfile);
			g_start.start=C_START;
		}
		break;
	case '"':
		fputc(ch,g_start.outputfile);
		g_start.start=STR_START;
		break;
	case EOF:
		g_start.start = OFF_START;
		break;
	default:
		fputc(ch,g_start.outputfile);
		break;
	}
}
void EnvertProCPP(char ch)// /*-->C++
{
	char nextch;
	switch(ch)
	{
	case '/':
		nextch=fgetc(g_start.inputfile);
		if(nextch=='*')
		{
			fputc(' ',g_start.outputfile);
			fputc(' ',g_start.outputfile);
		}
		else
		{
			fputc(ch,g_start.outputfile);
			fputc(nextch,g_start.outputfile);
		}
		break;
	case '*':
		nextch=fgetc(g_start.inputfile);
		if(nextch=='/')
		{
			fputc(' ',g_start.outputfile);
			fputc(' ',g_start.outputfile);
		}
		break;
	case '\n':
		fputc('*',g_start.outputfile);
		fputc('/',g_start.outputfile);
		fputc(ch,g_start.outputfile);
		g_start.start=ON_START;
		break;
	case EOF:
		fputc('*',g_start.outputfile);
		fputc('/',g_start.outputfile);
		g_start.start=OFF_START;
		break;
	default:
		fputc(ch,g_start.outputfile);
		break;
	}
}
void EnvertProC(char ch)// /*-->C
{
	char nextch;
	switch(ch)
	{
	case '*':
		nextch=fgetc(g_start.inputfile);
		if(nextch=='/')
		{
			fputc(ch,g_start.outputfile);
			fputc(nextch,g_start.outputfile);
			g_start.start=ON_START;
		}
		break;
	default:
		fputc(ch,g_start.outputfile);
		break;
	}
}
void EnvertProSTR(char ch)//字符串
{
	switch(ch)
	{
	case '"':
		g_start.start=ON_START;
	default:
		fputc(ch,g_start.outputfile);
		break;
	}

}