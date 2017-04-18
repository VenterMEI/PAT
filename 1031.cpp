#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

char str[100];
deque<char> s;
int n1,n2,len,i,j,maxk;

int main(void)
{
	cin>>str;
	len=strlen(str);
	for(i=3;i<=len;i++)
	{
		n1=(len-i+2)/2;
		if(maxk<n1&&i>=n1)
		{
			maxk=n1;
		}
	}
	n1=maxk;
	n2=len+2-2*n1;
	for(i=0;i<len;i++)
		s.push_back(str[i]);
	for(i=0;i<n1-1;i++)
	{
		cout<<s[0];
		for(j=0;j<n2-2;j++)
			cout<<" ";
		cout<<s[s.size()-1]<<endl;
		s.pop_back();
		s.pop_front(); 		
	}
	for(deque<char>::iterator it=s.begin();it!=s.end();it++)
		cout<<*it;
			 
	return 0;	
} 

//ÇáËÉ 
