#include<iostream>
using namespace std;

long long a[1000000],b[1000000],now;
int n1,n2,i,mid,pa=0,pb=0;

int main(void)
{
	cin>>n1;
	for(i=0;i<n1;i++)
		scanf("%lld",&a[i]);
	cin>>n2;
	for(i=0;i<n2;i++)
		scanf("%lld",&b[i]);
	mid=(n1+n2+1)/2;
	i=0;
	while(i++!=mid)
	{
		if(pa!=n1&&pb!=n2)
			if(a[pa]>b[pb])
			{
				now=b[pb];
				pb++;	
			}
			else
			{	
				now=a[pa];
				pa++; 
			}
		else if(pa!=n1)
			now=a[pa++];
		else
			now=b[pb++];		 
//		if(pa!=n1&&(pb==n2||a[pa]<b[pb]))
//			now=a[pa++];
//		else
//			now=b[pb++];	
	}	
	cout<<now;
	return 0;
} 

//long long ÒªÓÃ%lldÀ´¶Á¡£   
