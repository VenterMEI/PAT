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
	
	//��ʣͨ��path�����ŵ�·��
//	for(i=1,k=1;i<=N;i++)//��k����������ж�����possibleway�� 
//	{
//		k*=path[i].size(); 
//	}
//	deque<int> possibleWay[k];
//	int cnt=0;//possibleway������ 
	printf("%d",DFS(p,1<<30)-(1<<30)); 
	 
	return 0;
}

//dijkstra�㷨����visited��¼�Ƿ�����ͼ�У������ı�dist��ֵ��path������deque����¼��������ͬpath��׺������β�� 

//����1030����������������������˼·��
/*
���ȣ���dist��С��node������Ҳ�����break��������
Ȼ�󣬸�����С��node���ڽӵ㡣����ڽӵ���º��dist��ԭ����С����ô����dist��������path�������ͬ���ͼ���path��
(ʵ���϶���cost������˵������ֱ���ж���ͬdist˭��cost��С�Ϳ���ȡ�ᡣ�������bike���⣬�ȿ��ܳ��������Ҳ�����٣�ֻ���ȼ�¼��)
Ȼ�����ǵõ������е����·��Ҳ����deque����path������dfsһ�����path���Ϳ���������𰸡� 
*/ 
