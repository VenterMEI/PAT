#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;

struct stu
{
	string name;
	deque<int> course;
	bool operator ==(string s)//���ص�������Ⱥ�˳��Ҳ���ܴ�Ҫ��stu==string��д��string==stu�Ͳ����ԡ� 
	{
		return name==s;	
	}		
}; 
deque<stu> list;
int m,n,index,cnt;
int i,j;
string tmpname;
bool is_found;

int main(void)
{
	cin>>n>>m;
	while(m--)
	{
		cin>>index>>cnt;
		for(i=0;i<cnt;i++)
		{
			cin>>tmpname;
			is_found=false;
			for(j=0;j<list.size();j++)
			{
				if(list[j]==tmpname)
				{
					is_found=true;
					list[j].course.push_back(index);
					break;
				}
			}
			if(!is_found)
			{
				stu tmp;
				tmp.name=tmpname;
				tmp.course.push_back(index);
				list.push_back(tmp);	   	
			} 
		}
	}
	while(n--)
	{
		cin>>tmpname;
		is_found=false;
		for(i=0;i<list.size();i++)
		{
			if(list[i]==tmpname)
			{
				is_found=true;
				cout<<tmpname<<" "<<list[i].course.size();
				sort(list[i].course.begin(),list[i].course.end());
				for(j=0;j<list[i].course.size();j++)
				{
					cout<<" "<<list[i].course[j];	
				}
				list.erase(list.begin()+i);
				break; 
			}
		}
		if(!is_found)//��������û��ѡ�Σ���ôcourse�ﲻ������������֣���ôlist�Ͳ�����¼���� 
		{
			cout<<tmpname<<" 0";
		}
		cout<<endl;
	}
	return 0;
}

//����ѭ�������Ӷȹ��ߣ���һ�����Ե����г�ʱ�� 
//��ʵ��Ź���һ���ǿ���Ԥ���ģ�4ǧ*4��*4�򣬲���ʱ�й��� 
