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
						if(last<=j)//这里是<=。因为，如果j就是0的话，root会因此而不能重置。 
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

//levelorder肯定是要用队列了。思路就是，每次把inorder的start和end成对加入队列，成对弹出。
//这个范围里的数在post里index最大的（last）就是root，然后将root的左右子树加入队列。 
//inorder 中序 preorder 先序 postorder 后序
//<=那个bug其实挺经典的，要多注意。 
//num==1的情况，不用特别处理
