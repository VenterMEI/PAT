#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,i,j;
vector<int> l;
int sum;

int main()
{
	cin>>n;
	while(n--)
	{
		scanf("%d",&i);
		l.push_back(i);
	}
	sort(l.begin(),l.end());
	cout<<l.size()%2<<" ";
	i=0;
	j=l.size()-1;
	while(i<j)
		sum+=l[j--]-l[i++];
	if(j==i)
		sum+=l[i];
	cout<<sum<<endl;
	return 0;
}
