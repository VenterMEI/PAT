#include<iostream>
#include<deque>
using namespace std;

int n,b;
deque<int> nb;
bool flag=true;

int main(void)
{
	cin>>n>>b;	
	if(n==0){
		printf("Yes\n0");
		return 0;
	}
	while(n!=0)
	{
		nb.push_front(n%b);
		n/=b;
	} 
	for(int i=0;i<nb.size()/2;i++)
	{
		if(nb[i]!=nb[nb.size()-i-1])
		{
			flag=false;
			break;
		}
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	flag=false;
	while(nb.size())
	{
		if(flag)
			cout<<" ";
		else
			flag=true;
		cout<<nb[0];
		nb.pop_front(); 	
	}
	return 0;
}

//ע���������������nΪ0.��������㣬��ר���жϣ���nb��û�ж�����ֵ���yes�������0. 
