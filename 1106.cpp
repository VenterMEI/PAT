#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>
using namespace std;


vector<int> l[100010];
deque<int> queue;
int ml;
int n;
double p,rate;
int i,j,t,level;

int main(void)
{
	cin>>n;
	cin>>p>>rate;
	for(i=0;i<n;i++)
	{
		cin>>j;
		while(j--)
		{
			cin>>t;
			l[i].push_back(t);
		}
	}
	ml=0;
	int tail=0,rear=0,cnt;
	bool is_break=false;
	queue.push_back(0); 
	while(queue.size())
	{
		if(!l[queue[0]].size())
		{
			if(!is_break)
			{
				is_break=true;
				cnt=1;
				for(i=0;i<ml;i++)
					p*=1+rate*.01;
				printf("%.4lf ",p);
			}
			else
				cnt++;
		}
		for(i=0;i<l[queue[0]].size();i++)
		{
			queue.push_back(l[queue[0]][i]);
			tail=l[queue[0]][i];
		}
		if(rear==queue[0])
		{
			rear=tail;
			ml++;
			if(is_break)
				break;
		}
		queue.pop_front(); 
	}

	cout<<cnt<<endl;
	return 0;
}

//����������㣬���ý����ṹ�塣��ʵ�����ü�¼���������е�ʱ�����p�Ϳ����ˡ�
//