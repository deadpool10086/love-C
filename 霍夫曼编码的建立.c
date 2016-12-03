#include "huffstruct.h"
struct Huff*huff;
void build(void)
{
	int i;
	huff->n=SUM-1;
	huff->sum=999999999;
	for(i=0;i<SUM;i++)
	{
		huff[i+1].n=i;
		huff[i+1].sum=0;
	}
}
void statistical(unsigned short n)
{
	int s=0,e=SUM-1,i;
	i=(s+e)/2;
	while(1)
	{
		if(n==i)
		{
			huff[i+1].sum++;
			break;
		}
		else if(n>i)
		{s=i+1;}
		else
		{e=i-1;} 
		i=(s+e)/2;
	}
}
void PercDown( struct Huff *p,int i )
{
    int Parent, Child;
    struct Huff x;
    x = p[i]; 
    for( Parent=i; Parent*2<=SUM; Parent=Child ) {
        Child = Parent * 2;
        if( (Child!=SUM) && (p[Child].sum<p[Child+1].sum) )
            Child++;  
        if( x.sum >= huff[Child].sum ) break; 
        else  
            huff[Parent] = huff[Child];
    }
	huff[Parent] = x;
}
 
void BuildHeap(struct Huff *p)
{
   int i;
    for( i =SUM/2; i>0; i-- )
        PercDown(p,i);
}
