/*
1003. Emergency (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
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

//scattered  分散的
//题目要求的最大rescue team是指在所有最短路径中的rescue team最大。 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 

/*
解题思路：采用DFS暴力遍历每种可能（当然通过shorestPath<length排除了很多）。
他DFS遍历的方式是，专门构造一个DFS递归函数，当cityStart还没到c2时，遍历cityStart的所有未被访问过的邻接城市。
将这个邻接城市设为已访问后，然后开始DFS递归。
注意，递归结束后的这步很重要，即将刚刚设为已访问的城市重新设为未访问。
这样做确保了与它同级的其它邻接城市在DFS时，享受和它相同多的未访问城市。
这才确保了每个cityStart的DFS都能成功完成它应有的遍历。
DFS每深一层，就多一个城市被mark为已访问。没退回一层，就多一个城市被mark为未访问。 
*/
int cityNum,roadNum,c1,c2;
int road[500][500];
int rescueTeam[500];
int shorestPath=-1,maxRTA=-1;
bool visited[500]={};
int cnt;
void dfs(int cityStart,int length,int RTA);//函数调用时要想使用未作为参数表传入的变量，那么这个变量定义在main外面。 

int main(void){ 
	
	int i,j,k;
	scanf("%d%d%d%d",&cityNum,&roadNum,&c1,&c2);
//	int road[cityNum][cityNum];//妈蛋，先scanfcityNum，再用cityNum创建road二维数组。先后顺序居然搞反了，花了半天功夫才发现。 
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
//table代码整体右移，shift+table代码整体左移（缩进）
//函数调用时要想使用未作为参数表传入的变量，那么这个变量定义在main外面。 
//PAT要使用bool型必须include<stdbool.h> ，否则编译不通过。 
//要用INT_MAX，要先include<stdlib.h>.但PAT里不可以使用INT_MAX。所以要想用INT_MAX时，可以先用编译器printf（INT_MAX），然后再#define INT_MAX 2147483647。 
//include<math.h>  a=pow(a,b)。注意， 在pow（a,b）中，a,b及pow(a,b)都是double类型。所以要printf pow（a，b）的话要（int）来强制类型转换。
//exp是指数函数，以e为底，exp（a）==int（a）。pow是幂函数，pow（a，b）==a^b。 
