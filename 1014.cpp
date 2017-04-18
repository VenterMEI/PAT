#include<iostream>
#include<deque>
using namespace std;

int N,M,K,Q;//windowsnumber,capacity,customer,query(ѯ��)
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
	
	if(N*M>K)//�Ȱѻ����ڵ�ѹ����Ȼ���ٽ����� 
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
	
	for(i=1;i<=K;i++)//�ȴ����н��г��� 
	{
		if(N*M+i<=K)//�Ƚ� 
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
			line[shorestLine].pop_front();//�ٳ� 
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

//INT_MAX��PAT�ﲻ���ã�ֱ���ã�1<<31��-1���ɡ�
//��Ŀ��17:00�Ժ󣨺�17��00����������ģ�����sorry����17��00ǰ�Ѿ���ʼ����ľʹ�ӡ����ʱ�伴�ɡ������ڳ���17��59�Ĵ�����ĿҲû˵����ֱ�ж����� 
//�ҵ�˼·���Ƚ����ߣ�ֻ�����������ٽ������⣨�߽��߳�������������ֻ����������
//���Ǻܺõ�˼·�����ڴ���ε��ظ����൱�鷳��Ӧ�� wait�Ƿ�>=540���ж�Ӧ���г��ĵط������жϡ���һ�ε���ֻ�ڼ�ֻ�������ĵط������жϣ����Ե���ʼ�չ����ˡ�
//ԭ������ڱ߽��߳���ʱ��ͳ�����>=540�Ĺ˿͡�
//����һ�δ���ͺܼ�����ֻ��һ�α߽��߳������ȣ��ҵ�minLine��Ȼ����minLine��ӡ����ţ��жϻ������Ƿ���������������minLine���ӡ�
//ÿ��Line����һ��record����¼�ո��Ǹ��뿪�ͻ���wait����ô�±䶯��Line��front��wait�͵���record+cost�����ȫ��������������wait�Ѹ��£������ٳ��ˡ� 

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
