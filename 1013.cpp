#include<iostream>
#include<string.h>
using namespace std;

int N,M,K,i,j,k,cnt,city1,city2;
bool roads[1001][1001];
bool visited[1001];

void DFS(int occupied,int j){
	visited[j]=true;
	for(k=1;k<=N;k++){
		if(k!=occupied&&!visited[k]&&roads[j][k]){//���˰��췢�־�Ȼ��visited[k]д����visited[j]���ѹֽ����˵ݹ顣 
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
//�ж��ٸ���ͨ��ͼ������ʹ�ò��鼯��Ҳ���Բ鿴��main�е����˶��� ��dfs 
//�ع����²��鼯�����鼯ֻ�����������ã���parent��root�Ϳ����ˡ�
//��ͼ����Ĳ��鼯����main���DFS(occupied,j)�ĳ�DFS(occupied,j,j��)��
//Ȼ��DFS���visited[j]�ĳ�root[j],��ʱ��root����bool�ģ�����int��������¼��main���ĸ�j�����õ�����
/*
main(){
	DFS(occupied,j,j)
}
void DFS(int occupied,int j,int p){
	root[j]=p;
	for(k=1;k<=N;k++){
		if(k!=occupied&&!root[k]&&roads[j][k]){//root��ʼΪ0��root[i]=i;��ʾi��һ������ 
			DFS(occupied,k,p);
		}
	}
}
*/ 
