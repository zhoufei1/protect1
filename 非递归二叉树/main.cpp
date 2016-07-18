#include"FBinTree.h"





void main()
{
	char *str="DBFEACG";//中序
	char *Rstr="DFEBGCA";//后序
	int length=strlen(str);
	BinTree<char> Tree;
	Tree.CreatBinTree_Post(str,Rstr,length);
	cout<<"\n前序：";
	Tree.PreOrder();
	cout<<"\n中序：";
	Tree.InOrder();
	cout<<"\n后序：";
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
	cout<<"\n前序：";
	Tree.PreOrder();
	cout<<"\n中序：";
	Tree.InOrder();
	cout<<"\n后序：";
	Tree.PostOrder();
	cout<<endl;
}*/