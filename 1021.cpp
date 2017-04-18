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
	while(parent[x]!=0)//parent[x]==0˵��x��һ������ 
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
		cnt--;//ÿ����Ч�ϲ���cnt--����Ϊcnt=N��ֻ��N-1������ÿ��ǡ����������ͨ�ķ�����ͨ��cnt����N-1��--������ʹcnt=1.
		//�����迼���л����������Ϊ��һ�������˷�һ��cnt--����ôcnt�ز���Ϊ1��Ҳ�����ܳ�����	
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
	for(int i=0;i<edge[index].size();i++)//�ݹ�һ��Ҫע�⣬������int i����Ȼi��static������ݹ����i��һ���ݹ���Ըı�����ֵ�� 
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
//		p=queue[0];//queue�����һ��������һ����depth����֮һ��������ȷ�����·��һ���˵㡣 
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
//		depth.push_front(queue[0]);//popһ����depth�ͼ�¼֮�� 
//		queue.pop_front(); 
//		if(last==depth[0]&&queue.size())//���last==depth[0]==queue[0]���������ˡ����Ҳ������һ�㣬��ô�Ͱ���һ���¼��depthȫclear���� 
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

//��һ�α����ҵ�ĳһ�ˡ��ڶ��α������ҵ����ö˵�������ж˵㡣ע����ǲ����ڶ���dfs���·Ҫȫ����¼����һ�ε�dfsҲҪȫ����¼�������˵�ſ϶�������©��
//֮ǰһֱ�м������Ե����ȥ��������Ϊû�аѵ�һ�ε�Ҳȫ����¼������ʹ������ֱ������ʱҪע��ĵط���
//ѧϰ��set������set����������ȡ�˺������ƽ���������������ݽṹ���ڲ��룬ɾ��ʱ���Զ��������Ϊƽ������������
//set�ı����������������������Զ��Ľ�Ԫ�ذ���ֵ��С�����������ı�������for(intp=all.begin();intp!=all.end();intp++)������ʽ����Ҫ����Ϊʲô��!=������<=. 
//����ʹ����bfs��dfs���ַ�ʽȥ��second�ı�����dfsҪע��ݹ�ʱ�����i,j������static�����Ա�������ݹ��޸ġ�
//bfs����ʹ��last��tail������ǣ�ȷ�������ˡ�bfs�ǲ���û�и����޸ļ�¼���α�����������Զ�˵㡣  
