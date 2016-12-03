#include <stdio.h>

int main()
{
	char a[1000]="010101010101010101010101010101011001010101010101010110100110010101010101011010101010011010010110101010100110011001100110011001100110100101010101";
	unsigned char d=0,s=0;
	int count = 0;
	int i,j;
//	scanf("%s",a);
	for (i=0; a[i]!='\0'; i+=2)
	{
		if(a[i]=='1')
		 	d = (d << 1)|0; 
		if (a[i]=='0')
	    	d = (d << 1)|1;
		count ++;
		if (count == 8)
		{
			for (j=0; j<8; j++)
			{
				s = s << 1;
				s = s | (d & 1);
				d = d >> 1;
			}
			printf("%X",s);
			d=0;
			count =0;
			
		}
	}
	printf("%X",d);
	return 0;
}
