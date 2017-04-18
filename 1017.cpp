#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct customer{
	int time;
	int cost;
};
int N,K,num,amount=0;
int window[100];
int h,m,s,cost;
int i,j;
deque<customer> data;

bool by_time(customer c1,customer c2){
	return c1.time<c2.time;
}
int main(void)
{
	cin>>N>>K;
	for(i=0;i<K;i++)
	{
		window[i]=8*3600;
	}
	for(i=0;i<N;i++)
	{
		customer c;	
		scanf("%d:%d:%d%d",&h,&m,&s,&c.cost);
		if(h*3600+m*60+s<=17*3600)
		{	
			c.time=h*3600+m*60+s;
			data.push_back(c);
		}
	}
	
	sort(data.begin(),data.end(),by_time);
	num=data.size(); 
	while(data.size()){
		int min=window[0],minIndex=0;
		for(j=1;j<K;j++)
		{
			if(min>window[j])
			{
				min=window[j];
				minIndex=j;				
			}
		}
		if(data[0].time<=window[minIndex])
		{
			window[minIndex]+=data[0].cost*60;
		}
		else
		{
			window[minIndex]=data[0].time+data[0].cost*60;
		}
		amount+=window[minIndex]-data[0].time-data[0].cost*60;
		data.pop_front(); 
	}	
	printf("%.1f",amount/60.0/num);
	return 0;	
} 
