#include<iostream>
using namespace std;

int n,i;
double t,sum;

int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{ 
		scanf("%lf",&t);
		sum+=t*i*(n-i+1);
		//һ��ʼ��i*(n-i+1)*t,Ȼ����Ե�2��3�����ˡ���Ϊint*int�Ľ�����ܳ���int�����̶����½���б䡣
		//����double*int�����һֱ��double����ͱ��������ִ��� 
	}
	printf("%.2lf",sum);
	return 0;
}


//��double�ȳ�double����֤���̲������⡣�ܶ�ʱ��Ī������Ĵ�����һ�����ǳ������̡� 
//�¸������㷨�� ʮ��*ʮ��=���ڣ���Ȼo(n^2)�ĸ��Ӷ�Ҳ���ܲ��ˡ� 

/* 
#include<iostream>
using namespace std;

int n,i,j;
double t[100010],sum,seq;
int main(void)
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&t[i]);
	}
	for(i=0;i<n;i++)
	{
		seq=0;
		for(j=i;j<n;j++)
		{
			seq+=t[j];
			sum+=seq;
		}
	}
	printf("%.2lf",sum);
	
	return 0;
}
*/
