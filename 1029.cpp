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
	m=(n1+n2+1)/2;//ע��Ҫ+1�������棬żż����ż����������������õ���merge�Ļ�������������-1�ˡ�
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
	//����l[p]��Ϊ��Сֵ����ֹmiddle��l[0]С�� 
	while(true)	
	{
		scanf("%d",&b); 
		i++;
		if(l[p]<b)
		{
			flag=false;//�����������l[p]�󣬽�����һ��ѭ���Ͳ����ˡ� 
			break;
		}
		if(i==m) 
		{
			swap(l[p],b);
			break;	
		}
		if(i-p==n2)//����ڶ��б������ˡ����жϵ��ⲽ˵��l[p]>b����i!=m�� 
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

//STL��񫻼�� 
 

//		if(pa!=n1&&(pb==n2||a[pa]<b[pb]))
//			now=a[pa++];
//		else
//			now=b[pb++];
//ǳ������������Ƹ�ܸߡ�pb==n2��ʾpb�Ѿ������ˣ���������now֮�󡣻���a[pa]<b[pb]��ֻ��������������Ǹ���a��
//������Խ��һ�£�����now��ȥ����һ��while(true)���жϣ�Ȼ����pa==n1ȥ�ж϶�����pa==n1-1&&a[pa]<b[pb]���ַ�ʽ�����̫�����ˡ� 
