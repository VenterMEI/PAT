#include<iostream>
#include<string>
using namespace std;

struct no{
	string id;
	int t1[3];
	int	t2[3];
};
no l[10000];
int n,i,j,k;
int cl,op;
int main()
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>l[i].id;
		scanf("%d:%d:%d %d:%d:%d",&l[i].t1[0],&l[i].t1[1],&l[i].t1[2],&l[i].t2[0],&l[i].t2[1],&l[i].t2[2]);
		if(!i)
		{	cl=0;op=0;}
		if(l[cl].t2[0]<l[i].t2[0]||(l[cl].t2[0]==l[i].t2[0]&&l[cl].t2[1]<l[i].t2[1])||(l[cl].t2[0]==l[i].t2[0]&&l[cl].t2[1]==l[i].t2[1]&&l[cl].t2[2]<l[i].t2[2]))
			cl=i;
		if(l[op].t1[0]>l[i].t1[0]||(l[op].t1[0]==l[i].t1[0]&&l[op].t1[1]>l[i].t1[1])||(l[op].t1[0]==l[i].t1[0]&&l[op].t1[1]==l[i].t1[1]&&l[op].t1[2]>l[i].t1[2]))
			op=i;
	}
	cout<<l[op].id<<" "<<l[cl].id;
	return 0;
}

//这题由于不用打印时间，其实不用记录hh:mm:ss,直接保存总时间即可。复习时算一遍当练笔吧。