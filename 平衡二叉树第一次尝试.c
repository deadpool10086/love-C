#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct Shu
{
	int num;
	struct Shu*left;
	struct Shu*right;
}shu;

shu *insert(shu*root;int n);
void build(shu *p,int n);

int main(int argc, char *argv[]) {
	srond((unsigned)time(NULL));
	int n=rand();
	shu *root=NULL;
	build(root,n);
	for(int i=0;i<32;i++)
	{
		n=rand();
		root=insert(root,n);
	}
	return 0;
}
shu *insert(shu*p;int n)
{
	while(1)
	{
		if(n<p->num)
		{push(p);p=p->left;}
		else if(>p->num)
		{push(p);p=p->right;}
		if(p==NULL)
		{build(pop(-1),n);break}
	}
	p=pop(-2);
	if(hight(p->left)-hight(p->right)==2)
	{
		if(hight(p->left->left)-hight(p->left->right)==2)
		leftleftspin(p);
		else if(hight(p->left->rignt)-hight(p->left->left)==2)
		leftrightspin(p);
	}
	else if(hight(p->right)-hight(p->left)==2)
	{
		if(hight(p->rightp->right)-hight(p->right->left)==2)
		rightrightspin(p);
		else if(hight(p->right->left)-hight(p-right->right)==2)
		rightleftspin(p);
	}
}
void build(shu *p,int n)
