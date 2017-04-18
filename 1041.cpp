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

//cin是sacnf的双倍时间。
//套路，对于按input顺序输出，可以开一个数组专门记录input的顺序。然后用这个数组做index遍历存的数据。
