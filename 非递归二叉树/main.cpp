#include"FBinTree.h"





void main()
{
	char *str="DBFEACG";//����
	char *Rstr="DFEBGCA";//����
	int length=strlen(str);
	BinTree<char> Tree;
	Tree.CreatBinTree_Post(str,Rstr,length);
	cout<<"\nǰ��";
	Tree.PreOrder();
	cout<<"\n����";
	Tree.InOrder();
	cout<<"\n����";
	Tree.PostOrder();
	cout<<endl;
}
/*void main()
{
	char *str="ABDEFCG";
	char *Rstr="DBFEACG";
	int length=strlen(str);
	BinTree<char> Tree;
	Tree.CreatBinTree_Pre(str,Rstr,length);
	Tree.PreOrder();
	cout<<endl;
	Tree.InOrder();
	cout<<endl;
	Tree.PostOrder();
	cout<<endl;
}
/*void main()
{
	//char *str="ABDEFCG";
	//char *Rstr="DBFEACG";
	char *str="abdecfg";
	char *Rstr="dbeafcg";
	int length=strlen(str);
	BinTree<char> Tree;
	Tree.CreatBinTree_Pre(str,Rstr,length);
	Tree.PreOrder();
	cout<<endl;
	Tree.InOrder();
	cout<<endl;
	Tree.PostOrder();
	cout<<endl;
}
/*void main()
{
	//char *str="abde##f##kL##n##cxy##m##t##";
	char *str="abd##e##cf##g##";
	BinTree<char> Tree('#');
	Tree.CreateBinTree(str);
	cout<<"\nǰ��";
	Tree.PreOrder();
	cout<<"\n����";
	Tree.InOrder();
	cout<<"\n����";
	Tree.PostOrder();
	cout<<endl;
}*/