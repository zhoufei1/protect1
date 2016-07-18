#include "tongxunlu.h"

int main()
{
	Pcon my_contact;
	Init(&my_contact);

	int input = 1;
	while(input)
	{
		menu();
		printf("ÇëÑ¡Ôñ>");
		scanf("%d",&input);
		switch(input)
		{
		case 1:
			add_peo(&my_contact); //0x00332d88  0x00622d90
			break;
		case 2:
		//	del_peo(&my_contact);
			break;
		case 3:
		//	search_peo(&my_contact);
			break;
		case 4:
		//	modify_peo(&my_contact);
			break;
		case 5:
			show_peo(&my_contact);
			break;
		case 6:
		//	clear_peo(&my_contact);
			break;
		}
	}
	return 0;
}
