#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int nums[10],i,n=10;
	void sort(int *p,int x);
	printf("please in put 10 numbers\n");
	for(i=0;i<n;i++)
	  scanf("%d",nums+i);
	sort (nums,n);
	for(i=0;i<n;i++)
	  printf("%d  ",nums[i]);
	return 0;
}
void sort(int *p,int x){
	int i,n,temp,m=3;
	for(i=0;i<m;i++){
		temp=p[9];
		for(n=x-2;n>=0;n--){
		p[n+1]=p[n];	
		}
	p[0]=temp;
	}
}
