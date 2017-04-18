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
	}//����д�� bool operator<(nod s)   return level<s.level;
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
//level=0ȫ�����˵���Ȼ���level=1��ʼ��ÿ�������޺��ӽ��ģ���cnt++��level��󣬾ʹ�ӡcnt����ײ���Ǹ�cnt��Ϊ���������������level��û�л���cout�������ֶ�cout��
//redim ������������Ų���ʡ�ԡ� 
