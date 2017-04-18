#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<long long> l;
long long tmp;
int n1,n2,mid,i;

int main(void)
{
	cin>>n1;
	for(i=0;i<n1;i++)
	{
		scanf("%lld",&tmp);
		l.push_back(tmp); 
	}
	cin>>n2; 
	for(i=0;i<n2;i++)
	{
		scanf("%lld",&tmp);
		l.push_back(tmp); 
	}
	sort(l.begin(),l.end());
	mid=(n1+n2-1)/2;
	cout<<l[mid];
	return 0;
}
