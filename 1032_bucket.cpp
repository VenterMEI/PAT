#include<iostream>
#include<string>
using namespace std;

int nextgjz[100010],record[100010],s1,s2,n;//next是关键字 
char s[2];
int i,j;
bool is_found;
 
int main(void)
{
	//input
	cin>>s1>>s2>>n;
	while(n--)
	{
		scanf("%d%s%d",&i,s,&j); 
		nextgjz[i]=j;
	}
	 
	//bucket
	while(s1!=-1) 
	{
		record[s1]=true;
		s1=nextgjz[s1];
	}
	while(s2!=-1)
	{
		if(record[s2])
		{
			is_found=true;
			break;
		}
		s2=nextgjz[s2];
	}
	//output
	if(is_found)//这个哨兵是不能少的。因为找得到要输出五位数字，找不到要只要输出1位。 
//		cout<<s1<<endl;//我日，遇到几位数字的id一定要注意%0nd啊
		printf("%05d\n",s2); 
	else
		cout<<"-1"<<endl;	
	return 0;
}
 
 
//用bucket是o(n)复杂度的，用二重循环是o(n^2)复杂度的 
//scanf是不安全的，像%c连回车也读。可以把字符当字符串来读。 
//100000*100000是100亿次运算了，cin和scanf虽然在oj里有差距，但十万规模的还没什么影响。 
