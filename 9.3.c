#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Student
{
	int num;
	char name[20];
	int score[3];
};
int main(int argc, char *argv[]) {
	void print(struct Student *student);
	int i;
	struct Student student[5];
	printf("please in put the studen's data:bum name score\n");
	for(i=0;i<5;i++)
	scanf("%d %s %d %d %d",&student[i].num,student[i].name,student[i].score+0,student[i].score+1,student[i].score+2);
	print(student);
	return 0;
}
void print(struct Student *student)
{
	int i;
	for(i=0;i<5;i++)
	printf("%d %s %d %d %d\n",student[i].num,student[i].name,student[i].score[0],student[i].score[1],student[i].score[2]);
}
