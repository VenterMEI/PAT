#include<iostream>
#include<string>
using namespace std;

int nextgjz[100010],record[100010],s1,s2,n;//next�ǹؼ��� 
char s[2];
int i,j;
bool is_found;
 
int main(void)
{
	//input
	cin>>s1>>s2>>n;
	while(n--)
	{
		scanf("%d%s%d",&i,s,&j); 
		nextgjz[i]=j;
	}
	 
	//bucket
	while(s1!=-1) 
	{
		record[s1]=true;
		s1=nextgjz[s1];
	}
	while(s2!=-1)
	{
		if(record[s2])
		{
			is_found=true;
			break;
		}
		s2=nextgjz[s2];
	}
	//output
	if(is_found)//����ڱ��ǲ����ٵġ���Ϊ�ҵõ�Ҫ�����λ���֣��Ҳ���ҪֻҪ���1λ�� 
//		cout<<s1<<endl;//���գ�������λ���ֵ�idһ��Ҫע��%0nd��
		printf("%05d\n",s2); 
	else
		cout<<"-1"<<endl;	
	return 0;
}
 
 
//��bucket��o(n)���Ӷȵģ��ö���ѭ����o(n^2)���Ӷȵ� 
//scanf�ǲ���ȫ�ģ���%c���س�Ҳ�������԰��ַ����ַ��������� 
//100000*100000��100�ڴ������ˣ�cin��scanf��Ȼ��oj���в�࣬��ʮ���ģ�Ļ�ûʲôӰ�졣 
