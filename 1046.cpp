#include<iostream>
#include<algorithm>
using namespace std;

int l,n,m,dis[100010];
int x,y;
int i,j;

int main(void)
{
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>j;
		dis[i+1]=j+dis[i];
		l+=j;
	}
	cin>>j;
	l+=j;
	cin>>m;
	while(m--)
	{
		cin>>x>>y;
		if(y<x)
			swap(x,y);
		j=dis[y]-dis[x];
		cout<<min(j,l-j)<<endl;		
	}
}

//十万规模的数据经不起两次遍历。 
