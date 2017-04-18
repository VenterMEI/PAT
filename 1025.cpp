#include<iostream>
#include<deque>
#include<algorithm>
#include<string.h>
using namespace std;

struct stu
{
	char index[14];
	int score;
	int location;
	int rank_f;
	int rank_l;
};
deque<stu> loc[101];
int n,k;
int i,j;
bool compare(stu s1,stu s2)
{
	if(s1.score!=s2.score)
		return s1.score>s2.score;
	else if(strcmp(s1.index,s2.index)<0) 
		return true;
	else
		return false;	
}

int main(void)
{
	//input
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			stu s;
			cin>>s.index>>s.score;
			s.location =i;
			loc[i].push_back(s);  	
		} 
	}
	
	//sort_l
	for(i=1;i<=n;i++)
	{
		sort(loc[i].begin(),loc[i].end(),compare);
		int rank=1,cnt=1,pre=loc[i][0].score;
		while(loc[i].size())
		{
			if(pre!=loc[i][0].score){
				pre=loc[i][0].score;
				rank=cnt;
			}
			cnt++;
			loc[i][0].rank_l=rank;
			loc[0].push_back(loc[i][0]);
			loc[i].pop_front(); 
		}
	}
	
	//sort_f&&output
	cout<<loc[0].size()<<endl;
	sort(loc[0].begin(),loc[0].end(),compare); 
	int rank=1,cnt=1,pre=loc[0][0].score;
	for(i=0;i<loc[0].size();i++)
	{
		if(pre!=loc[0][i].score){
			pre=loc[0][i].score;
			rank=cnt;
		}
		cnt++;
		loc[0][i].rank_f=rank;
		printf("%s %d %d %d\n",loc[0][i].index,loc[0][i].rank_f,loc[0][i].location,loc[0][i].rank_l);
	}	
	return 0;
} 

//13位数字用string记录而不是int，这个自己调试的时候就能发现，不过将来如果index位数是变动的，就有可能因此扣分，值得注意。
//10位数字及以上都用string。
//这次的compare函数也可以学习一哈。 
