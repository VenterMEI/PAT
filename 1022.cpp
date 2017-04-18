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
		scanf("%d\n",&tmp.id);//这里必须打个\n把回车吃掉，不然下个gets只能读一个回车 
		gets(tmp.title);
		gets(tmp.author);
		//将带空格的字符串句子split为无空格的字符串 
//		gets(str);
//		int p=0;
//		char * reslut=strtok(str," ");//strtok(str1,str2);在str1中遇到str2，就将str2的部分改为'\0'，把那个字符串作为返回值。 
//		while(result)
//		{
//			strcpy(tmp.keywords[p++],result);
//			result=strtok(NULL," ");//第二次调用strtok，将str1改为NULL，他就自动从上次结束的地方继续读。	
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
					printf("%07d\n",dl[i].id);//id是7位数字，  %07d	
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

//gets()函数，读取字符串以回车结束，并丢弃换行符并在字符末位添"\0"。
	//char str[6];//注意不能是char *str，那样str没有指向有效的内存空间，这种操作是非法的。 
	//gets(str); 
//strstr(str1,str2);判断str2是否是str1的子串，如果是，返回首次出现地址。如果不是，返回NULL; 
//id是7位数字，%07d，切记切记。
//其实可以将book改成一个6列的字符串数组，可以省略switch-case 
//将带空格字符串分割,第一次调用strtok(str1,str2);之后调用strtok(NULL,str2); 
 
