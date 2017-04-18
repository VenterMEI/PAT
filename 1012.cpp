//�Ȱ�ÿ��ѧ���ĵ��������������������һ���ṹ���ע��ͬ�ɼ�����������ͬ�ģ�Ȼ��Ƚ������������ɡ� 
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

	i=0;//��¼��ӡ�ĵ�i��ѧ���� 
	while(M--){
		int j=0,is_found=0;//j��������stus��ƥ���i��ѧ����id 
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
				}//���������ֹ���������Ƚϣ�����ѧ����һ������һ��min_index���Ƚϡ������ṹ��Ҫ����һ�£���һ��int���������������װ�����ſ��ԡ� 
				stus.erase(stus.begin()+j);//����һ��ɾһ�� 
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

//ע������ʱ��ͬ�ɼ����������Ȼ�Ⲩ��û������Ȼ������ֱ�������������ȴ�С�������ÿ������������ 
//��Ȼ������Ͱ�����˼�룬ID�ܹ���6λ�����ȥ����ȥƥ���ˡ� 
//������δ������������ͬά�Ȳ�ͬ����Ķ����������ö�ά�����ʾ������ʹ�ýṹ�����������������ࡣƩ��math��English��cs�⼸�ųɼ�����дһ���ṹ�壬����һ��stu[3]�����顣 
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
double c[maxn][4];//[ѧ����ID][����ɼ�]  
char ch[4] = { 'C', 'M', 'E', 'A' };//��c[][]��������ˣ�����չ�ԱȽϺá�  
  
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
    int ans[4] = { 0, 0, 0, 0 };//ans ��������  
    for (int i = 1; i <= n; i++)  
    {  
      for (int j = 0; j < 4; j++) if (c[i][j]>c[f[x]][j]) ans[j]++;//�����������  
    }  
    x = 3;  
    for (int j = 0; j < 3; j++) if (ans[j] < ans[x]) x = j;//����������ҵ��ظ��Ƚ���  
    printf("%d %c\n", ans[x] + 1, ch[x]);  
  }  
  return 0;  
} 
*/ 
