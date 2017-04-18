#include<iostream>
#include<deque>
using namespace std;

char s[20];
int n,i,j;
int num;
deque<int> s3; 
bool is_d;
char s2[13][5]={"tret","tam", "hel", "maa", "huh", "tou","kes", "hei", "elo", "syy", "lok", "mer", "jou"};
char s1[13][5]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
int main(void)
{
	cin>>n;
	getchar();
	while(n--)
	{
		num=0;
		gets(s);
		if(s[0]>='0'&&s[0]<='9')
		{
			for(i=0;s[i];i++)
			{
				num=num*10+s[i]-'0';
			}
			if(num==0)
			{	
				cout<<"tret"<<endl;
			}else{
				while(num)
				{
					s3.push_back(num%13);
					num/=13;
				}	
				for(i=s3.size()-1;i>0;i--)
				{
					cout<<s2[s3[i]]<<" ";	
				}
				if(s3[0])
					cout<<s1[s3[0]];
				cout<<endl;
				s3.clear();
			}
		}
		else
		{
			for(i=-1;i==-1||s[i];i=i+3)
			{
				if(i>2&&s[i]=='t')
				{	j=0;break;}
				i++;
				for(j=0;j<13;j++)
				{
					if(s[i]==s2[j][0]&&s[i+1]==s2[j][1]&&s[i+2]==s2[j][2])
					{	
						is_d=true;
						break;
					}
					if(s[i]==s1[j][0]&&s[i+1]==s1[j][1]&&s[i+2]==s1[j][2])
					{	
						is_d=false;
						break;
					}
					
				}
				num=num*13+j;
			}
			if(is_d)
				num*=13;
			cout<<num<<endl;
		}
	}
	return 0;
}

//getline
//盲目追求通用性，其实这题火星文最多就两位字符。特殊情况是难以预料的。
//对于int型输入。如果输入为0，就打印“tret”。num/13非0，打印s1[num/13]。在此前提下，如果num%13！=0，打印一个空格。如果num%13!=0，打印s1[num%13].
//对于火星文输入。tret只在int为0时出现，因为不存在170，写出tam tret jam的样子。如果输入为四位，打印tret。如果三位，找到i，判断i来自是s1还是s2，s2就*13.
//如果7位，那就是num=i*13，num+=i； 