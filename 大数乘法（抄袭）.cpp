#include<stdio.h>  
#include<string.h>  
#define N 500  
int multy[1000];     //һǧλ���µĴ���  
void multiplyer(char *a,char *b)  
{  
    int i,j,num,tem,h;  
    char k;  
    memset(multy,0,sizeof(multy));  
    for(i=strlen(a)-1; i>=0; i--)  
        for(j=strlen(b)-1,tem=strlen(a)-1-i; j>=0; j--,tem++)  
        {  
            num=(a[i]-'0')*(b[j]-'0')+multy[tem];     // ת���������������  
            multy[tem]=num%10;                         // num%10�õ�����Ϊmuity��λ������  
            multy[tem+1]+=num/10;                     // num/10�õ�������ǰ��λ������  
        }  
    for(i=999; i>=0; i--)     //��multy����999λ��ʼ�������ҵ���һ����Ϊ0�����֣�����������˵õ������ĵ����Ϊ����  
        if(multy[i])  
            break;  
    if(i==-1)                 //ע�⣬�����������Ϊ0ʱ��i Ϊ-1�������������������� 0����˴˴������⴦��  
        i=0;  
    for(; i>=0; i--)  
        printf("%d",multy[i]);  
    puts("");  
}  
int main()  
{  
    char a[N+1],b[N+1];  
    while(scanf("%s%s",a,b)==2)      
        multiplyer(a,b);  
    return 0;  
}  
