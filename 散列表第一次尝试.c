#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DATAMAX 100000
#define HASHMAX 200000
#define HASHKEY 108089
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct shuju Datanode;
typedef struct jiedian Node;
typedef  struct sanliebiao Hashtable;
struct shuju
{
	int num;
	char name[10];
	int data;
};

struct jiedian
{
	int info;
	struct shuju *data;
};

struct sanliebiao
{
	int maxnum;
	struct jiedian *table;
};

void initialize(int num,Hashtable *p);
void insert(Datanode *p,Hashtable *table);
int calchash(int data);
void find(int n,Hashtable *p);

int main(int argc, char *argv[]) {
	int i,sum;
	srand((unsigned)time(NULL));
	Datanode *data=NULL;
	data=(Datanode *)malloc(sizeof(Datanode)*DATAMAX);
	Hashtable *table;
	table=(Hashtable*)malloc(sizeof(Hashtable));
	for(i=0,sum=0;i<60000;i++)
	{
		data[sum++].num=rand()*10+rand()%10;
	}
	data[5432].num=5432;
	scanf("%s %d",data[5432].name,&data[5432].data);
	initialize(sum,table);
	for(i=0;i<sum;i++)
	insert(data+i,table);
	scanf("%d",&i);
	printf("%d %s %d\n",data[5432].num,data[5432].name,data[5432].num);
	find(i,table);
	return 0;
}
void initialize(int num,Hashtable *p)
{
	int i;
	if(num<1000)
	{
		printf("数据太少");
		exit(0);
	}
	p->maxnum=HASHMAX;
	p->table=(Node*)malloc(sizeof(Node)*p->maxnum);
	if(p->table==NULL)
	{
		printf("空间不足");
		exit(0);
	}
	for(i=0;i<p->maxnum;i++)
	{
		p->table[i].info=0;
	}
}
void insert(Datanode *p,Hashtable *table)
{
	int key,flag=1,i,keyc,di=1;
	key=calchash(p->num);
	keyc=key;
	while(table->table[key].info!=0)
	{
		key=keyc+flag*di*di;
		if(flag==1)
		{
			flag=-1;
		}
		else if(flag==-1)
		{
			di++;
			flag=1;
		}
		if(key>=HASHKEY)
		key-=HASHKEY;
		else if(key<0)
		key+=HASHKEY;
	}
	table->table[key].info=1;
	table->table[key].data=p;
}

int calchash(int data)
{
	int n;
	n=data%HASHKEY;
	return n;
}
void find(int n,Hashtable *p)
{
	int flag=1,key,keyc,di=1;
	key=calchash(n);
	keyc=key;
	while(p->table[key].info!=0&&n!=p->table[key].data->num)
	{
		key=keyc+flag*di*di;
		if(flag==1)
		{
			flag=-1;
		}
		else if(flag==-1)
		{
			di++;
			flag=1;
		}
		while(key<0||key>=HASHKEY)
		{
			if(key>=HASHKEY)
			key-=HASHKEY;
			else if(key<0)
			key+=HASHKEY;
		}
		
	}
	if(p->table[key].info==0)
	{
		printf("no\n");
		return;
	}
	printf("%s %d",p->table[key].data->name,p->table[key].data->data);
}
