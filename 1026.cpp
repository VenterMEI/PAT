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
		return p1.start<p2.start;//关于同时start的情况，题目里没有说怎么处理，相应的，也没有考这个的测试点。 
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
		if(tmp.last>120)//持续时间不能超过2小时。 
			tmp.last=120;
		queue.push_back(tmp);  
	}
	cin>>k>>m;
	while(m--)
	{
		cin>>i;
		tableRank[i-1]=true;	
	}	
/* 不能这样做，选tableFree最小者是错误的。因为对于九点到的人来说，table是8点半free还是8点10分free是没有区别的。 
	//calcute
	for(i=0;i<queue.size();i++)
	{
		int min=1<<31-1,index,ip;
		//find free table
		for(j=0;j<k;j++)//一开始写的是for(j=0;i<k;i++)，简直爆炸 
		{
			if(min>tableFree[j])
			{
				index=j;
				min=tableFree[j];
			}
		}
		//find next pair of palyer
		min=1<<31-1;
		//不管是不是vip table， 不管有没有成队列，先选出queue里arrive最小的。
		//这里有个注意点，就是成不成队列。不成队列，先到先得。成队列，才涉及vip优先。注意，成队列才涉及vip优先。 
		for(m=0;m<queue.size();m++) 
			if(min>queue[m].arrive&&!visited[m])
			{
				ip=m;
				min=queue[m].arrive;		
			}
		min=1<<31-1;	
		if(tableRank[index])//如果是vip table，那么redim min，再遍历一次。 
		{
			for(m=0;m<queue.size();m++)
				//if(min>queue[m].arrive&&!visited[m]&&queue[m].is_vip)
				//上面这个判断是不正确的。就拿sample来说。20点后，table都空出来了。但是2号vip table应该处理的是8:52
				//的normal，而不是8:53的vip。因为当时空着的table还没有成queue，应该按先到先得处理。 
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
		//现在由于测试过测试点，补充了该判断。如果第一个是vip，就逐个vip table找，看有没有free的。 
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
		//如果没有free的vip table。那么逐个table排查，如果存在table满足tableFree小于最早的arrive，即有空table,那么不用管vip了，先到的去对应的table去start。
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
		if(!have_free)//如果找不到空table 
		{
			//find free table at first寻找最早free的table 
			for(j=0;j<k;j++)//一开始写的是for(j=0;i<k;i++)，简直爆炸 
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
				for(j=0;j<queue.size()-i;j++)//每循环依次，就有一个被visited，所以查找范围-1。 
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
		//小套路：把visited的pair放到最后，再删除原来的这个pair。这样经排序的queue的队首的arrive永远最小，不需要再遍历queue了，复杂度降低一个N。
		//但要注意，如果循环了i次，那么queue里实际未被visited的成员为[0，queue.size()-i]。	
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

//round四舍五入，round up to 四舍五入到多少位。round up 进一，round down 去尾。
//四舍五入的套路：（t+5）/10  如果t<=4，那么结果为0,。如果t>4,结果为1. 
//player既记录hh,mm,ss，也记录time。骚的一笔。 
//排查半天，i和j的混淆导致的循环出错。
//替代visited，不用遍历，降低时间复杂度的方法：先排序，然后将将队首插入队尾，删除队首。 

//一开始我理解的是，不成队列（有free的table），先到的人去index最小的table。
//需要排队了，每次table空出来，不是vip table，找队首。是vip table，找first vip in the queue。
//但后来和测试点对比发现是有问题的。有一个我觉得有争议的地方，就是即使不排队，vip pair来了也是优先去free的vip table。
//但题目明明是When a VIP table is open, the first VIP pair in the queue will have the priviledge to take it.  
//此题体现出的许多模拟排队的问题
//1.不超过2小时。max（time,2*60）
//2.两种情况，需要排队和不需要排队。需要排队才找tableFree最小的，不需要排队只要找index最小的即可。
//3.特殊情况单独处理，之后既可以以人为核心去解决问题，也可以以table为核心去解决问题。
//以table为核心，先考虑队首是否为vip。不是vip，看看成不成队。不成队简单，成队的话，找出最先free的table，table是vip，找first vip in the queue；不是，让队首去start。
//以人为核心，队首是vip。先找最先free的vip table，再找free的table，最后找先free的table。队首不是vip，先找free的table，再找先free的table。
//如果这个table是vip table，那么看看队列里有没有vip（该判断仅用于成队的情况，不成队不用判断）。 
