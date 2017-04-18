#include<iostream>
#include<deque>
#include<string>
using namespace std;

int n,cnt;
string name[1010],pass[1010];
int i,j;
bool is_changed,changed[1010];

int main(void)
{
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>name[i]>>pass[i];
	}
	
	for(i=0;i<n;i++)
	{
		is_changed=false;
		for(j=0;j<pass[i].size();j++)
		{
			switch(pass[i][j])
			{
				case '1':
					pass[i][j]='@';
					is_changed=true;
					break;
				case '0':
					pass[i][j]='%';
					is_changed=true;
					break;
				case 'l':
					pass[i][j]='L';
					is_changed=true;
					break;
				case 'O':
					pass[i][j]='o';
					is_changed=true;
					break;					
			} 
		}
		if(is_changed)
		{
			cnt++;
			changed[i]=true;
		}
	}
	if(cnt)
	{
		cout<<cnt<<endl;
		for(i=0;i<n;i++)
		{
			if(changed[i])
				cout<<name[i]<<" "<<pass[i]<<endl;	
		} 
	} 
	else
	{
		if(n==1)
			cout<<"There is 1 account and no account is modified"<<endl;
		else 
			printf("There are %d accounts and no account is modified\n",n);//是are不是is，,accounts不是account，orz 
	}
	return 0;
}
