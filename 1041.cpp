#include <iostream>
using namespace std;


int n,t,i,order[100010],num[100010];
  
  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 0; i < n; i++) 
	{
//		scanf("%d", &order[i]);
		cin>>order[i];
		num[order[i]]++;  	
	}
    for (int i = 0; i < n; i++)  
    {  
        if (num[order[i]] == 1) 
		{ 
			printf("%d\n", order[i]); 
			return 0; 
		}  
    }  
    printf("None\n");  
    return 0;  
}  

//cin��sacnf��˫��ʱ�䡣
//��·�����ڰ�input˳����������Կ�һ������ר�ż�¼input��˳��Ȼ�������������index����������ݡ�
