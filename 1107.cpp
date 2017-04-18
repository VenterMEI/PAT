#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;

int hob[1010];
int n;
deque<int> p[1010];
int i,j,k,t,pt;

int find(int i)
{
	if(hob[i]>0)
	{
		i=hob[i];
		i=find(i);
	}
	return i;
}
void un(int i,int j)
{
	i=find(i);
	j=find(j);
	if(hob[j]<0)
		hob[i]+=hob[j];
	if(i!=j)
		hob[j]=i;
}

int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		scanf("%d:",&j);
		for(k=0;k<j;k++)
		{
			cin>>t;
			if(k!=0)
			{
				un(t,pt);
			}
			pt=t;
			if(k==j-1)
			{
				pt=find(t);
				hob[pt]--;
			}			
		}
	}
	sort(hob,hob+1010);
	for(i=0,j=0;i<n;j++,i++)
	{
		if(hob[i]>=0)
			break;
	}	
	cout<<j<<endl;
	for(i=0;i<j;i++)
	{
		if(i!=0)
			cout<<" ";
		cout<<-hob[i];
	}
	cout<<endl;

}