#include<stdio.h>
#include<string.h>

typedef struct {
	int childNum;
	int child[100];
	int level;
}Node;

int main(void){
	int nodeNum,nonLeafNum,i,j;
	int fatherIndex,maxLevel=1;
	scanf("%d%d",&nodeNum,&nonLeafNum);//2 1
	Node node[nodeNum+1];
	for(i=1;i<=nodeNum;i++){
		node[i].childNum=0;
		node[i].level=0; 
	}
	node[1].level=1;
	for(i=1;i<=nonLeafNum;i++){
		scanf("%d",&fatherIndex);//01 
		scanf("%d",&node[fatherIndex].childNum);//1
		for(j=1;j<=node[fatherIndex].childNum;j++){
			scanf("%d",&node[fatherIndex].child[j]);//02
			node[node[fatherIndex].child[j]].level=node[fatherIndex].level+1; 
		}
		if(maxLevel<node[fatherIndex].level+1&&node[fatherIndex].childNum!=0)//��������ǰ���Ǹ��׽ڵ��к��ӣ���Ȼ������+1������ 
			maxLevel=node[fatherIndex].level+1;
	}
	int level[maxLevel+1];
	for(i=1;i<=maxLevel;i++){
		level[i]=0;
	}
	for(i=1;i<=nodeNum;i++){
		if(node[i].childNum==0){
			level[node[i].level]++;		
		}
	}
	for(i=1;i<=maxLevel;i++){
		if(i!=maxLevel){
			printf("%d ",level[i]);
		}else{
			printf("%d",level[i]);
		}
	}	
	
	return 0;
} 

/*
��ȷ��������������int�����롣	
	int s;
	int cnt=0;
	while(scanf("%d",&s)!=EOF){
		printf("%d\n",cnt++);
	}
	
��һ��scanfͬʱ�����������������������ڱ����оͿ�ʼʹ�ã���Ϊ�����ûس�֮ǰ������������û��scanf��������ôʹ���ء�
���⣬scanf("%d",a);�����˫�����ﾡ����Ҫ���ֿո񣬾���������%d�Ϳ����ˡ�����������ո񣬵������ʱ�򣬱���Ҳ������+�ո�����oj����������ʧ�ܡ�	
int main(void){
	int a,b[10]={};
	scanf("%d %d",&a,&b[a]);
	printf("%d",b[a])2; 
	return 0;
} 

int main(void){
	int a,b[10]={};
	scanf("%d",&a);
	scanf("%d",&b[a]);
	printf("%d",b[a]); 
	return 0;
} 
*/
