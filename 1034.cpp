#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;

struct call
{
	string p1;
	string p2;
	int time;	
};
struct r
{
	int parent;
	string name;
	int time;	
};
struct g
{
	int parent;//代表所在集合
	string head;
	int time;//最大者的姓名及其时长
	int total;//总时长 
	int num;//集合人数	
};
deque<g> gang; 
deque<r> record;
int n,k;
int i,j;

int place(string s)
{
	for(int m=0;m<record.size();m++)
	{
		if(s==record[m].name)
		{
			return m;	
		}
	}
	return -1;
}
int find(string s)
{
	int m=place(s); 
	if(m!=-1)
	{
		while(record[m].parent!=m)
			m=record[m].parent;
		return m;	
	}
	return -1;
}
void un(string s1, string s2)
{
	int m1=find(s1);
	int m2=find(s2);
	if(m1!=m2)
		record[m1].parent=m2;
}
void deal_a_call(call c)
{
	int m1=place(c.p1);
	int m2=place(c.p2);
	if(m1==-1)
	{
		r tmp;
		tmp.name=c.p1;
		tmp.parent=record.size();
		tmp.time=c.time;
		record.push_back(tmp);     
	}
	else
		record[m1].time+=c.time;
	if(m2==-1)
	{
		r tmp;
		tmp.name=c.p2;
		tmp.parent=record.size();
		tmp.time=c.time;
		record.push_back(tmp);     
	}
	else
		record[m2].time+=c.time;
	un(c.p1,c.p2);
}
bool compare(g g1,g g2)
{
	return g1.head<g2.head;
}

int main(void)
{
	cin>>n>>k;
	while(n--)
	{
		call tmp;
		cin>>tmp.p1>>tmp.p2>>tmp.time;
		deal_a_call(tmp);  
	}	
	for(i=0;i<record.size();i++)
	{
		int m=find(record[i].name);
		for(j=0;j<gang.size();j++)
		{
			if(gang[j].parent==m)
			{
				gang[j].num++;
				gang[j].total+=record[i].time;
				if(record[i].time>gang[j].time)
				{
					gang[j].time=record[i].time;
					gang[j].head=record[i].name;
				}
				break;			
			}	
		}
		if(j==gang.size())
		{
			g tmp;
			tmp.head=record[i].name;
			tmp.time=record[i].time;
			tmp.num=1;
			tmp.parent=m;
			tmp.total=record[i].time;  
			gang.push_back(tmp);   
		} 
	}
	for(i=0;i<gang.size();)
	{
		if(gang[i].num<3||gang[i].total<=k*2)//注意乘2，一次电话时间会进入两个record里。 
		{
			gang.erase(gang.begin()+i);
			continue;
		}
		i++;
	}
	sort(gang.begin(),gang.end(),compare);
	cout<<gang.size()<<endl;
	for(i=0;i<gang.size();i++)
	{
		cout<<gang[i].head<<" "<<gang[i].num<<endl;
	}
	return 0;
} 

//并查集，这里在find之前，要先通过place函数找到name在数组中的位置。 
