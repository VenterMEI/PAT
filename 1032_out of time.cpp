#include<iostream>
#include<string>
using namespace std;

int nextgjz[100010],s1,s2,n;//next�ǹؼ��� 
//char s[100010];//һ��ʼ���ÿ����ַ�������ַ�һ�������ȥ���������ֲ��ã���һ�����ȥ�˵�������Ŀ�ò������ڶ���scanf���а�ȫ������ģ���%cҲ���س�����bug�ˡ�
char s[2];//����İ취���ǵ��ַ��������� 
int i,j;
 
int main(void)
{
	//input
	cin>>s1>>s2>>n;
//����Ϊɶscanf���Ƕ����� 
/* 
	while(n--)
	{
		//cin>>i>>s[i]>>j;//������������ֵ��������һ�������У�ͬʱ����ʹ�á�	
		//scanf("%d %c %d\n",&i,&s[i],&j); 
//		cin>>i;
		scanf("%d",&i); 
//		cin>>s[i]>>j;
		scanf("%s",&s);
		scanf("%d",&j);
//		cout<<"i:"<<i<<" j:"<<j<<" s[i]"<<s[i]<<endl;
		nextgjz[i]=j;	
	}	
*/
	while(n--)
	{
		scanf("%d%s%d",&i,s,&j); 
		nextgjz[i]=j;
	}
	 
	//find
	bool is_found=false;
	while(s1!=-1)
	{
		n=s2;
		while(n!=-1)
		{
			
			if(s1==n)
			{
				is_found=true;
				break;
			}
			n=nextgjz[n];
//			cout<<s[s1]<<" "<<s[s2]<<endl;
		} 
		if(is_found)
			break;
		s1=nextgjz[s1]; 
//		cout<<s1<<endl;	
	}
	
	//output
	if(is_found)
//		cout<<s1<<endl;//���գ�������λ���ֵ�idһ��Ҫע��%0nd��
		printf("%05d\n",s1); 
	else
		cout<<"-1"<<endl;	
	return 0;
}
 
 
//��λdigit��int�洢���У���Ϊ������00002��002�����𡣶���һһ��Ӧ�ġ� 
//next�ǹؼ��֣�������Ҫʹ��һЩ����Ӣ�ĵ��ʣ����ܱ�����ͨ���˵�ojͨ�����ˡ� 
//������һ�������У�ͬʱ����ʹ��һ��������
//�������idһ��Ҫ����Ҫ��Ҫ��0��������Ϊ����۷ְ��� 
//scanf�ǲ���ȫ�ģ���%c���س�Ҳ�������԰��ַ����ַ��������� 
//100000*100000��100�ڴ������ˣ�cin��scanf��Ȼ��oj���в�࣬��ʮ���ģ�Ļ�ûʲôӰ�졣 
