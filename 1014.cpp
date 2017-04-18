#include<iostream>
#include<deque>
using namespace std;

int N,M,K,Q;//windowsnumber,capacity,customer,query(询问)
deque<int> line[21];
int wait[1010];
int cost[1010]; 
int query[1010];
int i,j,k,shorestLine;
 
int main(void){
	scanf("%d%d%d%d",&N,&M,&K,&Q);
	for(i=1;i<=K;i++)
	{
		scanf("%d",&cost[i]);
	}
	for(i=1;i<=Q;i++)
	{
		scanf("%d",&query[i]);
	}
	
	if(N*M>K)//先把黄线内的压满，然后再进出。 
	{
		j=1;
		for(i=1;i<=K;i++)
		{
			line[j].push_back(i);
			j++;
			if(j>N)
			{
				j=1;
			}	
		}		
	}else{
		for(j=1;j<=M;j++)
		{
			for(i=1;i<=N;i++)
			{
				line[i].push_back(j*N-N+i); 	
			}	
		} 
	}
	for(i=1;i<=N;i++)
	{
		if(i<=K)
		{
			wait[i]=cost[i];
		}
	}
	
	for(i=1;i<=K;i++)//先处理有进有出的 
	{
		if(N*M+i<=K)//先进 
		{	
			shorestLine=1;
			for(j=2;j<=N;j++)
			{
				if(wait[line[shorestLine][0]]>wait[line[j][0]])
				{
					shorestLine=j; 
				}	
			}
			line[shorestLine].push_back(N*M+i);
			if(wait[line[shorestLine][0]]<540)
			{
				wait[line[shorestLine][1]]=wait[line[shorestLine][0]]+cost[line[shorestLine][1]];
			}else{
				wait[line[shorestLine][1]]=1<<30;
			}
			line[shorestLine].pop_front();//再出 
		}else{
			break;
		}
	}
	for(i=1;i<=N;i++)
	{
		while(line[i].size()!=0)
		{
			if(line[i].size()!=1)
			{	
				if(wait[line[i][0]]<540)
				{
					wait[line[i][1]]=wait[line[i][0]]+cost[line[i][1]];
				}else{
					wait[line[i][1]]=1<<30;
				}
			}
			line[i].pop_front(); 	
		} 
	}
	 
	for(i=1;i<=Q;i++)
	{	
		if(wait[query[i]]==1<<30)
		{
			printf("Sorry\n");
		}else{
			printf("%02d:%02d\n",wait[query[i]]/60+8,wait[query[i]]%60);
		}
	} 
	return 0;
} 

//INT_MAX在PAT里不可用，直接用（1<<31）-1即可。
//题目中17:00以后（含17：00）进来服务的，返回sorry。而17：00前已经开始服务的就打印结束时间即可。（至于超过17：59的处理，题目也没说。简直有毒。） 
//我的思路是先进黄线（只进不出），再进黄线外（边进边出），最后出掉（只出不进）。
//不是很好的思路，存在代码段的重复，相当麻烦。应该 wait是否>=540的判断应该有出的地方就有判断。第一次调试只在加只出不进的地方补了判断，测试点四始终过不了。
//原因就是在边进边出的时间就出现了>=540的顾客。
//下面一段代码就很简明。只有一段边进边出。首先，找到minLine，然后在minLine入队。接着，判断黄线区是否已满，已满就在minLine出队。
//每条Line都有一个record，记录刚刚那个离开客户的wait。那么新变动的Line的front的wait就等于record+cost。最后全进黄线区后，所有wait已更新，不用再出了。 

/*
#include<cstdio>  
#include<string>  
#include<cstring>  
#include<vector>  
#include<iostream>  
#include<queue>  
#include<algorithm>  
using namespace std;  
typedef long long LL;  
const int INF = 0x7FFFFFFF;  
const int maxn = 1e3 + 10;  
int T, a, b, n, q, x, t[maxn];  
queue<int> p[maxn];  
  
struct point  
{  
    int x, y;  
    point(int x = 0, int y = 0) :x(x), y(y){}  
}f[maxn];  
  
int main()  
{  
    scanf("%d%d%d%d", &a, &b, &n, &q);  
    for (int i = 1; i <= n; i++)  
    {  
        scanf("%d", &x);  
        int minx = 1;  
        for (int j = 1; j <= a; j++)  
        {  
            if (i <= a*b)  
            {  
                if (p[j].size() < p[minx].size()) minx = j;  
            }  
            else if (p[j].front() < p[minx].front()) minx = j;  
        }  
        t[minx] += x;  
        p[minx].push(t[minx]);   
        if (i > a*b) p[minx].pop();  
        if (t[minx] - x < 540) f[i] = point(8 + t[minx] / 60, t[minx] % 60);  
        else f[i] = point(18, 0);  
    }  
    while (q--)  
    {  
        scanf("%d", &x);  
        if (f[x].x < 18) printf("%02d:%02d\n", f[x].x, f[x].y);  
        else printf("Sorry\n");  
    }  
    return 0;  
} 
*/ 
