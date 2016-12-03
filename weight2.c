#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float r1,r2,p,w,v;
	r1=8.9/100,r2=5.1/100,p=11340;
	v=3.14159267*(r1*r1-r2*r2);
	w=v*p;
	printf("weight is %f\n",w);
	system("pause");
	return 0;
}
