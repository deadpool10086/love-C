#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	srand((unsigned)time(NULL));
	int w,s=30,c,h;
	do 
	  {printf("Please decide who first Computer(1) Player(2):");
	   scanf("%d",&w);
	  }
	while(w!=1&&w!=2);
	while(1)
	{if(w==1)
	  {if(s%3==0)
	    c=rand()%2+1;
	   else
	    c=s%3;
	   s-=c; 
	   printf("Computer take %d root.\nMatch with %d remaining root\n",c,s);
	   if(s==0)
	     {printf("Computer win \n");
	      break;}
	   do
	    {printf("Your turn:");
		 scanf("%d",&h);}
	   while(h!=1&&h!=2||h>s);
	   s-=h;
	   printf("Match with %d remaining root\n",s);
	   if(s==0)
	     {printf("Player win \n");
	      break;}
	  } 
	 else
	  {do
	    {printf("Your turn:");
		 scanf("%d",&h);}
	   while(h!=1&&h!=2||h>s);
	   s-=h;
	   printf("Match with %d remaining root\n",s);
	   if(s==0)
	     {printf("Player win \n");
	      break;}
	   if(s%3==0)
	    c=rand()%2+1;
	   else
	    c=s%3;
	   s-=h; 
	   printf("Computer take %d root.\nMatch with %d remaining root\n",c,s);
	   if(s==0)
	     {printf("Computer win \n");
	      break;}
	  }   
	}
	system("pause");
	return 0;
}
