#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

deque<long long> coupon,product;
long long total,t;
int m,n;

int main(void)
{
	cin>>n;
	while(n--)
	{
		scanf("%lld",&t);
		coupon.push_back(t); 	
	}
	cin>>m;
	while(m--)
	{
		scanf("%lld",&t);
		product.push_back(t); 	
	}
	sort(coupon.begin(),coupon.end());
	sort(product.begin(),product.end());

	while(coupon.size()*product.size()&&coupon[0]<0&&product[0]<0)
	{
		total+=coupon[0]*product[0];
		coupon.pop_front();
		product.pop_front();  
	}
	while(coupon.size()*product.size()&&coupon[coupon.size()-1]>0&&product[product.size()-1]>0)
	{
		total+=coupon[coupon.size()-1]*product[product.size()-1];
		coupon.pop_back();
		product.pop_back();  
	}
	cout<<total;	
	return 0;
}

//计算机是以二进制的补码表示一个数的。
/*
	char c=255;// 1111 1111
	printf("%d",c);//-1 //如果按原码是-127	
*/ 
//原码补码的转换：
/*
正数的补码和原码相同。
负数原码到补码，符号位（1）不变，绝对值部分取反+1.
负数的补码到原码，符号位（1）不变，绝对值部分-1取反，或者取反+1. 
*/ 
//int最大值是(1<<31)-1,括号不能少，优先级缘故。int最小值1<<31. 
//int有10位，long long有19位，ull有20位。 
//之前那个long long没有20位，可能是因为是形如ll=int*int，右边的乘积仍为int。 
