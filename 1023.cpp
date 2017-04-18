#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

char num1[21];
int digit[10]={}; 
int i,j,doub=0;
int num2[22]={}; 
bool flag=true;

int main(void)
{
	cin>>num1;
	for(i=0;i<strlen(num1);i++)
	{
		j=num1[i]-'0';
		digit[j]++;	
	}
	//先用num1来scanf，然后录入digit里。再将num1转化为数字并乘2。在逐个读数字去更新digit。但是这doub是可能超过int范围的，所以一切操作都应该在字符串里完成。 
//	j=1;
//	for(i=strlen(num1)-1;i>=0;i--)
//	{
//		doub=doub+(num1[i]-'0')*j;
//		j*=10;
//	}
//
//	doub*=2;
//	j=doub;
//	while(j)
//	{
//		i=j%10;
//		digit[i]--;
//		j/=10;
//	}
//	for(i=0;i<10;i++)
//	{
//		if(digit[i])
//		{
//			flag=false;
//			break;
//		}
//	}
	for(i=strlen(num1)-1;i>=0;i--)
	{
		j=(num1[i]-'0')*2+num2[i+1];
		num2[i]+=j/10;
		num2[i+1]=j%10;
		digit[j%10]--;
	}
	if(j/10){//位数不同，必然错误。
		flag=false;
	} 
	for(i=0;i<10;i++)
	{
		if(digit[i])
		{
			flag=false;
			break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	if(num2[0])
		cout<<num2[0];
	for(i=1;i<=strlen(num1);i++)
		printf("%d",num2[i]);	
	return 0;
}

//这题必然使用string去scanf。一则即便long long 才19位，大约9.2*10^18，unsinged long long是20位,是不能完全表示所有20位的数字的。
//string的优点是计数方便，遍历数组即可。int的有点是double方便，*2即可。
//本题两条陷阱。1.所有操作都要在数组里完成，用int或long long都可能超过量程。2.要考虑到开头进位，num2比num1的空间大1位。 
