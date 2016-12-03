#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Student
	{int numbers;
	char names[10];
	char sex;
	int score;
	} ;
int main(int argc, char *argv[]) {
	int i;
	struct Student student[10];
	void sort (struct Student *p,int n);
    for(i=0;i<10;i++)
	{printf("Please input the %d student informantion according to numbers names sex score\n",i+1);
	scanf("%d %s %c %d",&student[i].numbers,student[i].names,&student[i].sex,&student[i].score);
	}
	sort (student,i);
	for(i=0;i<10;i++){
		printf("%d  %s  %c  %d\n",student[i].numbers,student[i].names,student[i].sex,student[i].score);
	}
	return 0;
}
void sort (struct Student *p,int n)
{int i,m,k;
 struct Student temp;
 for(i=0;i<n-1;i++){
	 for(k=i,m=i+1;m<n;m++)
		 if((p+k)->numbers>(p+m)->numbers) k=m;
	 temp=*(p+i),*(p+i)=*(p+k),*(p+k)=temp;
     }
}
