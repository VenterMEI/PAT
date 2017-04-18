//先把每个学生的的四项排名都求出来记在一个结构体里，注意同成绩的排名是相同的，然后比较四项排名即可。 
#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
 
typedef struct {
	int ID;
	int C,M,E;
	double A;
	int C_Rank,M_Rank,E_Rank,A_Rank;
}stuInfo;

bool by_C(stuInfo s1,stuInfo s2){
	return s1.C>s2.C;  
}
bool by_M(stuInfo s1,stuInfo s2){
	return s1.M>s2.M;  
}
bool by_E(stuInfo s1,stuInfo s2){
	return s1.E>s2.E;  
}
bool by_A(stuInfo s1,stuInfo s2){
	return s1.A>s2.A;  
}

int main(void){
	deque<stuInfo> stus;
	stuInfo stu;
	int N,M,i=0;
	scanf("%d %d",&N,&M);
	while(N--){
		scanf("%d%d%d%d",&stu.ID,&stu.C,&stu.M,&stu.E);
		stu.A=(stu.C+stu.E+stu.M)/3.0;
		stus.push_back(stu);
	}
	int ID[M];
	while(i<M){
		scanf("%d",&ID[i++]);
	}
	
	int rank=1,cnt=0;
	sort(stus.begin(),stus.end(),by_A);
	double grade_double=stus[0].A;
	while(cnt<stus.size()){
		if(grade_double-stus[cnt].A>10e-10){
			rank=cnt+1;
			grade_double=stus[cnt].A;
		}
		stus[cnt].A_Rank=rank;
		cnt++;
	}

	rank=1,cnt=0;
	sort(stus.begin(),stus.end(),by_C);
	int grade_int=stus[0].C;
	while(cnt<stus.size()){
		if(grade_int!=stus[cnt].C){
			rank=cnt+1;
			grade_int=stus[cnt].C;
		}
		stus[cnt].C_Rank=rank;
		cnt++;
	}
	
	rank=1,cnt=0;
	sort(stus.begin(),stus.end(),by_M);
	grade_int=stus[0].M;
	while(cnt<stus.size()){
		if(grade_int!=stus[cnt].M){
			rank=cnt+1;
			grade_int=stus[cnt].M;
		}
		stus[cnt].M_Rank=rank;
		cnt++;
	}
	
	rank=1,cnt=0;
	sort(stus.begin(),stus.end(),by_E);
	grade_int=stus[0].E;
	while(cnt<stus.size()){
		if(grade_int!=stus[cnt].E){
			rank=cnt+1;
			grade_int=stus[cnt].E;
		}
		stus[cnt].E_Rank=rank;
		cnt++;
	}

	i=0;//记录打印的第i个学生。 
	while(M--){
		int j=0,is_found=0;//j遍历整个stus，匹配第i个学生的id 
		while(j<stus.size()){
			if(ID[i]==stus[j].ID){
				is_found=1;
				if(stus[j].A_Rank<=stus[j].M_Rank&&stus[j].A_Rank<=stus[j].C_Rank&&stus[j].A_Rank<=stus[j].E_Rank){
					printf("%d A\n",stus[j].A_Rank);
				}else if(stus[j].C_Rank<=stus[j].M_Rank&&stus[j].C_Rank<=stus[j].E_Rank){
					printf("%d C\n",stus[j].C_Rank);
				}else if(stus[j].M_Rank<=stus[j].E_Rank){
					printf("%d M\n",stus[j].M_Rank);
				}else{
					printf("%d E\n",stus[j].E_Rank);
				}//如果将来不止四项排名比较，可以学下面一样，用一个min_index来比较。不过结构体要调整一下，用一个int数组把四项排名包装起来才可以。 
				stus.erase(stus.begin()+j);//用完一个删一个 
			}
			j++;
		} 
		if(!is_found){
			printf("N/A\n");
		}
		i++; 
	}
	return 0;
} 

//注意排序时的同成绩的情况。虽然这波我没出错，虽然不排序直接向下面那样比大小根本不用考虑这种情况。 
//依然可以用桶排序的思想，ID总共就6位嘛，不用去遍历去匹配了。 
//下面这段代码告诉我们相同维度不同种类的东西，可以用多维数组表示而不必使用结构体表明各个具体的种类。譬如math，English，cs这几门成绩不必写一个结构体，就是一个stu[3]的事情。 
/* 
#include<map>  
#include<cstdio>  
#include<stack>  
#include<cstring>  
#include<string>  
#include<algorithm>  
#include<iostream>  
using namespace std;  
typedef unsigned long long uLL;  
const int maxn = 2e3 + 10;  
int tot, n, m, x;  
int f[1000005];  
double c[maxn][4];//[学生的ID][四项成绩]  
char ch[4] = { 'C', 'M', 'E', 'A' };//和c[][]配合起来了，可扩展性比较好。  
  
int main()  
{  
  scanf("%d%d", &n, &m);  
  for (int i = 1; i <= n; i++)  
  {  
    scanf("%d", &x);  f[x] = i;  
    for (int j = 0; j < 3; j++) scanf("%lf", &c[i][j]);  
    c[i][3] = (c[i][0] + c[i][1] + c[i][2]) / 3;  
  }  
  while (m--)  
  {  
    scanf("%d", &x);  
    if (!f[x]) { printf("N/A\n"); continue; }  
    int ans[4] = { 0, 0, 0, 0 };//ans 四项排名  
    for (int i = 1; i <= n; i++)  
    {  
      for (int j = 0; j < 4; j++) if (c[i][j]>c[f[x]][j]) ans[j]++;//求出四项排名  
    }  
    x = 3;  
    for (int j = 0; j < 3; j++) if (ans[j] < ans[x]) x = j;//相比起来，我的重复比较了  
    printf("%d %c\n", ans[x] + 1, ch[x]);  
  }  
  return 0;  
} 
*/ 
