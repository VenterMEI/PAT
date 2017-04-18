#include<iostream>
#include<string>
using namespace std;

struct nodes
{	
	int dis;
	int cost;
};
nodes lists[510];
struct nodef
{
	int cost;
	int step;
};
nodef listf[510];
int n,m;
int edge[510][510],time_gjz[510][510],paths[510],pathf[510],cnts,cntf;
int i,j,v1,v2,f,e,t,index;
bool visits[510],visitf[510],is_same_gjz;
void findshort()
{
	int mindis=1<<30,mincost=1<<30,minstep=1<<30;
	for(f=0;f<n;f++)
	{
		if(!visits[f]&&mindis>lists[f].dis)
		{
			mindis=lists[f].dis;
			mincost=lists[f].cost;
			index=f;
		}
		else if(!visits[f] && mindis==lists[f].dis&&mincost>lists[f].cost)
		{
			index=f;
			mincost=lists[f].cost;
		}	
	}
}
void findfast()
{
	int mindis=1<<30,mincost=1<<30,minstep=1<<30;
	for(f=0;f<n;f++)
	{
		if(!visitf[f]&&mincost>listf[f].cost)
		{
			mincost=listf[f].cost;
			minstep=listf[f].step;
			index=f;
		}
		else if(!visitf[f]&&mincost==listf[f].cost&&minstep>listf[f].step)
		{
			index=f;
			minstep=listf[f].step;
		}	
	}
}


int main(void)
{
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>v1>>v2>>f;
		cin>>edge[v1][v2]>>time_gjz[v1][v2];
		if(!f)
		{
			edge[v2][v1]=edge[v1][v2];
			time_gjz[v2][v1]=time_gjz[v1][v2];
		}
	}
	cin>>v1>>v2;

	for(i=0;i<n;i++)
	{
		lists[i].cost=1<<30;
		lists[i].dis=1<<30;
	}
	lists[v1].dis=0;
	lists[v1].cost=0;
	while(true)
	{
		index=-1;
		findshort();
		visits[index]=true;
		if(index==-1)
			break;	
		for(i=0;i<n;i++)
			if(edge[index][i]!=0 && lists[index].dis+edge[index][i]<lists[i].dis)
			{
				lists[i].dis=lists[index].dis+edge[index][i];
				lists[i].cost=lists[index].cost+time_gjz[index][i]; 
			}
			else if(edge[index][i]!=0 && lists[index].dis+edge[index][i]==lists[i].dis && lists[index].cost+time_gjz[index][i]<lists[i].cost)
				lists[i].cost=lists[index].cost+time_gjz[index][i];
	}
	paths[0]=v2;
	for(i=0;i<n;)
	{
		for(j=0;j<n;j++)
		{
			if(edge[j][paths[i]] && lists[paths[i]].dis==lists[j].dis+edge[j][paths[i]]&&lists[paths[i]].cost==lists[j].cost+time_gjz[j][paths[i]])
				break;
		}
		paths[++i]=j;
		if(j==v1)
			break;
	}
	cnts=i;
	
	for(i=0;i<n;i++)
	{
		listf[i].cost=1<<30;
		listf[i].step=1<<30;
	}
	listf[v1].cost=0;
	listf[v1].step=1;
	while(true)
	{
		index=-1;
		findfast();
		visitf[index]=true;
		if(index==-1)
			break;	
		for(i=0;i<n;i++)
			if(edge[index][i]!=0 && listf[index].cost+time_gjz[index][i]<listf[i].cost)
			{
				listf[i].cost=listf[index].cost+time_gjz[index][i];
				listf[i].step=listf[index].step+1; 
			}
			else if(edge[index][i]!=0 && listf[index].cost+time_gjz[index][i]==listf[i].cost && listf[index].step+1<listf[i].step)
				listf[i].step=listf[index].step+1;
	}
	pathf[0]=v2;
	for(i=0;i<n;)
	{
		for(j=0;j<n;j++)
		{
			if(edge[j][pathf[i]] && listf[pathf[i]].cost==listf[j].cost+time_gjz[j][pathf[i]]&&listf[pathf[i]].step==listf[j].step+1)
			{
//				cout<<pathf[i]<<" "<<listf[paths[i]].step<<" "<<j<<" "<<listf[j].step<<endl;
				break;
			}
		}
		pathf[++i]=j;
		if(j==v1)
			break;
	}
	cntf=i;
	
	if(cntf==cnts)
	{
		for(i=0;i<=cnts;i++)
			if(paths[i]!=pathf[i])
				break;
		if(i==cnts+1)
			is_same_gjz=true;		
	}
//	for(i=0;i<n;i++)
//	{
//		cout<<i<<" "<<listf[i].cost<<" "<<listf[i].step<<endl; 
//	}
	if(is_same_gjz)
	{
		printf("Distance = %d; Time = %d: ",lists[v2].dis,lists[v2].cost);
		for(i=cntf;i>0;i--)
			cout<<pathf[i]<<" -> ";
		cout<<pathf[0]<<endl;	 
	}
	else
	{
		printf("Distance = %d: ",lists[v2].dis);
		for(i=cnts;i>0;i--)
		 	cout<<paths[i]<<" -> ";
		cout<<paths[0]<<endl;
		printf("Time = %d: ",listf[v2].cost);
		for(i=cntf;i>0;i--)
		 	cout<<pathf[i]<<" -> ";
		cout<<pathf[0]<<endl; 	
	}
	
	return 0;
}
/* 
1.�ܽ�һ��dijlkstra������dfs��ʹ�÷�����ԭ��
����dijkstra�㷨��

ʹ�÷�����
�Ƚ�����dis���㡣Ȼ��ѭ����ÿ���ҵ�dis��С�ĵ㣬���û�о��˳�������оͱ�Ƿ��ʹ���Ȼ�󣬼�����������ڽӵ㣬�и�С��dis�͸��£�����¼path��

ԭ��
oj�ϵ���Ŀ�������в�ֹһ�����·�����������������cost����tine����С��һ�������ұ�֤��һ����Ψһ�ġ�
һ��ʼ�Ӵ�����dijkstraû��ʤ������������뵽�İ취���������¼path��deque����������ͬdis��Ҳ��ӽ�ȥ���������һ�����ε�path��
����dfsһ����ܵõ�˫��С�����ǵõ�˫��С��ֵ�Ѿ����ף�����μ�¼������̵�·���أ������벻ͨ��
���������룬��ʵ�ܼ򵥡���Ȼ��֤˫��СΨһ����ô���·�ж̵ĺ����Ѿ�������dis��С������dis��С��ǰ����cost��time��С��
��ô��ֻҪ��compare������Ҳ��dis����cost��time����ô����ֱ�ӵõ���̡�·�ˡ�
����dijkstra�㷨ֻ������ڶ����·��һ������redim��compare����֮�󣬾���Ψһ����ˡ�
��Ȼ��Ҳ�п���˫��С��Ҳ��Ψһ�������dijkstra���޷�����ģ���ô����?�����ۼ���ඡ�

����twice dfs��

ʹ�÷�����
first dfs���Ƚ�����dfs���㣬Ȼ��dfs����㣩��������������ڽӵ㣬����������������ڽӵ���£��������µĵ�Ҳ�ݹ�ĵ���dfs������ֱ��û�����ݸ��¡�
second dfs�����յ㿪ʼ�����������յ�������ڽӵ㣬�ҵ���������������ڽӵ㡣�ȶ�������������ĵ�ݹ�ĵ���dfs���ٴ�ӡ����㡣

ԭ��
first dfs�������е����Ϣ��Ȼ��twice dfs���·������Ϊ�Ǵ��յ㿪ʼ�ݹ飬�����ȵݹ��ٴ�ӡ���Եõ�����
д��д�����뵽�˴�ӡ������̡�·���ķ�����
��һ��flag int binary=-1�ж��Ƿ�ֲ棨��dijkstra��˵����ʽpath>1����twice dfs��˵�ǿ����ҵ��������������ĵ㣩��
�ֲ�ʱ�������ߵ��Ǹ����index����binary����¼�����·�ڡ�
��������·�Ĳ�·���ٸ���binary��Ȼ�����һ�����·�󣬰Ѳ�·�ڵĵ�һ����·��dis��Ϊint_max���ɡ�֪��binary==-1��break��
*/
