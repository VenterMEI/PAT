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

//��������Զ����ƵĲ����ʾһ�����ġ�
/*
	char c=255;// 1111 1111
	printf("%d",c);//-1 //�����ԭ����-127	
*/ 
//ԭ�벹���ת����
/*
�����Ĳ����ԭ����ͬ��
����ԭ�뵽���룬����λ��1�����䣬����ֵ����ȡ��+1.
�����Ĳ��뵽ԭ�룬����λ��1�����䣬����ֵ����-1ȡ��������ȡ��+1. 
*/ 
//int���ֵ��(1<<31)-1,���Ų����٣����ȼ�Ե�ʡ�int��Сֵ1<<31. 
//int��10λ��long long��19λ��ull��20λ�� 
//֮ǰ�Ǹ�long longû��20λ����������Ϊ������ll=int*int���ұߵĳ˻���Ϊint�� 
