/**  ��������������  **/
//�����uva�ϵ�һ���⣬����д���Ǹ��ȽϷ����������һЩ�����˵ķ��� ...
/***
��������Ϊ������������һ�����ţ� '/'  or ''% ����������������ࣨ���г�����n���� 0<n<231��������
 ����Ϊ��
110 / 100
99 % 10
���Ϊ��
1
9
***/ 
//�������£�
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
    while(cin>>s>>c>>n)   //���뱻���� s������ c �� '/' or ''% �����Լ�����n
    {
        len=strlen(s);
        if(c=='%')
        {
            mod=0;
            for(i=0; i<len; i++)
            {
                mod=mod*10+s[i]-'0';          
                mod=mod%n;                      //���ó������ʣ���ʵ����ÿ�ζ���һ������n��һλ��mod��n��������
            }
            cout<<mod<<endl;
        }
        else
        {
            divis=flag=0;
            for(i=k=0; i<len; i++)              
            {
                divis=divis*10+s[i]-'0';
                if(divis>=n&&!flag)                //���ó������ʣ���divs���ڳ���nʱ����ʼ��������
                {
                    result[k++]=divis/n+'0';
                    divis=divis%n;                  //�������ʣ�����*10����һλ�����ֱ����µı�����
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
