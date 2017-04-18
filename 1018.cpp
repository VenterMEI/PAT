#include<iostream>
#include<deque>
using namespace std;

int capacity,N,p,M;
int cur[501],edge[501][501];
int dist[501];
int i,j,k;
bool visit[501]={};
deque<int> path[501]; 
int minDist,minIndex;


int DFS(int s,int bike)
{
	if(s==0) 
	{
		printf("0:%d\n",bike);
		return bike;	
	}
	else 
	{	
		int minBike=1<<31-1,t;
		bike+=capacity/2-cur[s];
		while(path[s].size())
		{
			t=DFS(path[s][0],bike);
			if(minBike>t)
			{
				minBike=t;
			}
			path[s].pop_front(); 
		}
		printf("%d:%d\t",s,minBike);
		return minBike;
	}
}
 
int main(void){
	cin>>capacity>>N>>p>>M;
	for(i=1;i<=N;i++){
		cin>>cur[i];
	}
	for(i=0;i<=N;i++)
		for(j=0;j<=N;j++)
			edge[i][j]=1<<31-1;
	for(k=0;k<M;k++)
	{
		cin>>i>>j;
		cin>>edge[i][j];
		edge[j][i]=edge[i][j];
	}
	
	//init dist  
	for(i=1;i<=N;i++){
		dist[i]=edge[i][0];
	}
	dist[0]=0;
	
	while(1)
	{
		//find min dist	
		minDist=1<<31-1;
		for(i=1;i<=N;i++)
		{
			if(!visit[i]&&minDist>dist[i]){
				minDist=dist[i];
				minIndex=i;
			}			
		}
		if(minDist==1<<31-1) break;
		
		//update other dist
		visit[minIndex]=true;
		for(i=1;i<=N;i++)
		{
			if(dist[minIndex]+edge[i][minIndex]<dist[i])
			{
				dist[i]=dist[minIndex]+edge[i][minIndex];
				path[i].clear();
				path[i].push_back(minIndex); 
			}
			else if(dist[minIndex]+edge[i][minIndex]==dist[i])
			{
				path[i].push_back(minIndex); 
			}
		}
	}
	
	//还剩通过path找最优的路。
//	for(i=1,k=1;i<=N;i++)//用k算出最多可能有多少种possibleway。 
//	{
//		k*=path[i].size(); 
//	}
//	deque<int> possibleWay[k];
//	int cnt=0;//possibleway的数量 
	printf("%d",DFS(p,1<<30)-(1<<30)); 
	 
	return 0;
}

//dijkstra算法，用visited记录是否收入图中，而不改变dist的值。path用链表（deque）记录，遇到相同path就缀在链表尾。 

//做到1030，我试着来整理下这条的思路。
/*
首先，找dist最小的node，如果找不到，break，结束。
然后，更新最小的node的邻接点。如果邻接点更新后的dist比原来的小，那么更新dist，并重置path。如果相同，就加入path。
(实际上对求cost的题来说，这里直接判断相同dist谁的cost最小就可以取舍。但是这个bike问题，既可能车多出来，也可能少，只能先记录着)
然后，我们得到了所有的最短路，也就是deque数组path。我们dfs一遍这个path，就可以求出来答案。 
*/ 
