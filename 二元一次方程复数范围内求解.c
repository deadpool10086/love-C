#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a,b,c;
	double x1,x2,tmp,d;
	printf("please input a b c:");
	scanf("%f%f%f",&a,&b,&c);
	if(a==0&&b==0)
	 {printf("Not an equation\n");}
	else if(a==0)
	  {if(c==0)
	   printf("The solution of equation is x=0\n");
	   else
	   {x1=-c/b;
	   printf("The solution of equation is x=%.2lf\n",x1);
	   }
	  }
	else
	  {d=b*b-4*a*c;
	    if(d>=0)
	    {x1=(sqrt(d)-b)/(2*a);
	     x2=(-sqrt(d)-b)/(2*a);
		 printf("The solution of equation is x1=%.2lf x2=%.2lf\n",x1,x2);
		}
		else
		{x1=-b/(2*a);
	     x2=-b/(2*a);
	     tmp=sqrt(-d)/(2*a);
	     printf("The solution of equation is x1=%.2lf+%.2lfi x2=%.2lf-%.2lfi\n",x1,tmp,x2,tmp);
		}
	  }
	system("pause");  
	return 0;
}
