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
//			//���������ȣ����������������ӡ���Ҫ����ݹ麯������ͣ�ݹ���ȥ��
//			//���compareֻ����һ���ӿں�����Ȼ���ڸ��ִ���ָ�룬�ַ�����һ����������һ���º������ݹ��������ַ�����ָ�벻ͣ������ȥ�� 
//			//������������������ȫģ��string�ıȴ�С�ˡ� 
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
	if(!is_zero)//�����������ȫΪ0���Ǿ����һ��0.����û�ˡ� 
		cout<<'0';	
	return 0;
} 

//���compare������·����Ȼ�����뵽�ˡ������ģ��������̣�������compare���ӿڣ�����һ���ݹ麯���ݹ�֮��
//����һ�����ִ�������ע��㣺 
//һ��ע����ǣ�head��0���������������������ַ���ȫΪ0���¸��ַ�����ͷ��Ϊ0.
//��һ��ע�����������һ��0����ô��Ҫ���һ��0�ġ�
//����������ִ��ķ�Χ�� 
 
 
