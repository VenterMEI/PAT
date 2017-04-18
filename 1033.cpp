#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

struct station
{
	double price;
	int distance; 
}; 
double tank,dis,avg;
deque<station> s;
station tmp;
int n,i,j,path[510];

bool compare(station s1,station s2)
{
	if(s1.distance!=s2.distance)
		return s1.distance<s2.distance;
	else
		return s1.price<s2.price; 	  	
} 

void DFS(int x,double cost,double rest)
{
//	cout<<x<<" "<<cost<<" "<<rest;
	int index,k;
	double minprice=1<<31-1;
	for(k=x+1;k<n;k++)
	{
		if(s[x].distance+tank*avg<s[k].distance)
			break;
		if(minprice>s[k].price)
		{
			index=k;
			minprice=s[k].price;	
//			cout<<" index:"<<index<<" minprice "<<minprice; 
		}
		if(s[x].price>s[k].price)
		{
			break;
		}
	}
	if(minprice==1<<31-1&&s[x].distance+tank*avg<dis)
	{
//		cout<<" "<<"1"<<endl;
		printf("The maximum travel distance = %.02lf",s[x].distance+tank*avg);
		return ;	
	}
	if(s[x].distance+tank*avg>dis&&s[x].price<=minprice)
	{
//		cout<<" "<<"2"<<endl;
		cost+=((dis-s[x].distance)/avg-rest)*s[x].price;
		printf("%.02lf",cost);
		return ;
	}
	double oil=(s[index].distance-s[x].distance)/avg;
	if(s[x].price<minprice&&s[x].distance+tank*avg<dis)
	{
//		cout<<" "<<"3"<<endl;
		cost+=(tank-rest)*s[x].price;
		rest=tank-oil;
		DFS(index,cost,rest); 
		return ;
	}
	if(oil>rest)
	{
//		cout<<" "<<"4"<<endl;
		cost+=(oil-rest)*s[x].price;
		DFS(index,cost,0);
		}
	else
	{
//		cout<<" 5"<<endl;
		DFS(index,cost,rest-k);
}
}
int main(void)
{
	//input
	cin>>tank>>dis>>avg>>n;
	for(i=0;i<n;i++)
	{
		cin>>tmp.price>>tmp.distance;  
		s.push_back(tmp); 
	}
	
	//calulate
	sort(s.begin(),s.end(),compare);
	if(s[0].distance)
	{
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	DFS(0,0,0);
	
	return 0;
}

//rest变量很重要，用递归函数的方式比较方便。考虑的情况挺多的。 
