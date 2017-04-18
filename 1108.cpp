#include<iostream> 
#include<deque>
#include<string>
using namespace std;

string s;
int n,i,cnt;
double value,sum;
bool is_legal(string str)
{
	bool dian=false;
	int liangwei;
	value=0;
	if(str[0]=='-')
	{
		i=1;
	}
	else
		i=0;
	for(;i<str.length();i++)
	{
		if(str[i]=='.')
		{
			if(!dian)
			{
				dian=true;
				liangwei=0;
			}
			else
				return false;	
		}
		if(dian&&liangwei==3)
			return false;
		if((str[i]>='0'&&str[i]<='9')||str[i]=='.')
			liangwei++;
		else
			return false;			
	}
	if(str[0]=='-')
	{
		i=1;
	}
	else
		i=0;
	for(;i<str.length();i++)
	{
		if(s[i]=='.')
			break;
		value=value*10+s[i]-'0';			
	}	
	for(i++,liangwei=0;i<str.length()&&liangwei<2;i++,liangwei++)
	{
		if(liangwei==0)
			value+=(s[i]-'0')*0.1;
		else	
			value+=(s[i]-'0')*0.01;	
	}	
	if(value>1000.001)
		return false;
	if(s[0]=='-')
		value=-value;
	return true;			
}
int main(void)
{
	cin>>n;
	while(n--)
	{
		cin>>s;
		if(is_legal(s))
		{
			cnt++;
			sum+=value;
		}
		else
		{
			cout<<"ERROR: "<<s<<" is not a legal number"<<endl; 	
		}
	}
	if(cnt==0)
		printf("The average of %d numbers is Undefined",cnt);
	if(cnt==1)	
		printf("The average of %d number is %.02lf",cnt,sum/cnt);
	if(cnt>1)
		printf("The average of %d numbers is %.02lf",cnt,sum/cnt);
	return 0;
}
