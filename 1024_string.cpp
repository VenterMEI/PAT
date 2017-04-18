#include<iostream>
#include<string>
using namespace std;

string num1,num2,tmp;
int step,i=0,j,k; 
int main(void)
{
	cin>>num1>>step;
	while(i<step)
	{
		num2.assign(num1.rbegin(),num1.rend());
		if(num1==num2) break;
		i++;
		tmp=num1; 
//		num1.clear();
		k=0;
		for(j=0;j<num2.size();j++)
		{
			int x=tmp[j]-'0';
			int y=num2[j]-'0';//实际上这两处j应该从后往前加的，但因为是逆序，所以可以偷个懒。
//			num1+=(char)((x+y+k)%10+'0');
			num1[j]=(char)((x+y+k)%10+'0');
			k=(x+y+k)/10; 
		}
		if(k)
			num1+=(char)(k+'0');			
		tmp.assign(num1.rbegin(),num1.rend());
		num1=tmp;
	}
	
	cout<<num1<<endl<<i;
	return 0;
}

//借此题学习一下string库的操作。 
//为什么之前的不行num1[j]的不行
//答：如果要使用num1[j]，必须在num1[j]已存在的情况下才可以，不能clear()再num1[j]=。对于尚未开辟的位置，需要通过+=字符/字符串来添加。 
//关于进位，可以采取逆序加，再逆序的方式，这样可以省去对超出数组头的排查。 
