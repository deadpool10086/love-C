#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int s=30,y,n;
	printf("Match with %d remaining root\n",s);
	biaoshiz: printf("Please decide who first,computer 1,human 2\n" );
	scanf("%d",&y);
	switch(y)
	{case 1:
	  {do
	    {printf("Computer turn:\n");
		 if(s%3==0)
	     s=s-1;
	     else
	     s=s-s%3;
	     printf("Match with %d remaining root\n",s);
	     if(s==0)
	     {printf("Computer win \n");
	      break;
		 }
		 biaoshi: printf("your turn:");
	     scanf("%d",&n);
	     if(n==1||n==2)
	      {s=s-n;
	      printf("Match with %d remaining root\n",s);
		  }
		 else
		  {printf("The operating error\n");
		   goto biaoshi;
		  }
		 if(s<=0)
	     {printf("Human win \n");
	      break;
		 } 
	   	}        
		while(1);
	  }
	  break;
	case 2:
	  {while(1)
	    {biaoshi1: printf("your turn:");
	     scanf("%d",&n); 
	     if(n==1||n==2)
	      {s=s-n;
	      printf("Match with %d remaining root\n",s);
		  }
		 else
		  {printf("The operating error\n");
		   goto biaoshi1;
		  }
		  if(s<=0)
	     {printf("Human win \n");
	      break;}
	     printf("Computer turn:\n");
		 if(s%3==0)
	     s=s-1;
	     else
	     s=s-s%3;
	     printf("Match with %d remaining root\n",s);
	     if(s==0)
	     {printf("Computer win \n");
	      break;} 
		}
      }
	  break;
	default: 
	 {printf("The operating error\n");
	  goto biaoshiz;
	 } 
    }
	system("pause");  
	return 0;
}
