#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Date
{
	int year,month,day;
}date;                     //�ṹ�彫���������̱�ʹ�ã� 
int main(int argc, char *argv[]) {
	int method1();
	int method2();
	srand((unsigned)time(NULL));           			//�����������ʵ�ִ����Ĳ������������� 
	clock_t star,stop;								//���ڼ�¼����ʱ�� 
	int i,days;
	double duration;
	star=clock();									//��ʱ��ʼ	
	for(i=0;i<100000000;i++)							//�÷���һ������Ԥ��10000�� 
	{
		date.year=rand()%3000+1;
		date.month=rand()&12+1;
		date.day=rand()%28+1;
		days=method1();								// ����date������Ϊȫ�ֱ������Բ�û��ʹ�ò��� 
	}
	stop=clock();									//��ʱ����		 
	duration=((double)(stop-star))/CLK_TCK;         //ת��Ϊ����Ϊ��λ 
	printf("%lf\n",duration);							//������	 
	star=clock();									//�������������ϲ���һ���Ȼ������ж���Ϊ�˼��������ѡ�����߷ֿ� 
	for(i=0;i<100000000;i++)
	{
		date.year=rand()%3000+1;
		date.month=rand()&12+1;
		date.day=rand()%28+1;
		days=method2();
	}
	stop=clock();
	duration=((double)(stop-star))/CLK_TCK;
	printf("%lf\n",duration);
	return 0;
}
int method1()
{
	int n;
	n=date.month;
	switch(n)
	{
		case 1:n=date.day;break;
		case 2:n=date.day+31;break;
		case 3:n=date.day+59;break;
		case 4:n=date.day+90;break;
		case 5:n=date.day+120;break;
		case 6:n=date.day+151;break;
		case 7:n=date.day+181;break;
		case 8:n=date.day+212;break;
		case 9:n=date.day+243;break;
		case 10:n=date.day+273;break;
		case 11:n=date.day+304;break;
		case 12:n=date.day+334;break;
	}
	if(date.month>2&&(date.year&4==0&&date.year%100!=0||date.year%400==0))
	n=n+1;
	return n;
}
int method2()
{
	int i,days;
	int month[11]={31,28,31,30,31,30,31,31,30,31,30};
	days=date.day;
	for(i=date.month;i>1;i--)
	days=days+month[i-2];
	if(date.month>2&&(date.year&4==0&&date.year%100!=0||date.year%400==0))
	days+=1;
	return days;
}
