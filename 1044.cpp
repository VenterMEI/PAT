#include<iostream>
#include<deque>
using namespace std;

int n,p,t;
int s,ms=1<<30,st=1,v[100010];
int i,j,k;
bool is_found;
deque<int> st1,ed1;
int main(void)
{
	cin>>n>>p;
	for(i=1;i<=n;i++)
	{
		cin>>v[i];
		s+=v[i];
		if(s==p){
			cout<<st<<"-"<<i<<endl;is_found=true;}
		while(s>=p)
		{
			if(s<ms&&!is_found)
			{
				st1.clear();
				ed1.clear();
				ms=s;
			}
			if(s==ms&&!is_found)
			{
				st1.push_back(st);
				ed1.push_back(i);
			}
			s-=v[st];
			st++;		
			if(s==p)
			{	cout<<st<<"-"<<i<<endl;is_found=true;}
		}
	}
	if(!is_found)
		for(i=0;i<st1.size();i++)
			cout<<st1[i]<<"-"<<ed1[i]<<endl;
	return 0;
}
//还有一个测试点运行超时，这里其实不用在线处理。记录起点到每个点的总sum，两点间的sum即为两点sum之差。 
/*
#include<cstdio>      
#include<cstring>      
#include<cmath>      
#include<algorithm>      
#include<queue>      
using namespace std;  
typedef long long ll;  
const int maxn = 1e5 + 5;  
int n, m, a[maxn], sum[maxn], ans;  
  
int main()  
{  
    scanf("%d%d", &n, &m);  
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];  
    ans = sum[n];  
    for (int i = 1, j = 1; i <= n; i++)  
    {  
        while (sum[j] - sum[i - 1] < m&&j <= n) j++;  
        if (sum[j] - sum[i - 1] >= m) ans = min(sum[j] - sum[i - 1], ans);  
    }  
    for (int i = 1, j = 1; i <= n; i++)  
    {  
        while (sum[j] - sum[i - 1] < ans&&j <= n) j++;  
        if (sum[j] - sum[i - 1] == ans) printf("%d-%d\n", i, j);  
    }  
    return 0;  
} 
*/