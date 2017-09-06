#include <stdio.h>
#include <stdlib.h>
#define SUM 8
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct HuffNode huffnode;
struct HuffNode
{
	int height;
	huffnode *left,*right; 
};
huffnode *zhan[20];
int zhanding=0;
void track(huffnode *p,int len);

huffnode *creathufft(int *dp,int sum);
void bianli(huffnode *p);
int zongzhi(huffnode *p,int len);

int main(int argc, char *argv[]) {
	huffnode *root;
	int data[SUM]={12,32,35,4,78,12,24,8};
	root=creathufft(data,SUM);
	bianli(root);
	printf("%d",zongzhi(root,0));
	track(root,0);
	return 0;
}
huffnode *creathufft(int *dp,int sum)
{
	int i,j;
	int k1,k2;
	huffnode **b,*q;
	b=malloc(sum*sizeof(huffnode *));
	for(i=0;i<sum;i++)
	{
		b[i]=malloc(sizeof(huffnode));
		b[i]->height=dp[i];
		b[i]->left=b[i]->right=NULL;
	}
	for(i=1;i<sum;i++)
	{
		k1=-1,k2;
		for(j=0;i<sum;j++)
		{
			if(b[j]!=NULL&&k1==-1)
			{k1=j;continue;}
			else	if(b[j]!=NULL)
			{k2=j;break;}
		}
		for(j=k2;j<sum;j++)
		{
			if(b[j]!=NULL)
			{
				if(b[j]->height<b[k1]->height)
				{
					k2=k1;
					k1=j;
				}
				else if(b[j]->height<b[k2]->height)
				k2=j;
			}
		}
		q=malloc(sizeof(huffnode));
		q->height=b[k1]->height+b[k2]->height;
		q->left=b[k1];
		q->right=b[k2];
		b[k2]=NULL;
		b[k1]=q;
	}
	free(b);
	return q;
}
void bianli(huffnode *p)
{
	while(zhanding!=0||p!=NULL)
	{
		while(p!=NULL)
		{
			zhan[zhanding++]=p;
			p=p->left;
		}
		p=zhan[--zhanding];
		if(p->left==NULL&&p->right==NULL)
		printf("%d\t",p->height);
		p=p->right;
	}
}
int zongzhi(huffnode *p,int len)
{
	if(p->left==NULL&&p->right==NULL)
		return p->height*len;
	else
	return zongzhi(p->left,len+1)+zongzhi(p->right,len+1);
}
void track(huffnode *p,int len)
{
	int i;
	static int road[10];
	if(p==NULL)
	return;
		road[len]=0;
		track(p->left,len+1);
		road[len]=1;
		track(p->right,len+1);
	if(p->left==NULL&&p->right==NULL)
	{
		printf("\n");
		for(i=0;i<len;i++)
		printf("%d",road[i]);
		printf("\n");
	}
}
