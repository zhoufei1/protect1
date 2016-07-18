#include"String.h"

void Show()
{
	cout<<"*********************************************"<<endl;
	cout<<"*[1]:  ��ʼ���ַ���        [2]:�����ַ���   *"<<endl;
	cout<<"*[3]:  �Ƚ��ַ���          [4]:���ַ������� *"<<endl;
	cout<<"*[5]:  ��ʾ�ַ���          [6]:�����ַ���   *"<<endl;
	cout<<"*[7]:  ƥ���ַ���          [8]:�滻�ַ���   *"<<endl;
	cout<<"*[9]:  �����ַ���          [10]:��λɾ��    *"<<endl;
	cout<<"*[11]: �ݻ��ַ���          [0]:��������     *"<<endl;
	cout<<"*********************************************"<<endl;
	cout<<"��ѡ��";
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
void StrDelete(LString *T, int pos)//��λ��ɾ��
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
int StrCompare(LString *T, LString *S)//�Ƚ��ַ�����С
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
void StringConcat(LString *T, LString *S)//��S���ӵ�T��
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
void InitHString(LString *T)//��ʼ��
{
	T->head=(Chunk*)malloc(sizeof(Chunk));
	if(T->head==NULL)
	{
		cout<<"���ٿռ�ʧ��"<<endl;
		return;
	}
	T->tail=T->head;
	T->length=0;
}
void StrAssign(LString *T, char *str)//��ʼ���ַ���
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


void PrintString(LString *T) //��ʾ�ַ���
{	
	if(T->head==T->tail)
	{
		cout<<"*****�ַ���Ϊ��*****\n"<<endl;
		return;
	}
	Chunk *p=T->head;
	while(p!=T->tail)
	{
		printf("%s\n",p->ch);
		p=p->next;
	}
}