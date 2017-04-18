#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;

int s[100010];
int mx[100010];
int mn[100010];
int n,i,j;
deque<int> ss;

int main(void)
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		mx[i+1]=mx[i]>s[i]?mx[i]:s[i];
		mn[i]=1<<30;
	}
	for(i=n;i>0;i--)
	{
		mn[i-1]=mn[i]<s[i]?mn[i]:s[i];
	}
	for(i=1;i<=n;i++)
	{
		if(s[i]>mx[i]&&s[i]<mn[i])
		{
			ss.push_back(s[i]);
		}
	}
	cout<<ss.size()<<endl;
	for(i=0;i<ss.size();i++)
	{	
		if(i==0)
			cout<<ss[i];
		else
			cout<<" "<<ss[i];
	}
	cout<<endl;
	return 0;
}

//即时size为0，也要输出第二行。所以最后一行打个endl还是有必要的。