#include<iostream>
#include<string>
using namespace std;

int nextgjz[100010],s1,s2,n;//next是关键字 
//char s[100010];//一开始想用开个字符数组把字符一个个存进去。后来发现不好，第一，存进去了但这条题目用不到。第二，scanf是有安全性问题的，如%c也读回车，就bug了。
char s[2];//解决的办法就是当字符串来读。 
int i,j;
 
int main(void)
{
	//input
	cin>>s1>>s2>>n;
//不懂为啥scanf就是读不了 
/* 
	while(n--)
	{
		//cin>>i>>s[i]>>j;//不允许这样赋值。不能在一次输入中，同时读和使用。	
		//scanf("%d %c %d\n",&i,&s[i],&j); 
//		cin>>i;
		scanf("%d",&i); 
//		cin>>s[i]>>j;
		scanf("%s",&s);
		scanf("%d",&j);
//		cout<<"i:"<<i<<" j:"<<j<<" s[i]"<<s[i]<<endl;
		nextgjz[i]=j;	
	}	
*/
	while(n--)
	{
		scanf("%d%s%d",&i,s,&j); 
		nextgjz[i]=j;
	}
	 
	//find
	bool is_found=false;
	while(s1!=-1)
	{
		n=s2;
		while(n!=-1)
		{
			
			if(s1==n)
			{
				is_found=true;
				break;
			}
			n=nextgjz[n];
//			cout<<s[s1]<<" "<<s[s2]<<endl;
		} 
		if(is_found)
			break;
		s1=nextgjz[s1]; 
//		cout<<s1<<endl;	
	}
	
	//output
	if(is_found)
//		cout<<s1<<endl;//我日，遇到几位数字的id一定要注意%0nd啊
		printf("%05d\n",s1); 
	else
		cout<<"-1"<<endl;	
	return 0;
}
 
 
//五位digit用int存储就行，因为不存在00002和002的区别。都是一一对应的。 
//next是关键字，尽量不要使用一些常见英文单词，可能编译器通过了但oj通过不了。 
//不能在一次输入中，同时读和使用一个变量。
//遇到输出id一定要想想要不要补0，不能因为这个扣分啊。 
//scanf是不安全的，像%c连回车也读。可以把字符当字符串来读。 
//100000*100000是100亿次运算了，cin和scanf虽然在oj里有差距，但十万规模的还没什么影响。 
