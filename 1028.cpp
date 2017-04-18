#include<iostream>
#include<deque>
#include<string.h>
#include<algorithm>
using namespace std;

struct stu
{
	int id;//%06d
	char name[9];
	int grade;
};

bool by_id(stu s1,stu s2)
{
	return s1.id>s2.id;
}
bool by_name(stu s1,stu s2)
{
	if(strcmp(s1.name,s2.name))
		if(strcmp(s1.name,s2.name)<0)
			return false;
		else 
			return true;	
	else
		return s1.id>s2.id;  
}
bool by_grade(stu s1,stu s2)
{
	if(s1.grade!=s2.grade)
		return s1.grade>s2.grade;
	else
		return s1.id>s2.id;  
}
int n,m;
deque<stu> record;

int main(void)
{
	cin>>n>>m;
	while(n--)
	{
		stu tmp;
		scanf("%d %s %d",&tmp.id,tmp.name,&tmp.grade);
		record.push_back(tmp);  
	}
	switch(m)
	{
		case 1:
			sort(record.begin(),record.end(),by_id);
			break; 
		case 2:
			sort(record.begin(),record.end(),by_name);
			break;
		case 3:
			sort(record.begin(),record.end(),by_grade);
			break;
	}
	while(record.size())
	{
		printf("%06d %s %d\n",record[record.size()-1].id,record[record.size()-1].name,record[record.size()-1].grade);
		record.pop_back();
	}
	return 0;
}

//column 纵列 rows横行 
//在oj上尽量使用printf和scanf进行I/O。因为cin 和 cout在oj上耗时较长，尤其是进行大规模输入输出的时候。可能是因为他要兼容printf和scanf，保持同步而引起的问题。
//这次输入输出规模为一百万，就足以超时了。 
//可惜的是printf和scanf无法处理string类型的数据。 
 
