#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
	int key;
	int l;
	int r;
	int level;
};
node n[1010];
int k,i,j,p,t,ml=1;

int main(void)
{
	cin>>k;
	n[1].level=1;
	for(i=1;i<=k;i++)
	{
		cin>>n[i].key;
		if(i!=1)
		{
			j=1;
			while(true)
				if(n[i].key<=n[j].key)
				{
					p=j,j=n[j].l;
					if(!j)
					{
						n[p].l=i , n[i].level=n[p].level+1 , ml=max(ml,n[p].level+1);
						break;
					}
				}
				else
				{
					p=j,j=n[j].r;
					if(!j)
					{
						n[p].r=i , n[i].level=n[p].level+1 , ml=max(ml,n[p].level+1);
						break;
					}
				}
		}
	}

	int x=0 ,y=0;
	for(i=1;i<=k;i++)
		if(n[i].level==ml)
			x++;
		else if(n[i].level+1==ml)
			y++;
	cout<<x<<" + "<<y<<" = "<<x+y;

	return 0;
}

//vc++6.0����ʹ�ÿ⺯�����max������swap��sort�����á�
//�и�1�ֲ��Ե�ֻ��һ�����ڵ㣬����Ҫ�ȳ�ʼml(maxlevel)Ϊ1. 
