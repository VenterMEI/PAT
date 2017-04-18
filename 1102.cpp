#include<iostream>
#include<deque>
using namespace std;

int n,k,root;
int i,j;
int s[15][2];
deque<int> qu;
char t[3];
bool visit[20];
 
void inorder(int x)
{
	if(s[x][0]!=-1)
	{
		inorder(s[x][0]);
	}	
	qu.push_back(x);
	if(s[x][1]!=-1)
	{		
		inorder(s[x][1]);
	}
}
int main(void)
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		for(j=1;j>=0;j--)
		{
			cin>>t;
			if(t[0]!='-')
			{	
				sscanf(t,"%d",&s[i][j]);
				visit[s[i][j]]=true;
			}
			else
				s[i][j]=-1;
		}
	}
	for(i=0;i<n;i++)
		if(!visit[i])
			root=i;
	qu.push_back(root);
	while(qu.size())
	{
		i=qu.front();
		qu.pop_front();
		if(i!=root)
			cout<<" ";
		cout<<i;
		if(s[i][0]!=-1)
			qu.push_back(s[i][0]);
		if(s[i][1]!=-1)
			qu.push_back(s[i][1]);
	}
	cout<<endl;
	inorder(root);
	for(i=0;i<n;i++)
	{
		if(i!=0)
			cout<<" ";
		cout<<qu[i];
	}
	cout<<endl;
	return 0;
}