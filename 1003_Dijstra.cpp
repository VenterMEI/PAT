/*
1003. Emergency (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/ 

//scattered  分散的
//题目要求的最大rescue team是指在所有最短路径中的rescue team最大。
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h> 

int main(void){
	int cityNum,roadNum,c1,c2;
	int i,j,k;
	scanf("%d%d%d%d",&cityNum,&roadNum,&c1,&c2);
	int road[cityNum][cityNum];
	int rescueTeam[cityNum];
	for (i=0;i<cityNum;i++){
		scanf("%d",&rescueTeam[i]);
	}
	for(i=0;i<cityNum;i++)
		for(j=0;j<cityNum;j++){
			if(i==j)
				road[i][j]=0;	
			else
				road[i][j]=INT_MAX;	
		}
	for(i=1;i<=roadNum;i++){
		scanf("%d%d",&j,&k);
		scanf("%d",&road[j][k]);
		road[k][j]=road[j][k];
	}
	
	int dist[cityNum],RTA[cityNum]={},pathCount[cityNum]={};
	bool visited[500]={};
	for(i=0;i<cityNum;i++){
		dist[i]=road[c1][i];
	}
	pathCount[c1]=1;
	RTA[c1]=rescueTeam[c1];
	for(i=0;i<cityNum;i++){
		int minDist=INT_MAX,minIndex;
		for(j=0;j<cityNum;j++){
			if(minDist>dist[j]&&!visited[j]){
				minDist=dist[j];
				minIndex=j;
			}
		}
		visited[minIndex]=true;
		for(j=0;j<cityNum;j++){
			if(!visited[j]){
				if(dist[j]>dist[minIndex]+road[minIndex][j]){
					dist[j]=dist[minIndex]+road[minIndex][j];
					RTA[j]=RTA[minIndex]+rescueTeam[j];
					pathCount[j]=pathCount[minIndex];
				}else if(dist[j]==dist[minIndex]+road[minIndex][j]){
					pathCount[j]+=pathCount[minIndex];
					if(RTA[j]<RTA[minIndex]+rescueTeam[j])
						RTA[j]=RTA[minIndex]+rescueTeam[j];
				}
			}
		}
		
	}
	printf("%d %d",pathCount[c2],RTA[c2]);

	return 0;
}

//定义数组可以通过int example[num]={};来完成默认初始化。
//但是在PAT里，这个num必须是常量。如果是变量，example作为可变数组不能通过这种方式初始化，而必须for循环遍历来初始化。 

