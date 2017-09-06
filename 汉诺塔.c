#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void move(char A,char B)
 {printf("%c->%c\n",A,B);
 }
 void hanoi(int n,char A,char B,char C)
 {if(n==1) {move(A,C);}
  else
 {hanoi(n-1,A,C,B);
  move(A,C);
  hanoi(n-1,B,A,C);}
 }
int main(int argc, char *argv[]) {
	int n;
	scanf("%d",&n);
	hanoi(n,'A','B','C');
	return 0;
}


