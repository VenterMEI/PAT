#include<iostream>
#include<string.h>
using namespace std;

int N,M,K,i,j,k,cnt,city1,city2;
bool roads[1001][1001];
bool visited[1001];

void DFS(int occupied,int j){
	visited[j]=true;
	for(k=1;k<=N;k++){
		if(k!=occupied&&!visited[k]&&roads[j][k]){//找了半天发现竟然把visited[k]写成了visited[j]，难怪进不了递归。 
			DFS(occupied,k);
		}
	}
}

int main(void){
	scanf("%d%d%d",&N,&M,&K);
	for(i=1;i<=N;i++){
		for(j=1;j<=N;j++){
			roads[i][j]=false;
		}
	}
	for(i=0;i<M;i++){
		scanf("%d%d",&city1,&city2);
		roads[city1][city2]=true;
		roads[city2][city1]=true;
	}
	for(i=0;i<K;i++){
		int occupied;
		cnt=-1;
		scanf("%d",&occupied);
		for(j=1;j<=N;j++){
			visited[j]=false;
		}
		for(j=1;j<=N;j++){
			if(j!=occupied&&visited[j]==0){
				cnt++;
				DFS(occupied,j);
			}
		}
		if(N==1){
			printf("0\n");
		}else{
			printf("%d\n",cnt);
		}	
	}
	return 0;
} 
//有多少个联通子图，可以使用并查集，也可以查看在main中调用了多少 此dfs 
//回顾了下并查集，并查集只能在树里面用，用parent查root就可以了。
//而图里面的并查集，将main里的DFS(occupied,j)改成DFS(occupied,j,j’)，
//然后DFS里的visited[j]改成root[j],这时候root不是bool的，而是int，用来记录是main里哪个j’调用的他。
/*
main(){
	DFS(occupied,j,j)
}
void DFS(int occupied,int j,int p){
	root[j]=p;
	for(k=1;k<=N;k++){
		if(k!=occupied&&!root[k]&&roads[j][k]){//root初始为0。root[i]=i;表示i是一个根。 
			DFS(occupied,k,p);
		}
	}
}
*/ 
