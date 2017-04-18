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

//column ���� rows���� 
//��oj�Ͼ���ʹ��printf��scanf����I/O����Ϊcin �� cout��oj�Ϻ�ʱ�ϳ��������ǽ��д��ģ���������ʱ�򡣿�������Ϊ��Ҫ����printf��scanf������ͬ������������⡣
//������������ģΪһ���򣬾����Գ�ʱ�ˡ� 
//��ϧ����printf��scanf�޷�����string���͵����ݡ� 
 
