#include<iostream>
#include<string>
using namespace std;

struct nod
{
	int left;
	int right;	
};
int n,i,j;
string l,r;
bool visit[30];
nod node[30];
int tree[30];

int getvalue(string s)
{
	int v=0;
	for(int k=0;k<s.length();k++)
	{
		v=v*10+s[k]-'0';	
	}
	return v;	
} 

int main(void)
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>l>>r;
		if(l!="-")
		{
			node[i].left=getvalue(l);
			visit[node[i].left]=true;
		}
		else
			node[i].left=-1;
		if(r!="-")
		{
			node[i].right=getvalue(r);
			visit[node[i].right]=true;
		}
		else
			node[i].right=-1;	
	}
	for(i=2;i<=n;i++)
	{
		tree[i]=-1;
	}
	for(i=0;i<n;i++)
		if(!visit[i])
			break;
	tree[1]=i;
	for(i=1;i<=n;i++)
	{
		if(node[tree[i]].left!=-1)
			tree[i*2]=node[tree[i]].left; 		
		if(node[tree[i]].right!=-1)
			tree[i*2+1]=node[tree[i]].right; 		
	}
	for(i=1;i<=n;i++)
	{
		if(tree[i]==-1)
			break;		
	}
	if(i==n+1)
		cout<<"YES"<<" "<<tree[n];
	else
		cout<<"NO"<<" "<<tree[1];		
	return 0; 
} 
//string有没有getvalue的函数。 
