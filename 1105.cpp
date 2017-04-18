#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int m,n,i,j,k,c,dis=1<<30;
vector<int>	l;
int flag;//0,r 1,d 2,r 3,u

int main(void)
{
	cin>>c;
	for(m=1;m<=c/m;m++)
	{
		n=c/m;
		
		if(m*n==c&&n-m<dis)
			i=m,j=n,dis=n-m;
	}
	m=j,n=i;
	for(i=0;i<c;i++)
	{
		scanf("%d",&j);
		l.push_back(j); 
	}
	int mar[m][n];
	for(i=0;i<m;i++)
		for(j=0;j<n;j++)
			mar[i][j]=10010;
	sort(l.begin(),l.end());
	i=0,j=0;//hang lei
	for(k=c-1;k>=0;k--)
	{
		mar[i][j]=l[k];
		if(flag==0)
			j++;
		if(flag==1)
			i++;
		if(flag==2)
			j--;
		if(flag==3)
			i--;
		if(flag==0&&(mar[i][j+1]!=10010||j+1==n))//下面这四个判断可以收到各自i或j++的里面 
			flag++;
		if(flag==1&&(mar[i+1][j]!=10010||i+1==m))
			flag++;
		if(flag==2&&(mar[i][j-1]!=10010||j-1==-1))
			flag++;
		if(flag==3&&(mar[i-1][j]!=10010||i+1==-1))
			flag=0;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j!=0) printf(" ");
			printf("%d",mar[i][j]);
		}
		cout<<endl;
	}
	return 0;
}