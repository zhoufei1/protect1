#ifndef __CONTACT_H__
#define __CONTACT_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct peole
{
	char *name;
}peo;
typedef struct Contact
{
	peo *dhb;
	int count;
}Pcon;

void menu();
void Init(Pcon *my_contact);
void add_peo(Pcon *pcon);
void del_peo(Pcon *pcon);
void search_peo(Pcon *pcon);
void modify_peo(Pcon *pcon);
void show_peo(Pcon *pcon);
void clear_peo(Pcon *pcon);
int find(char *p, Pcon *pcon);

#endif  
