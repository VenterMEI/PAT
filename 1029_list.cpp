#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int n1,n2;
list<long int> l;
long int t;
int now=0; 
bool insert_pre=true;
int main(void)
{
	cin>>n1;
	while(n1--)
	{
		scanf("%d",&t);
		l.push_back(t); 
	}
	cin>>n2;
	list<long int>::iterator it=l.begin();
	while(n2--)
	{
		scanf("%d",&t);
		while(*it<t)
		{
			if(it==l.end())
			{
				l.push_back(t);
				insert_pre=false; 
			}
			else
				it++;		
		}
		if(insert_pre)
			l.insert(it,t);//list����ν��insert(it,i)��������ʵ�����ǰ�iֵ���뵽��ַit�ϣ�Ȼ��it�����Ժ�Ԫ�غ��ơ�
		insert_pre=true;	
	}

	it=l.begin();
	n1=0;
	while(n1++<l.size()/2)
		it++; 
	cout<<*it;
	return 0;
} 

//��֪�����������Ƿ�����ͬ���֡��еĻ��������ϻ��ǰ�һ��������أ� 
//long long��scanf��printf 
//iterator����ָ�룬�洢���ǵ�ַ����ַû��˭��˭С��ֻ���ж��Ƿ���ȡ�������˳��洢��˵�ǿ��ԱȽϵģ���������ʽ�洢���С���
//����iterator����ֻ��++��--,����+1��-1.���ı�����ʽ���ж�it!=set.end(),ԭ������Щ��������Ч�洢��Χ��[����.begin(),����.end()-1] 
/*	
	���磺
	list<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	//�����б����������ķ�Χ�� [����.begin(),����.end()-1] ����[����.begin(),����.end()]������it!=����.end()���ɽ���������Ҫ�������end()Ԫ�ء�  
	list<int>::iterator it=q.end(); 
	cout<<*it<<" "<<*--it; //3 3
	//������α�����list����ν��insert(it,i)��������ʵ�����ǰ�iֵ���뵽��ַit�ϣ�Ȼ��it�����Ժ�Ԫ�غ��ơ�Ҳ����˵����i���뵽it--��λ�ã�Ȼ��itǰ���Ԫ��ȫ��ǰ�ơ�
	//����˵�������ǰ��it_pre��it��ָ��Ԫ�ض����䣬���list���ַ��Ԫ�صĶ�Ӧ��ϵ��û�иı䡣�ı��ֻ�ǵ�ַ��˳����Ƕ�Ӧ��ϵ�� 
	//��ν��ַ˳�����˵��ԭ��it--��it==it_pre������it--��itָ����Ǹող����Ԫ�أ���������it_pre��ȡ� 
	list<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	list<int>::iterator it=q.end();
	cout<<*it<<" "<<*--it; //3 3 
	list<int>::iterator it2=q.begin(),it1;
	it1=it2++;
	cout<<"before insert it1:"<<*it1<<endl;//1
	q.insert(it2,0);
	cout<<"after insert it1:"<<*it1<<endl;//1
	cout<<"--it2:"<<*--it2;//0
*/
