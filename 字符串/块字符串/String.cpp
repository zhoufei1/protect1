#include"String.h"

void Show()
{
	cout<<"*********************************************"<<endl;
	cout<<"*[1]:  ³õÊ¼»¯×Ö·û´®        [2]:Á´½Ó×Ö·û´®   *"<<endl;
	cout<<"*[3]:  ±È½Ï×Ö·û´®          [4]:Çó×Ö·û´®³¤¶È *"<<endl;
	cout<<"*[5]:  ÏÔÊ¾×Ö·û´®          [6]:ÇåÀí×Ö·û´®   *"<<endl;
	cout<<"*[7]:  Æ¥Åä×Ö·û´®          [8]:Ìæ»»×Ö·û´®   *"<<endl;
	cout<<"*[9]:  ²åÈë×Ö·û´®          [10]:°´Î»É¾³ý    *"<<endl;
	cout<<"*[11]: ´Ý»Ù×Ö·û´®          [0]:½áÊø³ÌÐò     *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<"ÇëÑ¡Ôñ£º";
}

int Index(LString *T, int pos, LString *P)
{
	if(T->head==T->tail && P->head==P->tail && pos>=T->length)
		return -1;
	int i=0;
	int tep=pos;
	Chunk *t=T->head;
	Chunk *p=P->head;
	Chunk *temp=(Chunk*)malloc(sizeof(Chunk));
	if(tep>0)
	{
		while(--tep)
		{
			t=t->next;
		}
	}
	while(t!=T->tail)
	{
		temp=t;
		while(strcmp(t->ch,p->ch)==0 && p->next!=P->tail)
		{
			t=t->next;
			p=p->next;		
		}
		if(p->next==P->tail)
			break;
		t=temp->next;
		i++;
		p=P->head;
	}
	if(p->next==P->tail)
		return i+pos;
	else
		return -1;
}
void Replace(LString *T, LString *D,int pos)
{
	if(T->head==T->tail && D->head==D->tail && pos>=T->length)
		return;
	Chunk *p=T->head;
	if(pos>0)
	{
		while(--pos)
		{
			p=p->next;
		}
	}
	p->next=D->head;
	T->tail=D->tail;
}
void StrInsert(LString *D, int pos, LString *T)
{
	if(T->head==T->tail && D->head==D->tail && pos>=T->length)
		return;
	Chunk *p=D->head;
	while(--pos)
	{
		p=p->next;
	}
	Chunk *q=T->head;//ABCD EF->T->tail
	while(q->next!=T->tail)
	{
		q=q->next;
	}
	q->next=p->next;
	p->next=T->head;
	T->length+=D->length;
}
void StrDelete(LString *T, int pos)//°´Î»ÖÃÉ¾³ý
{
	if(pos>=T->length || T->head==T->tail)
		return;
	Chunk *p=T->head;
	while(--pos)
	{
		p=p->next;
	}
	if(p->next->next=T->tail)
	{
		T->tail=p->next;
		T->length--;
	}
	Chunk *q=p->next;
	p->next=q->next;
	p=q->next;
	T->length--;
}
int StrCompare(LString *T, LString *S)//±È½Ï×Ö·û´®´óÐ¡
{
	if(T->head==T->tail && S->head==S->tail)
		return 0;
	Chunk *pt=T->head;
	Chunk *ps=S->head;
	while(pt!=T->tail && ps!=S->tail)
	{
		if(strcmp(pt->ch,ps->ch)>0)
			return 1;
		if(strcmp(pt->ch,ps->ch)<0)
			return -1;
		pt=pt->next;
		ps=ps->next;
	}
	return 0;
}
void StringConcat(LString *T, LString *S)//°ÑSÁ´½Óµ½Tºó
{
	if(T->head==T->tail && S->head==S->tail)
		return;
	Chunk *p=T->head->next;
	while(p->next!=T->tail)
	{
		p=p->next;
	}
	p->next=S->head;
	p=S->head;
	S->tail=T->tail;
	T->length+=S->length;
}
void ClearString(LString *T)
{
	T->head=T->tail=NULL;
}
void DestroyString(LString *T)
{
	free(T->head);
	ClearString(T);
}
bool StrEmpty(LString *S)
{
	return S->length==0;
}
int GetLength(LString *T)
{
	return T->length-1;
}
void InitHString(LString *T)//³õÊ¼»¯
{
	T->head=(Chunk*)malloc(sizeof(Chunk));
	if(T->head==NULL)
	{
		cout<<"¿ª±Ù¿Õ¼äÊ§°Ü"<<endl;
		return;
	}
	T->tail=T->head;
	T->length=0;
}
void StrAssign(LString *T, char *str)//³õÊ¼»¯×Ö·û´®
{
	int t=0;
	Chunk *p=T->head;

	while((p->ch[t]=*str)!='\0')
	{
		t++;
		if(t==SIZE-1)
		{
			p->ch[t]='\0';	
			Chunk *s=(Chunk*)malloc(sizeof(Chunk)*SIZE);
			p->next=s;
			p=p->next;
			t=0;
		}
		T->length++;
		str++;
	}
	p->next=NULL;
	T->tail=p->next;
}


void PrintString(LString *T) //ÏÔÊ¾×Ö·û´®
{	
	if(T->head==T->tail)
	{
		cout<<"*****×Ö·û´®Îª¿Õ*****\n"<<endl;
		return;
	}
	Chunk *p=T->head;
	while(p!=T->tail)
	{
		printf("%s\n",p->ch);
		p=p->next;
	}
}