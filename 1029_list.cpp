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
			l.insert(it,t);//list里所谓的insert(it,i)操作，其实并不是把i值插入到地址it上，然后it及其以后元素后移。
		insert_pre=true;	
	}

	it=l.begin();
	n1=0;
	while(n1++<l.size()/2)
		it++; 
	cout<<*it;
	return 0;
} 

//不知道两个序列是否有相同数字。有的话，按集合还是按一般的容器呢？ 
//long long的scanf和printf 
//iterator属于指针，存储的是地址。地址没有谁大谁小，只能判断是否相等。（对于顺序存储来说是可以比较的，但对于链式存储则不行。）
//对于iterator类型只能++和--,不能+1或-1.他的遍历方式是判断it!=set.end(),原因是这些容器的有效存储范围是[容器.begin(),容器.end()-1] 
/*	
	例如：
	list<int> q;
	q.push_back(1);
	q.push_back(2);
	q.push_back(3);
	//下两行表明，容器的范围是 [容器.begin(),容器.end()-1] 而非[容器.begin(),容器.end()]，所以it!=容器.end()即可结束，不需要遍历这个end()元素。  
	list<int>::iterator it=q.end(); 
	cout<<*it<<" "<<*--it; //3 3
	//下面这段表明，list里所谓的insert(it,i)操作，其实并不是把i值插入到地址it上，然后it及其以后元素后移。也不是说，把i插入到it--的位置，然后it前面的元素全部前移。
	//而是说，插入的前后，it_pre和it所指的元素都不变，这个list里地址和元素的对应关系都没有改变。改变的只是地址的顺序而非对应关系。 
	//所谓地址顺序就是说，原本it--后，it==it_pre，现在it--后，it指向的是刚刚插入的元素，而不在于it_pre相等。 
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
