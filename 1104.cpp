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
		//一开始是i*(n-i+1)*t,然后测试点2和3过不了。因为int*int的结果可能超出int的量程而导致结果有变。
		//先让double*int，结果一直以double来存就避免了这种错误。 
	}
	printf("%.2lf",sum);
	return 0;
}


//有double先乘double，保证量程不出问题。很多时候莫名其妙的错误。有一个就是超出量程。 
//下附暴力算法。 十万*十万=百亿，虽然o(n^2)的复杂度也接受不了。 

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
