#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct nod
{
	deque<int> child;
	int level;
	bool operator<(nod s)
	{
		return level<s.level;
	}//不能写成 bool operator<(nod s)   return level<s.level;
};
nod tree[110];
int n,m,i,j,k,cnt;
int visit[110];
bool appear[110];
deque<int> qu;

int main(void)
{
	cin>>n>>m;
	while(m--)
	{
		cin>>i>>k;
		appear[i]=true;
		while(k--)
		{
			cin>>j;
			appear[j]=true;
			visit[j]=true;
			tree[i].child.push_back(j);
		}
	}
	for(i=0;i<100;i++)
		if(appear[i]&&!visit[i])
			break;
	tree[i].level=1;
	qu.push_back(i);
	while(qu.size())
	{
		i=qu[0];
		qu.pop_front();
		for(j=0;j<tree[i].child.size();j++)
		{
			qu.push_back(tree[i].child[j]);
			tree[tree[i].child[j]].level=tree[i].level+1;
		}
	}
	
	sort(tree,tree+110);
	k=1;
	for(i=0;i<110;i++)
	{	
		if(tree[i].level>k)
		{
			cout<<cnt<<" ",k++,cnt=0;
		}
		if(tree[i].level==k&&tree[i].child.size()==0)
			cnt++;
	}
	cout<<cnt; 
	return 0;
}
//level=0全都过滤掉，然后从level=1开始，每次遇到无孩子结点的，就cnt++；level变大，就打印cnt。最底层的那个cnt因为遇不到比他更大的level，没有机会cout，所以手动cout。
//redim 运算符，大括号不能省略。 
