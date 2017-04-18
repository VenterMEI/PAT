#include<iostream>
#include<deque>
using namespace std;

int n,m,s,d;
int i,j;
int map[510][510],cost[510][510],dis[510],pay[510];//����dis�ǵ��յ�ľ��룬���ǵ����ľ��� 

void rdfs(int x)
{
	if(x==s)
		return;
	for(int k=0;k<n;k++)
	{
		if(map[x][k])
		{
									
			if(dis[k]>dis[x]+map[k][x])
			{
				dis[k]=dis[x]+map[k][x];
				pay[k]=pay[x]+cost[k][x];
				rdfs(k);
			}
			else if(dis[k]==dis[x]+map[k][x]&&pay[k]>pay[x]+cost[x][k])
			{	
				pay[k]=pay[x]+cost[k][x];
				rdfs(k);//���д��rdfs[k]�ͻ�warnning����Ѻ���ָ�뵱�������ˡ�warning�����ˣ����ؼ����ǽ����˵ݹ麯���ˡ�
				   		//[Warning] pointer to a function used in arithmetic [-Wpointer-arith]
			}
		} 
	}
}

void dfs(int x)//����㿪ʼ��ӡ 
{
	if(x==s)
		cout<<s<<" ";
	for(int k=0;k<n;k++)
	{
		if(map[x][k]&&dis[x]==map[x][k]+dis[k]&&pay[x]==pay[k]+cost[x][k])
		//map[x][k]�����٣���ΪĬ�ϵ�map��cost����0.��������x==k�Ļ�������Ҳ����������Ȼ�ǲ�Ӧ�ý���ѭ���ġ� 
		{
			cout<<k<<" ";
			if(k!=d)
				dfs(k);	
		}	
	}
}

//void dfs(int x)//���յ㿪ʼ��ӡ 
//{
//	for(int k=0;k<n;k++)
//	{
//		if(map[x][k]&&dis[x]==map[x][k]+dis[k]&&pay[x]==pay[k]+cost[x][k])
//		{
//			
//			dfs(k);	
//			cout<<k<<" ";
//			if(x==s)
//				cout<<s<<" ";	
//		}	
//	}
//
//}
 
int main(void)
{
	cin>>n>>m>>s>>d;
	while(m--)
	{
		cin>>i>>j;
		cin>>map[i][j];
		map[j][i]=map[i][j];
		cin>>cost[i][j];
		cost[j][i]=cost[i][j]; 
	}
	for(i=0;i<n;i++)
	{
		dis[i]=1<<31-1;
		pay[i]=1<<31-1;	
	}	
	dis[d]=0;
	pay[d]=0;
	rdfs(d);
//	cout<<"dis: "<<dis[0]<<" "<<dis[1]<<" "<<dis[2]<<" "<<dis[3]<<endl;
//	cout<<"pay: "<<pay[0]<<" "<<pay[1]<<" "<<pay[2]<<" "<<pay[3]<<endl;
	dfs(s);
	cout<<dis[s]<<" "<<pay[s];
	return 0;
}

//������main��ı������Զ���ʼ����
 
//�����һ�����·��������Dijkstra�����Ƕ�����������·�е�cost��С·����������dfs���ɡ�
//��һ�鷴���������յ�Ϊ��㣬�Ѹ���node���յ����Сdistance��cost����ǳ�����
//�ڶ����������������x���ڽӵ�������dis��pay�ļӺͣ���ô˵������ڽӵ���������ʡ·�С�
//��ʵҲ���Ե�һ�����������ڶ��鷴�����������ȽϷ����߼���
//����Ҫ�޸��µڶ���dfs������˵������������ݹ�������ȷ��ʵĺ�printf������˵�ѵݹ����printf֮ǰ��
//�ο�ע�͵Ĵ��յ㿪ʼ��ӡ�������һ�����������Ļ������ķ�������ӡ�������ŵ�˳���ˡ� 

//��������Dijkstra��ȣ����������⣬һ��������ʱ�临�Ӷȣ��Ϳռ临�Ӷȣ���Dijkstra��̫���ˡ����ǣ������������ͬcost��dis��·���������޷��б�
//��Ȼ��Dijkstra����Ŀǰ��û�뵽��ô�����ӡ�����⡣
//�����������������������µ�1018����˼·��
/*
���ȣ���dist��С��node������Ҳ�����break��������
Ȼ�󣬸�����С��node���ڽӵ㡣����ڽӵ���º��dist��ԭ����С����ô����dist��������path�������ͬ���ͼ���path��
(ʵ���϶���cost������˵������ֱ���ж���ͬdist˭��cost��С�Ϳ���ȡ�ᡣ�������bike���⣬�ȿ��ܳ��������Ҳ�����٣�ֻ���ȼ�¼��)
Ȼ�����ǵõ������е����·��Ҳ����deque����path������dfsһ�����path���Ϳ���������𰸡� 
*/ 
