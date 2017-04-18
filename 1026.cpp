#include<iostream>
#include<deque>
#include<algorithm> 
using namespace std;

struct player
{
	int hour,minute,second;
	int arrive;
	int start;
	int last; 
	bool is_vip;	
};
deque<player> queue;
int n,k,m,tableFree[100]={},tableCnt[100]={};
bool tableRank[100]={},visited[1000]={},flag=false;
int i,j,l;
int hour, minute,second;

bool start(player p1,player p2)
{
//	if(p1.start!=p2.start)
		return p1.start<p2.start;//����ͬʱstart���������Ŀ��û��˵��ô������Ӧ�ģ�Ҳû�п�����Ĳ��Ե㡣 
//	else 
//		return p1.arrive>p2.arrive; 		  
}
bool arrive(player p1,player p2)
{
	return p1.arrive <p2.arrive; 
}
 
int main(void)
{
	//input&&init	
	cin>>n;
	while(n--){
		player tmp;  
		scanf("%d:%d:%d %d %d",&tmp.hour,&tmp.minute,&tmp.second,&tmp.last,&tmp.is_vip);
		tmp.arrive=tmp.hour*3600+tmp.second+tmp.minute*60;
		if(tmp.last>120)//����ʱ�䲻�ܳ���2Сʱ�� 
			tmp.last=120;
		queue.push_back(tmp);  
	}
	cin>>k>>m;
	while(m--)
	{
		cin>>i;
		tableRank[i-1]=true;	
	}	
/* ������������ѡtableFree��С���Ǵ���ġ���Ϊ���ھŵ㵽������˵��table��8���free����8��10��free��û������ġ� 
	//calcute
	for(i=0;i<queue.size();i++)
	{
		int min=1<<31-1,index,ip;
		//find free table
		for(j=0;j<k;j++)//һ��ʼд����for(j=0;i<k;i++)����ֱ��ը 
		{
			if(min>tableFree[j])
			{
				index=j;
				min=tableFree[j];
			}
		}
		//find next pair of palyer
		min=1<<31-1;
		//�����ǲ���vip table�� ������û�гɶ��У���ѡ��queue��arrive��С�ġ�
		//�����и�ע��㣬���ǳɲ��ɶ��С����ɶ��У��ȵ��ȵá��ɶ��У����漰vip���ȡ�ע�⣬�ɶ��в��漰vip���ȡ� 
		for(m=0;m<queue.size();m++) 
			if(min>queue[m].arrive&&!visited[m])
			{
				ip=m;
				min=queue[m].arrive;		
			}
		min=1<<31-1;	
		if(tableRank[index])//�����vip table����ôredim min���ٱ���һ�Ρ� 
		{
			for(m=0;m<queue.size();m++)
				//if(min>queue[m].arrive&&!visited[m]&&queue[m].is_vip)
				//��������ж��ǲ���ȷ�ġ�����sample��˵��20���table���ճ����ˡ�����2��vip tableӦ�ô������8:52
				//��normal��������8:53��vip����Ϊ��ʱ���ŵ�table��û�г�queue��Ӧ�ð��ȵ��ȵô��� 
				if(min>queue[m].arrive&&!visited[m]&&queue[m].is_vip&&queue[m].arrive<tableFree[index])
				{
					
					ip=m;
					min=queue[m].arrive;		
				}		
		}

	//	printf("ip:%d index:%d ",ip,index);
		//update
		visited[ip]=true;
		if(tableFree[index]<queue[ip].arrive)
		{
			queue[ip].start=queue[ip].arrive;	
			tableFree[index]=queue[ip].arrive+queue[ip].last*60;
			
		}
		else	
		{
			queue[ip].start=tableFree[index];
			tableFree[index]=tableFree[index]+queue[ip].last*60;
		}
		if(queue[ip].start<21*3600)
			tableCnt[index]++;
	//	printf("queue[ip].start=%d tableFree[index]=%d\n",queue[ip].start,tableFree[index]);	
	}
*/	
	
	//calcute
	sort(queue.begin(),queue.end(),arrive);
	for(i=0;i<queue.size();i++)
	{
		int min=1<<31-1,index,ip;
		bool have_free=false;
		//�������ڲ��Թ����Ե㣬�����˸��жϡ������һ����vip�������vip table�ң�����û��free�ġ� 
		if(queue[0].is_vip)
		{
			ip=0;
			for(j=0;j<k;j++)
				if(tableRank[j]&&tableFree[j]<=queue[0].arrive)
				{
					have_free=true;
					index=j;
					break;
				}	
		}
		//���û��free��vip table����ô���table�Ų飬�������table����tableFreeС�������arrive�����п�table,��ô���ù�vip�ˣ��ȵ���ȥ��Ӧ��tableȥstart��
		if(!have_free)
		{
			for(j=0;j<k;j++) 
			{
				if(tableFree[j]<queue[0].arrive)
				{
					have_free=true;
					index=j;
					ip=0; 
					break;
				}
			}
		}
		if(!have_free)//����Ҳ�����table 
		{
			//find free table at firstѰ������free��table 
			for(j=0;j<k;j++)//һ��ʼд����for(j=0;i<k;i++)����ֱ��ը 
			{
				if(min>tableFree[j])
				{
					index=j;
					ip=0;
					min=tableFree[j];
				}
			}
			//find the palyer
			min=1<<31-1;
			if(tableRank[index])
			{
				for(j=0;j<queue.size()-i;j++)//ÿѭ�����Σ�����һ����visited�����Բ��ҷ�Χ-1�� 
					if(min>queue[j].arrive&&queue[j].is_vip)
					{
						min=queue[j].arrive;
						ip=j;	
					} 
			} 
			else
				ip=0;	
		}
		
		//update
		if(tableFree[index]<queue[ip].arrive)
		{
			queue[ip].start=queue[ip].arrive;	
			tableFree[index]=queue[ip].arrive+queue[ip].last*60;
			
		}
		else	
		{
			queue[ip].start=tableFree[index];
			tableFree[index]=tableFree[index]+queue[ip].last*60;
		}
		if(queue[ip].start<21*3600)
			tableCnt[index]++;
		//С��·����visited��pair�ŵ������ɾ��ԭ�������pair�������������queue�Ķ��׵�arrive��Զ��С������Ҫ�ٱ���queue�ˣ����ӶȽ���һ��N��
		//��Ҫע�⣬���ѭ����i�Σ���ôqueue��ʵ��δ��visited�ĳ�ԱΪ[0��queue.size()-i]��	
		queue.push_back(queue[ip]); 
		queue.erase(queue.begin()+ip);
	} 
	
	 
	//output
	sort(queue.begin(),queue.end(),start);
	while(queue.size()) 
	{
		if(queue[0].start<21*3600)
		{
			printf("%02d:%02d:%02d ",queue[0].hour,queue[0].minute,queue[0].second);
			printf("%02d:%02d:%02d ",queue[0].start/3600,queue[0].start%3600/60,queue[0].start%60);
			printf("%d\n",(queue[0].start-queue[0].arrive+30)/60);
		}
		queue.pop_front(); 
	}
	for(i=0;i<k;i++)
	{
		if(flag)
			cout<<" ";
		else
			flag=true;
		cout<<tableCnt[i];		
	}
	return 0;
} 

//round�������룬round up to �������뵽����λ��round up ��һ��round down ȥβ��
//�����������·����t+5��/10  ���t<=4����ô���Ϊ0,�����t>4,���Ϊ1. 
//player�ȼ�¼hh,mm,ss��Ҳ��¼time��ɧ��һ�ʡ� 
//�Ų���죬i��j�Ļ������µ�ѭ������
//���visited�����ñ���������ʱ�临�Ӷȵķ�����������Ȼ�󽫽����ײ����β��ɾ�����ס� 

//һ��ʼ�������ǣ����ɶ��У���free��table�����ȵ�����ȥindex��С��table��
//��Ҫ�Ŷ��ˣ�ÿ��table�ճ���������vip table���Ҷ��ס���vip table����first vip in the queue��
//�������Ͳ��Ե�Աȷ�����������ġ���һ���Ҿ���������ĵط������Ǽ�ʹ���Ŷӣ�vip pair����Ҳ������ȥfree��vip table��
//����Ŀ������When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it.  
//�������ֳ������ģ���Ŷӵ�����
//1.������2Сʱ��max��time,2*60��
//2.�����������Ҫ�ŶӺͲ���Ҫ�Ŷӡ���Ҫ�ŶӲ���tableFree��С�ģ�����Ҫ�Ŷ�ֻҪ��index��С�ļ��ɡ�
//3.���������������֮��ȿ�������Ϊ����ȥ������⣬Ҳ������tableΪ����ȥ������⡣
//��tableΪ���ģ��ȿ��Ƕ����Ƿ�Ϊvip������vip�������ɲ��ɶӡ����ɶӼ򵥣��ɶӵĻ����ҳ�����free��table��table��vip����first vip in the queue�����ǣ��ö���ȥstart��
//����Ϊ���ģ�������vip����������free��vip table������free��table���������free��table�����ײ���vip������free��table��������free��table��
//������table��vip table����ô������������û��vip�����жϽ����ڳɶӵ���������ɶӲ����жϣ��� 
