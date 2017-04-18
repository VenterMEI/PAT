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
		cin>>x>>f>>m>>k;//���ֻ��ำֵ�ģ����ñ���ȥ��¼�����õ�ʱ�򷽱㡣ȫ����l[x]��f/m/c��ʾ���ر�����
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

//���ü�������
//1.�����ϵ����Ҫȷ�е�֪��������ĸ�ĸ������Ů��ֻ��Ҫ֪��������ѪԵ��ϵ���ɡ�
//2.��Ȼ������С��id������塣��Ҳ����ÿ����һ���˶�ȥ��������֮��ع�ϵ��id��Сֵ����ô������������Ϊ�������������ˣ������Ĺ�����Ȼ�޷�չ����
//������ֻ�ܱ�֤���������һ���ã������������û�еõ�����ġ�����Ҫ���ǰ�δ֪������ת��Ϊ��֪�����⡣
//����ʵ����һ��dfs�����⡣����С��id��ʼ���������������õ��Ķ���һ��family��
//���ⷸ�ô���Ҳ���ջ񡣵�һ��Ͳ�˵�ˣ���Ҫ�ѱߵĹ�ϵ����̫������Щ��Ϣ�Ƕ���ģ����ü�¼��ô��ȷ��
//��Σ�input��input������������ߴ���һ���԰�����������꣬�Ͳ�Ҫ��һ�롣
//��Ϊ����������һ�룬����calculate��������������ô�࣬��û�н��ܡ����˷�ʱ���ô��롣