#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int k,y;
	char c,m;
	do 
	 {printf("Do you want to Encode(1) or Decode(0):");
	 scanf("%d",&y);}
	while(y<0||y>1);
    do
     {printf("Please input the key:");
      scanf("%d",&k);}
    while(k<=0||k>=26);
    fflush(stdin);
    printf("please input your data:");
	if(!y)
	 k=-k;
	  while((c=getchar())!='\n')
	   {
	    if(c>='a'&&c<='z')
	     c='a'+(c-'a'+k)%26;
	    else if(c>='A'&&c<='Z')
		 c='A'+(c-'A'+k)%26;
	    putchar(c);
	   }
	 
    printf("\n");  
    system("pause");  
	return 0;
}
