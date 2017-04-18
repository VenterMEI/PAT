#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

struct s
{
	string name;
	int h;
	bool operator <(s s1)
	{
		if(h!=s1.h )
			return h>s1.h; 
		else
			return name<s1.name; 
	}
};
deque<s> list;
int i,j,n,m,k;
string row[10010];
//为什么最后一个测试点段错误没过，为什么呢？因为一开始row定义的是10000，最后一个测试点应该是只有一行，然后有10000个数据。没有row[0],但要有row[10000],然后段错误了。 
s t;

int main(void)
{
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>t.name>>t.h;
		list.push_back(t);  	
	}	
	sort(list.begin(),list.end()); 
	for(i=0;i<k;i++)
	{
//		m=(int)(n/k+0.5);
		m=n/k;//round down to the nearest integer是去尾，不是四舍五入。 
		if(i==0)
//			m=n-m*(k-1);
			m=n/k+n%k;
		int mid=(int)(m/2+1);
		int r=mid,l=mid;
		row[mid]=list[0].name;
		list.pop_front();
		for(j=1;j<m;j++)
		{
			if(j%2)
			{
				row[--l]=list[0].name;	
				list.pop_front();  
			}
			else
			{
				row[++r]=list[0].name;
				list.pop_front(); 		
			}	
		}
		for(j=l;j<r;j++)
			cout<<row[j]<<" ";
		cout<<row[j]<<endl;		
	}
	return 0;
} 
