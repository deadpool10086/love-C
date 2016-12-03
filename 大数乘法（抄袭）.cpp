#include<stdio.h>  
#include<string.h>  
#define N 500  
int multy[1000];     //一千位以下的大数  
void multiplyer(char *a,char *b)  
{  
    int i,j,num,tem,h;  
    char k;  
    memset(multy,0,sizeof(multy));  
    for(i=strlen(a)-1; i>=0; i--)  
        for(j=strlen(b)-1,tem=strlen(a)-1-i; j>=0; j--,tem++)  
        {  
            num=(a[i]-'0')*(b[j]-'0')+multy[tem];     // 转化成两个数字相乘  
            multy[tem]=num%10;                         // num%10得到的数为muity本位的数字  
            multy[tem+1]+=num/10;                     // num/10得到的是向前进位的数字  
        }  
    for(i=999; i>=0; i--)     //从multy数组999位开始遍历，找到第一个不为0的数字，即：两数相乘得到的数的的最高为数字  
        if(multy[i])  
            break;  
    if(i==-1)                 //注意，当输入的数字为0时，i 为-1，但数字与零相乘需输出 0，因此此处需特殊处理  
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
