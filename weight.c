#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float R,V,P,W,L;
	printf("Please input R L P\n");
	scanf("%f%f%f",&R,&L,&P);
	V=3.1415926*R*R*L;
	W=P*V;
	printf("Weight is %f\n",W);
	system("pause");
	return 0;
}
