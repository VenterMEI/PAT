#include<iostream>
#include<algorithm>
#include<deque>
#include<string>
using namespace std;

struct stu
{
	string name;
	deque<int> course;
	bool operator ==(string s)//重载的运算符先后顺序也不能错。要是stu==string。写成string==stu就不可以。 
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
		if(!is_found)//如果这个人没有选课，那么course里不会出现他的名字，那么list就不会收录他。 
		{
			cout<<tmpname<<" 0";
		}
		cout<<endl;
	}
	return 0;
}

//三重循环，复杂度过高，有一个测试点运行超时。 
//其实大概估算一下是可以预见的，4千*4万*4万，不超时有鬼啊。 
