#include<iostream>
#include<deque>
using namespace std;

int n,m,s,d;
int i,j;
int map[510][510],cost[510][510],dis[510],pay[510];//这里dis是到终点的距离，而非到起点的距离 

void rdfs(int x)
{
	if(x==s)
		return;
	for(int k=0;k<n;k++)
	{
		if(map[x][k])
		{
									
			if(dis[k]>dis[x]+map[k][x])
			{
				dis[k]=dis[x]+map[k][x];
				pay[k]=pay[x]+cost[k][x];
				rdfs(k);
			}
			else if(dis[k]==dis[x]+map[k][x]&&pay[k]>pay[x]+cost[x][k])
			{	
				pay[k]=pay[x]+cost[k][x];
				rdfs(k);//如果写出rdfs[k]就会warnning，你把函数指针当数组用了。warning就算了，更关键的是进不了递归函数了。
				   		//[Warning] pointer to a function used in arithmetic [-Wpointer-arith]
			}
		} 
	}
}

void dfs(int x)//从起点开始打印 
{
	if(x==s)
		cout<<s<<" ";
	for(int k=0;k<n;k++)
	{
		if(map[x][k]&&dis[x]==map[x][k]+dis[k]&&pay[x]==pay[k]+cost[x][k])
		//map[x][k]不能少，因为默认的map和cost都是0.例如自身，x==k的话，条件也成立，但显然是不应该进入循环的。 
		{
			cout<<k<<" ";
			if(k!=d)
				dfs(k);	
		}	
	}
}

//void dfs(int x)//从终点开始打印 
//{
//	for(int k=0;k<n;k++)
//	{
//		if(map[x][k]&&dis[x]==map[x][k]+dis[k]&&pay[x]==pay[k]+cost[x][k])
//		{
//			
//			dfs(k);	
//			cout<<k<<" ";
//			if(x==s)
//				cout<<s<<" ";	
//		}	
//	}
//
//}
 
int main(void)
{
	cin>>n>>m>>s>>d;
	while(m--)
	{
		cin>>i>>j;
		cin>>map[i][j];
		map[j][i]=map[i][j];
		cin>>cost[i][j];
		cost[j][i]=cost[i][j]; 
	}
	for(i=0;i<n;i++)
	{
		dis[i]=1<<31-1;
		pay[i]=1<<31-1;	
	}	
	dis[d]=0;
	pay[d]=0;
	rdfs(d);
//	cout<<"dis: "<<dis[0]<<" "<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<endl;
//	cout<<"pay: "<<pay[0]<<" "<<pay[1]<<" "<<pay[2]<<" "<<pay[3]<<endl;
	dfs(s);
	cout<<dis[s]<<" "<<pay[s];
	return 0;
}

//定义在main外的变量会自动初始化。
 
//如果求一条最短路，无疑用Dijkstra。但是对于求多条最短路中的cost最小路，正反两次dfs即可。
//第一遍反着来，以终点为起点，把各个node到终点的最小distance和cost都标记出来。
//第二遍再正着来，如果x的邻接点中满足dis和pay的加和，那么说明这个邻接点就在最短最省路中。
//其实也可以第一遍正着来，第二遍反则来，这样比较符合逻辑。
//但需要修改下第二次dfs。就是说，像中序或后序递归遍历，先访问的后printf。就是说把递归放在printf之前。
//参考注释的从终点开始打印，如果第一遍是正着来的话，反的反过来打印就是正着的顺序了。 

//但是它和Dijkstra相比，有两个问题，一个是它的时间复杂度（和空间复杂度）比Dijkstra大太多了。二是，如果有两条相同cost和dis的路径，它仍无法判别。
//虽然用Dijkstra，我目前还没想到怎么处理打印的问题。
//做到这条，我试着来整理下第1018条的思路。
/*
首先，找dist最小的node，如果找不到，break，结束。
然后，更新最小的node的邻接点。如果邻接点更新后的dist比原来的小，那么更新dist，并重置path。如果相同，就加入path。
(实际上对求cost的题来说，这里直接判断相同dist谁的cost最小就可以取舍。但是这个bike问题，既可能车多出来，也可能少，只能先记录着)
然后，我们得到了所有的最短路，也就是deque数组path。我们dfs一遍这个path，就可以求出来答案。 
*/ 
