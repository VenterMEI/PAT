#include<iostream>
using namespace std;

int c[3];
int i=0,ten,one;
char str[3][3]; 
int main(void)
{
	cin>>c[0]>>c[1]>>c[2];
	cout<<"#";
	while(i<3)
	{
		ten=c[i]/13;
		one=c[i]%13;
//		printf("c[i]=%d,ten=%d one=%d\n",c[i],ten,one);
		if(ten>9)
			str[i][0]=ten-10+'A';
		else 
			str[i][0]=ten+'0';
		if(one>9)
			str[i][1]=one-10+'A';
		else 
			str[i][1]=one+'0';
		cout<<str[i++];			
	}
	return 0;	
} 
