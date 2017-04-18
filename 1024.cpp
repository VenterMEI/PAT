#include<iostream>
using namespace std;

long long n1,n2,n;
int i=0,step;

bool is_p()
{	
	n2=0;
	n=n1;
	while(n)
	{
		n2=n2*10.0+n%10;
		n/=10;		
	}
	if(n1==n2)
		return 1;
	else
	{
		n1+=n2;
		i++;
		return 0;
	}
}
int main(void)
{
	cin>>n1>>step;
	while(i<step)
	{
		if(is_p())
			break; 
	}
	printf("%d\n%d",n1,i);
	return 0;	
} 

//将n1,n2的long long改为int，oj上正确率没有变动。以后尽量不要用long long，还是用string和int数组吧。 
//输出long long类型数据，%I64d ，注意I是大写的i，不是l或1.或者用cout也行。 long long unsigned则为%I64u 
