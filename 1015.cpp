#include<iostream>
#include<deque>
#include<math.h>
using namespace std;

int N,D,i;
deque<int> numstr;

bool is_prime(int num)
{
	if(N==0||N==1){
		return 0;
	}
	for(i=2;i<=sqrt(num);i++)//或者可以换成i*i<=num.
	//注意，这里是i<=sqrt(num)，不要画蛇添足搞个i<=sqrt(num)+1.那样，例如2（仅2啦）就是i遍历1，2，结果不是素数了。 
	{
		if(num%i==0)
		{
			return 0;
		}
	}
	return 1;
}

int main(void)
{
	scanf("%d",&N);
	while(N>=0)
	{
		scanf("%d",&D);
		if(!is_prime(N))
		{
			printf("No\n");
		}
		else{
			while(N!=0)
			{
				numstr.push_back(N%D);
				N/=D;
			}
			while(numstr.size()!=0)
			{
				N=N*D+numstr[0];
				numstr.pop_front(); 
			}
			if(is_prime(N))
			{
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
		scanf("%d",&N);
	}
	return 0;
}

//注意，这里是i<=sqrt(num)，不要画蛇添足搞个i<=sqrt(num)+1.那样，例如2（仅2啦）就是i遍历1，2，结果不是素数了。
//reversible 可逆的    prime 素数 
