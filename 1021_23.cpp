#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct node
{
	int index;
	int level;
};
int N; 
//int parent[10001]={};
//int edge[10001][10001]={}; 
int cnt=0,deepest=0,height[10001]={};
int i,j,k;
bool flag =false;
deque<node> root[10001];
deque<int> queue,edge[10001];
int main(void)
{
/*
	//union and find . 
	//it can judge the size of forest , but can't judge cycle;
	//if you want to judge cycle, considering that each node have only one parent in the tree,the node whose parent is't 0 but changes its parent is not a tree;  	

	以上方法的一个问题是如果一个结点分别指向两个根，你知道它不是一个树，但你不能把它所指的两个树合并成一个树。这导致forest的size变大。	
*/
	cin>>N;
	for(k=1;k<N;k++)
	{
		cin>>i>>j;
		edge[i].push_back(j) ;
		edge[j].push_back(i) ; 
//		if(i>j)
//			swap(i,j);	
//		if(parent[j]!=0)
//			flag=true;
//		parent[j]=i;	//这里判断环，其实也不一定是环。就是说一个树，它的root只能有一个。但加了这个判断，就有两个测试点不能通过 
	}
	bool visited[10001]={};
	for(i=1;i<=N;i++) 
	{
		if(!visited[i])
		{
			cnt++;
			queue.push_back(i);
			visited[i]=true;
			while(queue.size()) 
			{
				j=queue[0];
				for(k=0;k<edge[j].size();k++)
					if(!visited[edge[j][k]])
					{
						queue.push_back(edge[j][k]);
						visited[edge[j][k]]=true;
					}
				queue.pop_front(); 	
			}
		}
	}
	if(cnt!=1||flag)//cnt judge forest;flag judge forest;
	{
		printf("Error: %d components",cnt);
		return 0;	
	}
	
	//deepest root
	for(i=1;i<=N;i++)
	{
		node nf,nc;
		int p=0;//queue without pop;
		bool visited[10001]={};
		nf.index=i;
		nf.level=1;
		root[i].push_back(nf);
		visited[i]=true;
		while(p<root[i].size())
		{
			for(j=0;j<edge[root[i][p].index].size();j++)
			{
				if(!visited[edge[root[i][p].index][j]])
				{
					nc.index=edge[root[i][p].index][j];
					nc.level=root[i][p].level+1;
					root[i].push_back(nc); 
					visited[edge[root[i][p].index][j]]=true; 		
				}		
			}
			p++;   
		}
		for(j=0;j<root[i].size();j++)
		{
			if(height[i]<root[i][j].level)
				height[i]=root[i][j].level;	
		} 
		if(deepest<height[i])
			deepest=height[i]; 
		root[i].clear();//及时释放，不然内存超限。 
	}


	for(i=1;i<=N;i++)
	{
		if(deepest==height[i])
			printf("%d\n",i);
	} 
	
	return 0;
} 

//题目有问题，树里有环的不能称为树。我一开始想法是一对邻接的结点，让下标小的当根，下标大的parent置为小的下标。
//当某个下标的parent既不是默认值（表明还没变过），但又再次改变了,就说明他有两个root，亦即不是树。
//但这种想法是错误的。因为，比如输入 3\n 1 3\n 2 3\n.其实，不是node 3 有两个root，而是3是root，1 2是叶子。 
//学习：对于这种edge[10001][10001]这种最大存储量有一亿，可以用容器模拟邻接链表的方式的储存。 ---------------->>用容器来当链表，而不是邻接矩阵。
//对于内存超限，要及时释放。对于运行超时，要降低算法复杂度。扣的2分时因为复杂度较高，运行超时。 
//学习：并查集，树的直径。
 

/*
树的直径：从任一点u出发，搜到的最远点肯定是树的直径（树上的最长路）的两个端点之一。再从该端点出发，就可以搜到另一个最远点。 
树的直径的证明：
设树最短路径的最长路两个端点，p1和p3。最长路路径上一点为p2，最长路路径外一点为p0。则有两种情况：
1.u在最长路的路径上：假设搜到最远点不是p1和p3，而是t。则dis(u,t)>dis(u,p1)且dis(u,t)>dis(u,p3)。
即dis(u,t)+dis(u,p3)>dis(u,p1)+dis(u,p3)。则dis(t,p3)>最长路dis(p1,p3),矛盾。 
2.u在最长路的路径外：两种情况，一种是u会走到最长路路径上某点p2.则从p2出发，最远点必是p1或p3，情况1已证明。
一种是u到最远点t的路径与最长路路径不相交。则dis(u,t)>dis(u,p2)+dis(p2,p1)。则dis(u,t)+dis(p3,p2)>dis(u,p2)+dis(p1,p2)+dis(p2,p3)。 
则dis(t,u)+dis(u,p2)+dis(p2,p3)>2*dis(u,p2)+dis(p1,p2)+dis(p2,p3)>dis(p1,p2)+dis(p2,p3)=dis(p1,p2)，即dis(t,u)+dis(u,p2)+dis(p2,p3)。 
*/ 
