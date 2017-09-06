#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	double a,b,c=0;
	char d;
	scanf("%lf%c%lf",&a,&d,&b);
	if(d=='+')
	{c=a+b;}
	else if(d=='-')
	{c=a-b;}
	else if(d=='*')
	{c=a*b;}
	else if(d=='/')
	  {if(a!=0)
	   {c=a/b;}
	   else
	   {printf("Sorry invalid format\n");}
	  }
	else if(d=='%')
	{if((int)a==a&&(int)b==b)
	  {c=(int)a%(int)b;}
	 else
	 {printf("Sorry invalid format\n");}
	} 
	printf("%lf\n",c);
	system("pause"); 
	return 0;
}
