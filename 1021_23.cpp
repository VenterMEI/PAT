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

	���Ϸ�����һ�����������һ�����ֱ�ָ������������֪��������һ���������㲻�ܰ�����ָ���������ϲ���һ�������⵼��forest��size���	
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
//		parent[j]=i;	//�����жϻ�����ʵҲ��һ���ǻ�������˵һ����������rootֻ����һ��������������жϣ������������Ե㲻��ͨ�� 
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
		root[i].clear();//��ʱ�ͷţ���Ȼ�ڴ泬�ޡ� 
	}


	for(i=1;i<=N;i++)
	{
		if(deepest==height[i])
			printf("%d\n",i);
	} 
	
	return 0;
} 

//��Ŀ�����⣬�����л��Ĳ��ܳ�Ϊ������һ��ʼ�뷨��һ���ڽӵĽ�㣬���±�С�ĵ������±���parent��ΪС���±ꡣ
//��ĳ���±��parent�Ȳ���Ĭ��ֵ��������û������������ٴθı���,��˵����������root���༴��������
//�������뷨�Ǵ���ġ���Ϊ���������� 3\n 1 3\n 2 3\n.��ʵ������node 3 ������root������3��root��1 2��Ҷ�ӡ� 
//ѧϰ����������edge[10001][10001]�������洢����һ�ڣ�����������ģ���ڽ�����ķ�ʽ�Ĵ��档 ---------------->>���������������������ڽӾ���
//�����ڴ泬�ޣ�Ҫ��ʱ�ͷš��������г�ʱ��Ҫ�����㷨���Ӷȡ��۵�2��ʱ��Ϊ���ӶȽϸߣ����г�ʱ�� 
//ѧϰ�����鼯������ֱ����
 

/*
����ֱ��������һ��u�������ѵ�����Զ��϶�������ֱ�������ϵ��·���������˵�֮һ���ٴӸö˵�������Ϳ����ѵ���һ����Զ�㡣 
����ֱ����֤����
�������·�����·�����˵㣬p1��p3���··����һ��Ϊp2���··����һ��Ϊp0���������������
1.u���·��·���ϣ������ѵ���Զ�㲻��p1��p3������t����dis(u,t)>dis(u,p1)��dis(u,t)>dis(u,p3)��
��dis(u,t)+dis(u,p3)>dis(u,p1)+dis(u,p3)����dis(t,p3)>�·dis(p1,p3),ì�ܡ� 
2.u���·��·���⣺���������һ����u���ߵ��··����ĳ��p2.���p2��������Զ�����p1��p3�����1��֤����
һ����u����Զ��t��·�����··�����ཻ����dis(u,t)>dis(u,p2)+dis(p2,p1)����dis(u,t)+dis(p3,p2)>dis(u,p2)+dis(p1,p2)+dis(p2,p3)�� 
��dis(t,u)+dis(u,p2)+dis(p2,p3)>2*dis(u,p2)+dis(p1,p2)+dis(p2,p3)>dis(p1,p2)+dis(p2,p3)=dis(p1,p2)����dis(t,u)+dis(u,p2)+dis(p2,p3)�� 
*/ 
