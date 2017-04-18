#include<iostream>
#include<string>
#include<deque>
using namespace std;

bool not_r[1000];
int main(void)
{
	int k,i,j,p;
	string s;
	char t;
	char d[1000];
	int cnt=0;
	deque<char> c;
	cin>>k>>s;

	for(i=0;i<s.length();i++)
	{
		for(j=1;j<k&&j+i<s.length();j++)
			if(s[i]!=s[i+j])
				break;
		if(j!=k)
		{
			not_r[s[i]]=true;
			
		}
		else
			i+=k-1;
	}
	for(i=0;i<s.length();i++)
	{
		if(!not_r[s[i]])
		{
			for(j=0;j<c.size();j++)
				if(s[i]==c[j])
					break;
			if(j==c.size())
			{
				c.push_back(s[i]);
			}		
			for(j=1;j<k;j++)
				s[i+j]='%';
			i+=k-1;
		}	
	}
	
	for(i=0;i<c.size();i++)
	{
		cout<<c[i];
	}
	cout<<endl;
	for(i=0;i<s.length();i++)
		if(s[i]!='%')
			cout<<s[i];
	cout<<endl;
	return 0;
}