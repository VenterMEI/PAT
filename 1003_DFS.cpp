/*
1003. Emergency (25)

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
As an emergency rescue team leader of a city, you are given a special map of your country. The map shows several scattered cities connected by some roads. Amount of rescue teams in each city and the length of each road between any pair of cities are marked on the map. When there is an emergency call to you from some other city, your job is to lead your men to the place as quickly as possible, and at the mean time, call up as many hands on the way as possible.

Input

Each input file contains one test case. For each test case, the first line contains 4 positive integers: N (<= 500) - the number of cities (and the cities are numbered from 0 to N-1), M - the number of roads, C1 and C2 - the cities that you are currently in and that you must save, respectively. The next line contains N integers, where the i-th integer is the number of rescue teams in the i-th city. Then M lines follow, each describes a road with three integers c1, c2 and L, which are the pair of cities connected by a road and the length of that road, respectively. It is guaranteed that there exists at least one path from C1 to C2.

Output

For each test case, print in one line two numbers: the number of different shortest paths between C1 and C2, and the maximum amount of rescue teams you can possibly gather.
All the numbers in a line must be separated by exactly one space, and there is no extra space allowed at the end of a line.

Sample Input
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
Sample Output
2 4
*/ 

//scattered  ��ɢ��
//��ĿҪ������rescue team��ָ���������·���е�rescue team��� 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

/*
����˼·������DFS��������ÿ�ֿ��ܣ���Ȼͨ��shorestPath<length�ų��˺ࣩܶ��
��DFS�����ķ�ʽ�ǣ�ר�Ź���һ��DFS�ݹ麯������cityStart��û��c2ʱ������cityStart������δ�����ʹ����ڽӳ��С�
������ڽӳ�����Ϊ�ѷ��ʺ�Ȼ��ʼDFS�ݹ顣
ע�⣬�ݹ��������ⲽ����Ҫ�������ո���Ϊ�ѷ��ʵĳ���������Ϊδ���ʡ�
������ȷ��������ͬ���������ڽӳ�����DFSʱ�����ܺ�����ͬ���δ���ʳ��С�
���ȷ����ÿ��cityStart��DFS���ܳɹ������Ӧ�еı�����
DFSÿ��һ�㣬�Ͷ�һ�����б�markΪ�ѷ��ʡ�û�˻�һ�㣬�Ͷ�һ�����б�markΪδ���ʡ� 
*/
int cityNum,roadNum,c1,c2;
int road[500][500];
int rescueTeam[500];
int shorestPath=-1,maxRTA=-1;
bool visited[500]={};
int cnt;
void dfs(int cityStart,int length,int RTA);//��������ʱҪ��ʹ��δ��Ϊ��������ı�������ô�������������main���档 

int main(void){ 
	
	int i,j,k;
	scanf("%d%d%d%d",&cityNum,&roadNum,&c1,&c2);
//	int road[cityNum][cityNum];//�走����scanfcityNum������cityNum����road��ά���顣�Ⱥ�˳���Ȼ�㷴�ˣ����˰��칦��ŷ��֡� 
	for (i=0;i<cityNum;i++){
		scanf("%d",&rescueTeam[i]);
	}
	for(i=0;i<cityNum;i++)
		for(j=0;j<cityNum;j++){
			if(i==j)
				road[i][j]=0;	
			else
				road[i][j]=-1;	
		}
	for(i=1;i<=roadNum;i++){
		scanf("%d%d",&j,&k);
		scanf("%d",&road[j][k]);
		road[k][j]=road[j][k];
	}
	

	visited[c1]=true;
	dfs(c1,0,rescueTeam[c1]);
	printf("%d %d",cnt,maxRTA);

	return 0;

} 

void dfs(int cityStart,int length,int RTA){
	if(shorestPath<length&&shorestPath!=-1)
		return;
	if(cityStart!=c2){
		for(int i=0;i<cityNum;i++){
			if(!visited[i]&&road[i][cityStart]!=-1){
				visited[i]=true;
				dfs(i,length+road[i][cityStart],RTA+rescueTeam[i]);
				visited[i]=false;
			}
		}	
	}
	if(cityStart==c2){
		if(shorestPath>length||shorestPath==-1){
			shorestPath=length;
			maxRTA=RTA;
			cnt=1;
		}else if(shorestPath==length){
			cnt++;
			if(maxRTA<RTA)
				maxRTA=RTA;
		}
	} 
	return;
} 

//learning:
//table�����������ƣ�shift+table�����������ƣ�������
//��������ʱҪ��ʹ��δ��Ϊ��������ı�������ô�������������main���档 
//PATҪʹ��bool�ͱ���include<stdbool.h> ��������벻ͨ���� 
//Ҫ��INT_MAX��Ҫ��include<stdlib.h>.��PAT�ﲻ����ʹ��INT_MAX������Ҫ����INT_MAXʱ���������ñ�����printf��INT_MAX����Ȼ����#define INT_MAX 2147483647�� 
//include<math.h>  a=pow(a,b)��ע�⣬ ��pow��a,b���У�a,b��pow(a,b)����double���͡�����Ҫprintf pow��a��b���Ļ�Ҫ��int����ǿ������ת����
//exp��ָ����������eΪ�ף�exp��a��==int��a����pow���ݺ�����pow��a��b��==a^b�� 
