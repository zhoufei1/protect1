#include "contact.h"

int main()
{
	char ch;
	scanf("%c\t",&ch);

	Pcon my_contact;

	my_contact.count=0;//先赋个初值
	my_contact.dhb =(peo*)malloc(1000*sizeof(peo));	

	int input = 1;
	while(input)
	{
		menu();
		printf("请选择>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			add_peo(&my_contact); 
			break;
		case 2:
			del_peo(&my_contact);
			break;
		case 3:
			search_peo(&my_contact);
			break;
		case 4:
			modify_peo(&my_contact);
			break;
		case 5:
			show_peo(&my_contact);
			break;
		case 6:
			clear_peo(&my_contact);
			break;
		}
	}
	return 0;
}
