#include <iostream>
using namespace std;

struct r
{
	int cnt;
	int order;
};
int n,t,i;
r record[10010];
 
int main(void)
{
	for(i=0;i<10010;i++)
	{
		record[i].cnt=0; 
	}
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>t;
		if(!record[t].cnt)
		{
			record[t].cnt=1;
			record[t].order=i;	
		}
		else
		 	record[t].cnt++; 	
	}
	n=10020;
	for(i=0;i<100;i++)
	{  
		if(record[i].cnt==1&&record[i].order<n)
		{
			n=record[i].order;
			t=i;
		}
	}	
	if(n==10020) 
		printf("None\n");  
	else
		printf("%d\n", t);
    return 0;
}

//为什么粗暴的方法只能过一个测试点？？？ 
