#include "tongxunlu.h"

void menu()
{
	printf("************************\n");
	printf("*   1>add      2>del   *\n");
	printf("*   3>search   4>modify*\n");
	printf("*   5>show     6>clear *\n");
	printf("************************\n");
}

void Init(Pcon *my_contact)
{
	my_contact->count=0;//�ȸ�����ֵ
	my_contact->dhb = (peo*)malloc(1000*sizeof(peo));
}
void add_peo(Pcon *pcon)
{
			
		printf("���������֣�");
		pcon->dhb[pcon->count].name = (char *)malloc(10*sizeof(char));
		// scanf("%s ",pcon->dhb[pcon->count].name);  "%s "���治Ҫ���κοո��  ����һ��
		scanf("%s",pcon->dhb[pcon->count].name);
		
		//	pcon->dhb++;
		pcon->count++;
		printf("��ӳɹ�\n");//0x00562d90

}
void show_peo(Pcon *pcon)
{	
	int i=0;
	for(i=0;i<pcon->count;i++)
	{
		printf("%12s ",pcon->dhb[i].name);
	}
	printf("\n");
}
