#include<iostream>
using namespace std;

int n;
int l[1010],r[1010];
int i,j,k;
bool is_m;
void BST(int b, int e,int m)
{
	r[m]=l[b];
	if(b==e)
		return ; 
	int x,y;
	if(!is_m)
	{
		for(x=b+1;l[b]>l[x]&&x<=e;x++);
		for(j=x+1;l[b]>l[j]&&j<=e;j++)
			if(j!=e)	return ;
		if(l[b]>l[b+1]){
			BST(b+1,x-1,m-e+x-2);
		}
		if(l[b]<=l[e]) 
			BST(x,e,m-1);
	}
	else
	{
		for(x=b+1;l[b]<=l[x]&&x<=e;x++);
		for(j=x+1;l[b]<=l[j]&&j<=e;j++)
			if(j!=e)	return ;
		if(l[b]<=l[b+1]){
			BST(b+1,x-1,m-e+x-2);
		}
		if(l[b]>l[e]) 
			BST(x,e,m-1);
	}	
}
	
int main(void)
{
	cin>>n;
	for(i=0;i<n;i++)
		cin>>l[i];
	if(l[0]<=l[1])
		is_m=true;
//	if(is_m)
//		for(i=0;i<n;i++)
//			l[i]=-l[i];
//û�ã����ڵ����������ˣ����ǱȽϴ�С��ʱ���ж�is_m�ɡ�
	for(i=0;i<n;i++)
		r[i]=(1<<31)-1;
	BST(0,n-1,n-1);
	for(i=0;i<n;i++)
		if(r[i]==(1<<31)-1)
			break;
	if(i!=n)
	{
		cout<<"NO";
	}
	else
	{
		cout<<"YES"<<endl;
		for(i=0;i<n;i++)
		{
			if(i!=0)	cout<<" ";
			cout<<r[i];
		}
	}			
	return 0;
}

//�϶�����һ���ݹ麯������¼preorder��˳��Ȼ��ͷβ���ݹ麯����
//vc++6.0���ܶ���䳤���顣
