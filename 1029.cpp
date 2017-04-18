#include<iostream>
#include<algorithm>
using namespace std;

int n1,n2,m,p=0,i,p1=0,p2=0;
long l[1000000],b,now;
bool flag=true;
 
int main(void)
{
	cin>>n1;
	for(i=0;i<n1;i++)
	{
		scanf("%lld",&l[i]);
	}
	cin>>n2;
	m=(n1+n2+1)/2;//注意要+1。分奇奇，偶偶，奇偶三种情况。如果这次用的是merge的话，就是括号内-1了。
	i=0;
	scanf("%lld",&b);
	while(i++!=m)
	{
		if(p1!=n1&&(p2==n2||l[p1]<b))
		{
			now=l[p1++];	
		}	
		else
		{
			now=b;
			scanf("%lld",&b);
			p2++;
		}
	}
	cout<<now;
/*	
	//先让l[p]成为最小值，防止middle比l[0]小。 
	while(true)	
	{
		scanf("%d",&b); 
		i++;
		if(l[p]<b)
		{
			flag=false;//如果读的数比l[p]大，进入下一个循环就不读了。 
			break;
		}
		if(i==m) 
		{
			swap(l[p],b);
			break;	
		}
		if(i-p==n2)//如果第二行被读光了。能判断到这步说明l[p]>b，且i!=m。 
		{
			i++;
			break;	
		} 
	}
	printf("%d %d %d\n",l[p],i,b); 
	while(true)
	{
		if(i==m)
			break;
		if(l[p]<b)
		{
			if(p<n1-1&&l[p+1]<b)
			{
				while(l[p+1]<b)
				{
					p++;
					i++;
					printf("::::%d %d %d\n",l[p],i,b);
					if(i==m)
						break;
					if(p==n1-1)
						break;		
				}
				if(p!=n1&&i!=m)
				{
					i++;						
				}
			}			
		}
		else
			i++;
		if(p==n1-1&&l[p]<b)
			break;
		if(i-p!=n2+1)	
			if(flag)		
				scanf("%d",&b);
			else 
				flag=true;
		else
			break;		
		if(i-p==n2&&l[p]>b)
			break;	

		printf("%d %d\n",l[p],i); 
	} 
	while(i!=m)
	{
		if(p!=n1-1)
		{
			p++;
		}
		else
		{
			scanf("%d",&b);
			l[p]=b;
		}
		i++;
	}
	cout<<l[p];
*/
	return 0;
	
}

//STL成瘾患者 
 

//		if(pa!=n1&&(pb==n2||a[pa]<b[pb]))
//			now=a[pa++];
//		else
//			now=b[pb++];
//浅蓝的这个方法逼格很高。pb==n2表示pb已经走完了，而且落在now之后。或者a[pa]<b[pb]。只有这两种情况下是更新a。
//这里可以借鉴一下，引入now，去掉第一段while(true)的判断，然后用pa==n1去判断而不是pa==n1-1&&a[pa]<b[pb]这种方式，情况太复杂了。 
