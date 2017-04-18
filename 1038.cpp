#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;

deque<string> ls;
string t;
int n,i,j;
bool is_zero;
 
//bool compare1(string s1,string s2)
//{
//	int begin,end;
//	bool is_same=true,is_swap=false;
//	if(s1.length()!=s2.length())
//	{
//		if(s1.length()>s2.length())
//		{
//			swap(s1,s2);
//			is_swap=true;
//		}
//		for(end=0;end<s1.length();end++)
//		{
//			if(s1[end]!=s2[end])
//			{
//				is_same=flase;
//				break;
//			}
//		}
//		if(is_same)
//		{
//			for(begin=0;end<s2.length()&&begin<s1.length();end++,begin++)
//			{
//				if(s1[begin]!=s2[end])
//				{
//					if(is_swap)
//						return s1[begin]>s2[end];
//					else
//						return s1[begin]<s2[end];
//				}	
//			}
//			//如果还不相等，子子孙孙无穷匮矣。需要构造递归函数，不停递归下去。
//			//这个compare只能做一个接口函数，然后在各种传的指针，字符都做一个参数表构造一个新函数。递归中两个字符串的指针不停的走下去。 
//			//不过这样子做就是完全模拟string的比大小了。 
//			if(s1.length()*2<s2.length())
//			{
//				if(is_swap)
//					return s1[0]>s2[2*s1.length()-1];
//				else
//					return s1[0]<s2[2*s1.length()-1];	
//			}
//			else if(s1.length()*2>s2.length())
//			{
//				
//			}	 
//		}
//		else
//		{
//			if(is_swap)
//				swap(s1,s2);
//			return s1<s2;
//		}
//	}
//	else
//		return s1<s2; 	
//}

bool compare(string s1,string s2)
{
	string s3=s1+s2,s4=s2+s1;
	if(s3<s4) 
		return true;
	else
		return false;	
}

int main(void)
{
	cin>>n;
	while(n--)
	{
		cin>>t;
		ls.push_back(t); 
	}
	
	sort(ls.begin(),ls.end(),compare);
	for(i=0;i<ls.size();i++)
		for(j=0;j<ls[i].length();j++)
		{
			if(!is_zero)
			{
				if(ls[i][j]!='0')
				{
					is_zero=true;	
					cout<<ls[i][j];
				}
			}
			else
				cout<<ls[i][j];
		}
	if(!is_zero)//啊啊啊，如果全为0，那就输出一个0.两分没了。 
		cout<<'0';	
	return 0;
} 

//这个compare很有套路，居然被我想到了。如果想模拟这个过程，可以以compare做接口，另起一个递归函数递归之。
//对于一个数字串的两个注意点： 
//一个注意点是，head是0不输出，但有种情况是首字符串全为0，下个字符串开头仍为0.
//另一个注意点就是如果就一个0，那么是要输出一个0的。
//另外就是数字串的范围。 
 
 
