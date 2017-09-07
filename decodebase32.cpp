#include <iostream>

using std::cout;
using std::endl;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int change(char *en,char *de);

int main(int argc, char** argv) {
	int i;
	char data[]={"GUYDIMZVGQ2DMN3CGRQTONJXGM3TINLGG42DGMZXGM3TINLGGY4DGNBXGYZTGNLGGY3DGNBWMU3WI==="};
	char encode[8];
	char decode[6];
	decode[5]=0;
	for(int j=0;data[j]!=0;j+=8)
	{
		for(i=0;i<8;i++)
		{
			if(data[j+i]>64)
			encode[i]=data[j+i]-65;
			else if(data[j+i]<57)
			encode[i]=data[j+i]-48+24;
			else
			encode[i]=0;
		}
		change(encode,decode);
		cout << decode;
	}
	return 0;
}
int change(char *en,char *de)
{
	de[0]=en[0]<<3;
	de[0]=de[0]|en[1]>>2;
	de[1]=en[1]<<6;
	de[1]=de[1]|en[2]<<1;
	de[1]=de[1]|en[3]>>4;
	de[2]=en[3]<<4;
	de[2]=de[2]|en[4]>>1;
	de[3]=en[4]<<7;
	de[3]=de[3]|en[5]<<2;
	de[3]=de[3]|en[6]>>3;
	de[4]=en[6]<<5;
	de[4]=de[4]|en[7];
}
