#include<iostream>
#include<deque>
#include<algorithm>
#include<cstring>
using namespace std;

struct book
{
	int id;
	char title[81];
	char author[81];
//	char keywords[5][11];
	char keywords[161];
	char publisher[81];
	char year[5];
	bool operator<(book a)
	{
		return id<a.id;
	}
 };
 
 int N,M,i,j;
 book tmp;
 deque<book> dl;
 char str[81];
  	
int main(void)
{
	cin>>N;
	while(N--)
	{
		scanf("%d\n",&tmp.id);//���������\n�ѻس��Ե�����Ȼ�¸�getsֻ�ܶ�һ���س� 
		gets(tmp.title);
		gets(tmp.author);
		//�����ո���ַ�������splitΪ�޿ո���ַ��� 
//		gets(str);
//		int p=0;
//		char * reslut=strtok(str," ");//strtok(str1,str2);��str1������str2���ͽ�str2�Ĳ��ָ�Ϊ'\0'�����Ǹ��ַ�����Ϊ����ֵ�� 
//		while(result)
//		{
//			strcpy(tmp.keywords[p++],result);
//			result=strtok(NULL," ");//�ڶ��ε���strtok����str1��ΪNULL�������Զ����ϴν����ĵط���������	
//		}
//		while(p!=5)
//		{
//			strcpy(tmp.keywords[p++],"");
//		}
		gets(tmp.keywords);
		gets(tmp.publisher);
		gets(tmp.year);
		dl.push_back(tmp);
	}
	sort(dl.begin(),dl.end());
		
	scanf("%d\n",&M);
	while(M--)
	{	
		
		bool is_found=false;
		gets(str);
		puts(str);
		switch (str[0]-48)
		{
		case 1:
			for(i=0;i<dl.size();i++)
				if(!strcmp(dl[i].title,str+3))
				{
					printf("%07d\n",dl[i].id);//id��7λ���֣�  %07d	
					is_found=true;
				}
			break;
		case 2:
			for(i=0;i<dl.size();i++)
				if(!strcmp(dl[i].author,str+3))
				{
					printf("%07d\n",dl[i].id);		
					is_found=true;
				}
			break;
		case 3:
			for(i=0;i<dl.size();i++)
				if(strstr(dl[i].keywords,str+3))
				{
					printf("%07d\n",dl[i].id);		
					is_found=true;
				}
			break;
		case 4:
			for(i=0;i<dl.size();i++)
				if(!strcmp(dl[i].publisher,str+3))
				{
					printf("%07d\n",dl[i].id);		
					is_found=true;
				}
			break;
		case 5:
			for(i=0;i<dl.size();i++)
				if(!strcmp(dl[i].year,str+3))
				{
					printf("%07d\n",dl[i].id);		
					is_found=true;
				}
			break;									
		}
		if(!is_found)
			printf("Not Found\n"); 
	}

	return 0;
}

//gets()��������ȡ�ַ����Իس����������������з������ַ�ĩλ��"\0"��
	//char str[6];//ע�ⲻ����char *str������strû��ָ����Ч���ڴ�ռ䣬���ֲ����ǷǷ��ġ� 
	//gets(str); 
//strstr(str1,str2);�ж�str2�Ƿ���str1���Ӵ�������ǣ������״γ��ֵ�ַ��������ǣ�����NULL; 
//id��7λ���֣�%07d���м��мǡ�
//��ʵ���Խ�book�ĳ�һ��6�е��ַ������飬����ʡ��switch-case 
//�����ո��ַ����ָ�,��һ�ε���strtok(str1,str2);֮�����strtok(NULL,str2); 
 
