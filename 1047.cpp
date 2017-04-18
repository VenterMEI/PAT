#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;

deque<string> course[2510];
int N,K;
char tmp_name[5];
int i,j,k,t;
bool compare(string s1,string s2)
{
	return ((s1[0]*100+s1[1])*100+s1[2])*100+s1[3]/100<((s2[0]*100+s2[1])*100+s2[2])*100+s2[3]/100;	
} 

int main(void){
	//input
	cin>>N>>K;
	for(i=0;i<N;i++)
	{
		scanf("%s%d",tmp_name,&k);
//		cin>>tmp_name;
//		cin>>k;
		for(j=0;j<k;j++)
		{
			scanf("%d",&t);
//			cin>>t;
			course[t].push_back(tmp_name); 
		}	
	}
	
	//output
	for(i=1;i<=K;i++)
	{
		printf("%d %d\n",i,course[i].size());
//		cout<<i<<" "<<course[i].size()<<endl;
		sort(course[i].begin(),course[i].end(),compare); 
		for(j=0;j<course[i].size();j++)
		{
//			printf("%c%c%c%c\n",course[i][j][0],course[i][j][1],course[i][j][2],course[i][j][3]);
//			cout<<course[i][j]<<endl;
			printf("%s\n",course[i][j].c_str());
		}
	}
	return 0;
} 

//超时，应该cin和cout要上亿规模才会超时，那么就是排序的问题。但也已经重新定义了 
 
