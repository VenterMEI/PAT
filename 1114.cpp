#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

struct p
{
	deque<int>  r;
	double s;
	double a;
};
p l[10010];
struct fam
{
	int id;
	int cnt;
	double s;
	double a;
	bool operator <(fam h)
	{	
		if(h.a!=a)
			return a>h.a;
		else
			return id<h.id;
	}
};
fam family[10010];
int n,ct;
int i,j,p;
int x,f,m,k,c;
bool visit[10010];

void dfs(int z)
{	
	visit[z]=false;
	family[ct].cnt++;
	family[ct].s+=l[z].s;
	family[ct].a+=l[z].a;
	for(int y=0;y<l[z].r.size();y++)
	{
		if(visit[l[z].r[y]])
			dfs(l[z].r[y]);
	}
}

int main()
{
	cin>>n;
	while(n--)
	{
		cin>>x>>f>>m>>k;//这种互相赋值的，多用变量去记录，调用的时候方便。全都用l[x]的f/m/c表示，特别繁琐。
		visit[x]=true;
		if(f!=-1)
			l[x].r.push_back(f),l[f].r.push_back(x),visit[f]=true;
		if(m!=-1)
			l[x].r.push_back(m),l[m].r.push_back(x),visit[m]=true;
		while(k--)
		{	
			cin>>c;
			visit[c]=true;
			l[x].r.push_back(c),l[c].r.push_back(x);
		}
		cin>>l[x].s>>l[x].a;
	}

	ct=0;
	for(i=0;i<10010;i++)
	{	
		if(visit[i])
		{	
			dfs(i);
			family[ct].id=i;
			family[ct].s/=family[ct].cnt;
			family[ct].a/=family[ct].cnt;
			ct++;
		}
	}
	cout<<ct<<endl;
	sort(family,family+ct);
	for(i=0;i<ct;i++)
		printf("%04d %d %.3lf %.3lf\n",family[i].id,family[i].cnt,family[i].s,family[i].a);
	return 0;
};

//犯得几个错误：
//1.家族关系不需要确切的知道他是你的父母还是子女，只需要知道你们有血缘关系即可。
//2.虽然是用最小的id代表家族。但也不用每输入一个人都去更新找与之相关关系的id最小值。这么做不合适是因为，即便这样做了，后续的工作依然无法展开。
//这样做只能保证这次输入有一点用，但问题基本是没有得到解决的。最重要的是把未知的问题转化为已知的问题。
//这其实就是一个dfs的问题。从最小的id开始遍历，所有它碰得到的都是一个family。
//这题犯得错误也是收获。第一点就不说了，不要把边的关系看的太死，有些信息是多余的，不用记录那么精确。
//其次，input就input，如果不能在线处理，一次性把这个工作做完，就不要做一半。
//因为就算你做了一半，到了calculate，工作量还是那么多，并没有介绍。还浪费时间敲代码。