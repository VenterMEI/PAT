#include<iostream>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

int N,parent[10001]={},cnt;
int i,j,k;
bool visited[10001]={},flag;
deque<int>	edge[10001],queue,depth;
set<int> all; 
int last,tail,p;

//find 
int findSet(int x)
{
	while(parent[x]!=0)//parent[x]==0说明x是一个根。 
		x=parent[x];
	return x;	
}
//union 
void unionSet(int x,int y)
{
	x=findSet(x);
	y=findSet(y);
	if(x!=y)
	{
		parent[x]=y;
		cnt--;//每次有效合并就cnt--。因为cnt=N，只有N-1次输入每次恰将两个非联通的分量联通，cnt进行N-1次--，才能使cnt=1.
		//故无需考虑有环的情况，因为有一个环就浪费一个cnt--。那么cnt必不能为1，也即不能成树。	
	}
		
}

void DFS(int index,int level){
	visited[index]=true;
	if(k<level)
	{
		k=level;
		depth.clear();
		depth.push_back(index); 
	}
	else if(k==level)
	{
		depth.push_back(index); 
	} 
	for(int i=0;i<edge[index].size();i++)//递归一定要注意，这里是int i，不然i是static，这个递归里的i另一个递归可以改变他的值。 
	{	
		if(!visited[edge[index][i]])
		{
			DFS(edge[index][i],level+1);
		}
	}
}

int main(void)
{
	//input
	cin>>N;
	cnt=N;
	for(i=1;i<N;i++)
	{
		cin>>j>>k;
		edge[j].push_back(k);
		edge[k].push_back(j);
		unionSet(j,k);
	}
	if(cnt>1)
	{ 
		printf("Error: %d components",cnt);
		return 0; 
	} 
	//deepest root
	//first dfs 
	k=0;
	DFS(1,1);
	for(i=0;i<depth.size();i++)
	{
		all.insert(depth[i]);
	}
//	queue.push_back(1);
//	visited[1]=true;
//	while(queue.size())
//	{
//		p=queue[0];//queue里最后一个弹出的一定是depth最大的之一。这样就确定了最长路的一个端点。 
//		for(i=0;i<edge[queue[0]].size();i++)
//		{
//			if(!visited[edge[queue[0]][i]])
//			{
//				queue.push_back(edge[queue[0]][i]);
//				visited[edge[queue[0]][i]]=true; 		
//			}
//		}
//		queue.pop_front(); 	
//	}  
	//second bfs
//	for(i=1;i<=N;i++)
//		visited[i]=false;
//	queue.clear();
//	queue.push_back(p);
//	visited[p]=true;
//	last=p;
//	while(queue.size())
//	{
//	
//		for(i=0;i<edge[queue[0]].size();i++)
//		{
//			if(!visited[edge[queue[0]][i]])
//			{
//				visited[edge[queue[0]][i]]=true;
//				queue.push_back(edge[queue[0]][i]);
//				tail=edge[queue[0]][i]; 
//			}	
//		}
//		depth.push_front(queue[0]);//pop一个，depth就记录之。 
//		queue.pop_front(); 
//		if(last==depth[0]&&queue.size())//如果last==depth[0]==queue[0]，即换层了。并且不是最后一层，那么就把上一层记录的depth全clear掉。 
//		{
//			depth.clear(); 
//			last=tail; 
//		}
// 
//	}
//	depth.push_back(p);
//	sort(depth.begin(),depth.end());
//	while(depth.size())
//	{
//		printf("%d\n",depth[0]);
//		depth.pop_front(); 	
//	}
	
	//second dfs;
	for(i=1;i<=N;i++)
		visited[i]=false;
	k=0;//mark the deepest depth
	DFS(depth[0],1);
	for(i=0;i<depth.size();i++)
	{
		all.insert(depth[i]);
	}
	set<int>::iterator intp; 
	for(intp=all.begin();intp!=all.end();intp++)
	{
		printf("%d\n",*intp);
	}
	return 0;	
}  

//第一次遍历找到某一端。第二次遍历，找到除该端点外的所有端点。注意点是不但第二次dfs的最长路要全部记录，第一次的dfs也要全部记录，这样端点才肯定不会遗漏。
//之前一直有几个测试点过不去，就是因为没有把第一次的也全部记录。这是使用树的直径定理时要注意的地方。
//学习了set容器，set集合容器采取了红黑树的平衡二叉检索树的数据结构，在插入，删除时会自动将其调整为平衡二叉检索树。
//set的遍历采用中序遍历，因而会自动的将元素按键值从小到大排序。它的遍历就是for(intp=all.begin();intp!=all.end();intp++)这种形式，不要纠结为什么是!=而不是<=. 
//尝试使用了bfs和dfs两种方式去做second的遍历，dfs要注意递归时里面的i,j不能是static，可以被其他层递归修改。
//bfs就是使用last和tail两个标记，确定换层了。bfs那部分没有高兴修改记录两次遍历的所有最远端点。  
