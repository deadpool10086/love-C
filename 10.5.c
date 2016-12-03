#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int per[100],i,m,n,*p;
	printf("Please input how many people\n");
	do{scanf("%d",&n);
	}
	while(n<1||n>100);
	for(i=1,p=per;i<=n;i++){
		for(m=1;m<=3;p++){
			if(p==per+n)  p=per;
			if(*p!=3) *p=m++;
			
		}
	}

	printf("The luck guy is the number:%d",p-per);
	return 0;
}
