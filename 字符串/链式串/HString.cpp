#include"HString.h"

void Show()
{
	cout<<"*********************************************"<<endl;
	cout<<"*[1]:  ³õÊ¼»¯×Ö·û´®        [2]:¿½±´×Ö·û´®   *"<<endl;
	cout<<"*[3]:  ±È½Ï×Ö·û´®          [4]:Çó×Ö·û´®³¤¶È *"<<endl;
	cout<<"*[5]:  ÏÔÊ¾×Ö·û´®          [6]:ÇåÀí×Ö·û´®   *"<<endl;
	cout<<"*[7]:  Á´½Ó×Ö·û´®          [8]:°´Î»ÖÃµÃ×Ó´® *"<<endl;
	cout<<"*[9]:  Æ¥Åä×Ö·û´®          [10]:Ìæ»»×Ö·û´®  *"<<endl;
	cout<<"*[11]: ²åÈë×Ö·û´®          [12]:°´Î»É¾³ý    *"<<endl;
	cout<<"*[13]: ´Ý»Ù×Ö·û´®          [0]:½áÊø³ÌÐò     *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<"ÇëÑ¡Ôñ£º";
}
int StrDelete(HString *T, int pos, int len)
{
	if((pos+len)>T->length)
		return -1;
	char *ret=T->ch;
	int i=0;
	while(i<len)//abcdefg
	{
		ret[pos+i]=ret[i+pos+len];
		i++;
	}
	return 1;
}
void StrInsert(HString *D, int pos, HString *T)
{
	if(pos<0)
		return;
	char *ret=D->ch;
	for(int i=D->length;i>pos;i--)
	{
		ret[i+T->length]=ret[i];
	}
	while(pos--)
	{
		ret++;
	}

	while(*T->ch!='\0')
	{
		*ret++=*T->ch++;
	}
}

void Replace(HString *T, HString *P, HString *V,int pos)//°´Î»ÖÃÌæ»»×Ö·û´®,ÓÃV×Ö·û´®È¥Ìæ»»
{
	int wei=Index(T,pos,P);
	if(wei==-1)
	{
		cout<<"Ã»ÓÐÕÒµ½ºÏÊÊµÄÌæ»»Î»ÖÃ"<<endl;
		return;
	}
	char *ret=T->ch;
	while(*V->ch!='\0')
	{
		*ret++=*V->ch++;
	}
}

int Index(HString *T, int pos, HString *P)//°´Î»ÖÃÆ¥Åä£¬PÊÇ×Ó´®TÊÇ¸¸´®
{
	if(pos+P->length>T->length)
		return -1;
	int count=pos;
	while(count--)
	{
		T->ch++;
	}
	char *ret=T->ch;
	char *p=P->ch;
	int t_size=pos;
	int length=T->length-P->length;
	while(*p!='\0' && length>=P->length)
	{
		if(*ret==*p)
		{
			ret++;
			p++;
		}
		else
		{
			p=P->ch;
			ret=++T->ch;
			t_size++;
			length--;
		}
	}
	if(length<P->length)
		return -1;
	else
		return t_size;
}

int SubString(HString *D,HString *S, int pos, int len)
{
	if(pos+len>S->length)
		return -1;
	int i=0;
	while(i++<pos)
	{
		S->ch++;
	}
	char *ret=S->ch;
	char *t=D->ch;
	while(len--)
	{
		*t++=*ret++;
	}
	*t='\0';
	return 1;
}
void StringConcat(HString *T, HString *s1,HString *s2)
{
	if(((s1->length)+(s2->length))>SIZE)
		return;
	char *ret=T->ch;
	while(*s1->ch!='\0')
	{
		*ret++=*s1->ch++;
	}
	while(*s2->ch!='\0')
	{
		*ret++=*s2->ch++;
	}
	*ret=*s2->ch;
}
void DestroyString(HString *S)
{
	free(S->ch);
	S->ch=NULL;
	S->length=0;
}
void ClearString(HString *S)
{
	*S->ch='\0';
	S->length=0;
}
int Length(HString *S)
{
	return S->length;
}
int StrCompare(HString *T, HString *S)
{
	while(*T->ch==*S->ch)
	{
		T->ch++;
		S->ch++;
	}
	if(*T->ch>*S->ch)
		return 1;
	else if(*T->ch<*S->ch)
		return -1;
	else
		return 0;
}

void StrCopy(HString *T, HString *S)
{
	if(STrFull(T))
	{
		cout<<"¿Õ¼äÒÑÂú"<<endl;
		return;
	}
	char *p=T->ch;
	while(*S->ch!='\0')
	{
		*p++=*S->ch++;
	}
	*p=*S->ch;
}

void InitHString(HString *T)
{
	T->ch=(char*)malloc(sizeof(char)*SIZE);
	if(T->ch==NULL)
	{
		cout<<"¿ª±ÙÄÚ´æÊ§°Ü"<<endl;
		return;
	}
	T->length=0;
}

bool StrEmpty(HString *S)
{
	return S->length==0;
}
bool STrFull(HString *S)
{
	return S->length>=SIZE;
}
void StrAssign(HString *T, char *str)
{
	if(STrFull(T))
	{
		cout<<"ÄÚ´æÒÑÂú"<<endl;
		return;
	}
	char *Str=T->ch;

	while(*str!='\0')
	{
		*Str++=*str++;
		T->length++;
	}
	*Str=*str;
}

void PrintString(HString *T)
{
	char *str=T->ch;
	while(*str!='\0')
	{
		cout<<*str;
		str++;
	}
	cout<<endl;
}