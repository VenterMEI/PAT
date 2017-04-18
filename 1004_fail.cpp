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
		if(maxLevel<node[fatherIndex].level+1&&node[fatherIndex].childNum!=0)//不能忘记前提是父亲节点有孩子，不然不符合+1的条件 
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
不确定个数的内容以int型输入。	
	int s;
	int cnt=0;
	while(scanf("%d",&s)!=EOF){
		printf("%d\n",cnt++);
	}
	
用一个scanf同时读两个数，这两个数不能在本行中就开始使用，因为在你敲回车之前，这两个数还没被scanf进来，怎么使用呢。
另外，scanf("%d",a);这里的双引号里尽量不要出现空格，就是连续的%d就可以了。否则你多打个空格，等输入的时候，必须也是数字+空格，尤其oj里会造成输入失败。	
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
