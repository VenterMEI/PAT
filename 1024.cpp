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

//��n1,n2��long long��Ϊint��oj����ȷ��û�б䶯���Ժ�����Ҫ��long long��������string��int����ɡ� 
//���long long�������ݣ�%I64d ��ע��I�Ǵ�д��i������l��1.������coutҲ�С� long long unsigned��Ϊ%I64u 
