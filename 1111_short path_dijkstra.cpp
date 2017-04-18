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
1.总结一下dijlkstra和两次dfs的使用方法和原理
关于dijkstra算法：

使用方法：
先将起点的dis置零。然后循环，每次找到dis最小的点，如果没有就退出，如果有就标记访问过。然后，检查他的所有邻接点，有更小的dis就更新，并记录path。

原理：
oj上的题目往往是有不止一条最短路，他会让你输出其中cost啦，tine啦最小的一个，并且保证那一个是唯一的。
一开始接触觉得dijkstra没法胜任这个工作，想到的办法是用链表记录path（deque），遇到相同dis的也添加进去。最后这变成一个树形的path。
这样dfs一遍就能得到双最小。但是得到双最小的值已经不易，又如何记录那条最短的路径呢？所以想不通。
但反过来想，其实很简单。既然保证双最小唯一，那么最短路中短的含义已经不再是dis最小，而是dis最小的前提下cost，time最小。
那么，只要将compare的条件也从dis扩大到cost和time，那么就能直接得到最“短”路了。
本身dijkstra算法只能求出众多最短路的一条，但redim了compare条件之后，就是唯一输出了。
当然，也有可能双最小的也不唯一，这个是dijkstra所无法处理的，怎么办呢?给他扣几分喽。

关于twice dfs：

使用方法：
first dfs：先将起点的dfs置零，然后dfs（起点）。检查起点的所有邻接点，将满足更新条件的邻接点更新，并将更新的点也递归的调用dfs函数，直至没有内容更新。
second dfs：从终点开始遍历，遍历终点的所有邻接点，找到满足相等条件的邻接点。先对这个满足条件的点递归的调用dfs，再打印这个点。

原理：
first dfs更新所有点的信息，然后twice dfs求得路径。因为是从终点开始递归，所以先递归再打印可以得到正序。
写着写着我想到了打印多条最“短”路径的方法。
立一个flag int binary=-1判断是否分叉（对dijkstra来说是链式path>1，对twice dfs来说是可以找到两个满足条件的点），
分叉时将正在走的那个点的index赋给binary，记录这个岔路口。
再遇到岔路的岔路，再更新binary。然后输出一条最短路后，把岔路口的第一条岔路的dis设为int_max即可。知道binary==-1，break。
*/
