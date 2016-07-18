#include"String.h"

void Show()
{
	cout<<"*********************************************"<<endl;
	cout<<"*[1]:  ³õÊ¼»¯×Ö·û´®         [2]:¿½±´×Ö·û´®  *"<<endl;
	cout<<"*[3]:  ±È½Ï×Ö·û´®           [4]:Çó×Ö·û´®³¤¶È*"<<endl;
	cout<<"*[5]:  ÏÔÊ¾×Ö·û´®           [6]:ÇåÀí×Ö·û´®  *"<<endl;
	cout<<"*[7]:  Á´½Ó×Ö·û´®           [8]:»ñÈ¡×Ó´®    *"<<endl;
	cout<<"*[9]:  Æ¥Åä×Ö·û´®           [10]:Ìæ»»×Ö·û´® *"<<endl;
	cout<<"*[11]: ²åÈë×Ö·û´®           [12]:°´Î»É¾³ý   *"<<endl;
	cout<<"*[13]: ´Ý»Ù×Ö·û´®           [0]:½áÊø³ÌÐò    *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<"ÇëÑ¡Ôñ£º";
}
int Length(SString s)
{
	return strlen(s);
}

void StringConcat(SString T, SString s1, SString s2)
{	
	for(int i=0;i<Length(s1);i++)
	{
		T[i]=s1[i];
	}
	for(int j=0;j<Length(s2);j++)
	{
		T[i+j]=s2[j];
	}
	T[i+j]='\0';
}

void PrintString(char T[])
{
	cout<<T<<endl;
}

void StrAssign(SString T, char *str)
{
	for(int i=0;i<Length(T);i++)
	{
		T[i]=str[i];
	}
	T[i]='\0';
}

void StrCopy(SString T, SString S)
{
	for(int i=0;i<=Length(T);i++)
	{
		T[i]=S[i];
	}
}

bool StrEmpty(SString S)
{
	return S[0]=='\0';
}

int StrCompare(SString T, SString S)
{
	int i=0;
	while(T[i]!='\0' || S[i]!='\0')
	{
		if(T[i]> S[i])
			return 1;
		if(T[i]< S[i])
			return -1;
		else
			i++;
	}
	return 0;
}

void ClearString(SString S)
{
	S[0]='\0';
}

void SubString(SString D, SString S, int pos, int len)
{
	if(pos<0 || pos>Length(S))
		return;
	if(len>Length(S)-pos+1)
		return;
	for(int i=0;i<len;i++)
	{
		D[i]=S[i+pos];
	}
	D[i]='\0';
}

void StrInsert(SString D, int pos, SString T)
{
	int t_length=Length(T);
	int d_length=Length(D);

	for(int i=d_length;i>=pos;i--)
	{
		D[i+t_length]=D[i];
	}
	for(i=0;i<t_length;i++)
	{
		D[pos+i]=T[i];
	}
}

int Index(SString T, int pos, SString P)
{
	int t_length=Length(T);
	int p_length=Length(P);

	for(int i=pos;i<t_length-p_length;i++)
	{
		for(int j=0;j<p_length;j++)
		{
			if(T[i+j]==P[j])
				continue;
			else
				break;
		}
		if(j==p_length)
			return i;
	}
	return -1;
}

void Replace(SString T, SString P, SString V,int pos)
{
	int ret=Index(T,pos,P);
	if(-1==ret)
	{
		cout<<"Ã»ÓÐÕÒµ½ÐèÒªÌæ»»µÄÎ»ÖÃ,³ÌÐò½áÊø"<<endl;
		return;
	}
	int v_length=Length(V);

	for(int i=0;i<v_length;i++)
	{
		T[i+ret]=V[i];
	}
}
void StrDelete(SString T, int pos, int len)
{
	if(pos<0 || pos>=Length(T))
		return;
	if(pos+len>Length(T))
		return;
	for(int i=0;i<=Length(T)-pos-len;i++)
	{
		T[i+pos]=T[i+len+pos];
	}
}
void DestroyString(SString S)
{
	S[0] = '\0';
}
