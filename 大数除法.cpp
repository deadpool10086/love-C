/**  大数除法与求余  **/
//这个是uva上的一个题，本身写的那个比较繁琐，借鉴了一些其他人的方法 ...
/***
这个题大意为输入两个数和一个符号（ '/'  or ''% ），求除法或是求余（其中除数是n满足 0<n<231），例：
 输入为：
110 / 100
99 % 10
输出为：
1
9
***/ 
//代码如下：
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1000],result[1000];
int main()
{
    long long mod,divis;
    int  n,i,k,flag,len;
    char c;
    while(cin>>s>>c>>n)   //输入被除数 s，符号 c （ '/' or ''% ），以及除数n
    {
        len=strlen(s);
        if(c=='%')
        {
            mod=0;
            for(i=0; i<len; i++)
            {
                mod=mod*10+s[i]-'0';          
                mod=mod%n;                      //利用除法性质，其实质是每次都是一个最多比n多一位的mod对n进行求余
            }
            cout<<mod<<endl;
        }
        else
        {
            divis=flag=0;
            for(i=k=0; i<len; i++)              
            {
                divis=divis*10+s[i]-'0';
                if(divis>=n&&!flag)                //利用除法性质，当divs大于除数n时，开始进行整除
                {
                    result[k++]=divis/n+'0';
                    divis=divis%n;                  //除法性质，余数*10加下一位的数字便是新的被除数
                    flag=1;
                }
                else if(flag)
                {
                    result[k++]=divis/n+'0';
                    divis=divis%n;
                }
            }
            if(!k) result[k++]='0';
            result[k]='\0';
            cout<<result<<endl;
        }
    }
    return 0;
}
