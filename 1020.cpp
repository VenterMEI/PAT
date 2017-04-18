#include<iostream>
#include<deque>
using namespace std;

int	num,post[30],in[30]; 
int i,j,root;
bool flag=false;
deque<int> l;

int level(int start,int end)
{

	l.push_back(start);
	l.push_back(end); 
	while(l.size())
	{	
		start=l[0];
		end=l[1];
		l.pop_front();
		l.pop_front(); 
		if(start<=end){//
			int last=0;
			for(i=start;i<=end;i++)
				for(j=0;j<num;j++)
				{
					if(in[i]==post[j])
					{
						if(last<=j)//������<=����Ϊ�����j����0�Ļ���root����˶��������á� 
						{
							root=i;
							last=j;
						}
						break;			
					}		
				}			
			if(flag)
				printf(" ");
			else
				flag=true;	
			printf("%d",in[root]);
			if(start!=end)
			{
				l.push_back(start); 
				l.push_back(root-1);
				l.push_back(root+1);
				l.push_back(end);
			}
		}
	}
}

int main(void)
{	 
	cin>>num;
	for(i=0;i<num;i++)
		cin>>post[i];
	for(i=0;i<num;i++)
	 	cin>>in[i];
	level(0,num-1);
	return 0;	
} 

//levelorder�϶���Ҫ�ö����ˡ�˼·���ǣ�ÿ�ΰ�inorder��start��end�ɶԼ�����У��ɶԵ�����
//�����Χ�������post��index���ģ�last������root��Ȼ��root����������������С� 
//inorder ���� preorder ���� postorder ����
//<=�Ǹ�bug��ʵͦ����ģ�Ҫ��ע�⡣ 
//num==1������������ر���
