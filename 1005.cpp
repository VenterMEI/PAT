#include<iostream>
#include<deque>
#include<string.h>
using namespace std;

int main(void){
	char line[102];
//	char* line;//error char*不能被scanf。因为它的指针所指地址还未被开辟，不能存放东西。 
	scanf("%s",line);
	if(!strcmp(line,"0")){
		printf("%s", "zero");
		return 0;
	}
	int sum=0,i;
	for(i=0;line[i];i++){
		sum+=line[i]-'0';
	}
	char match[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	deque<int> sd;
	while(sum!=0){
		sd.push_back(sum%10);
		sum/=10; 
	} 
	while(sd.size()!=1){
		printf("%s ",match[sd.back()]);
		sd.pop_back(); 		
	} 
	printf("%s",match[sd.back()]);
//	printf("\b"); 
	return 0;
} 
/*
int是.214*10^10，21.4亿。long long 是20位。而10^100有100位，所以不能用long long去scanf。
对于长的整数，应该用字符串去scanf 

char*不能被scanf。因为它的指针所指地址还未被开辟，不能存放东西。

for(i=0;line[i];i++){
		sum+=line[i]-'0';
}
两点值得学习：1，for循环遍历字符串，'\0'==false。2，数字字符-字符0==val(数字字符)
另一种遍历字符方式：char *s=line; while(*s!='\0'){ ……；s++;} 

不能用转义字符\b来删除末尾的空格，\b不是delete，其含义是将光标回退一格，以insert的形式输入。如果不输入，回退的那个内容不会被覆盖。所以，不能用\b来删除末尾空格。 

	int flag = 0;  
	while (!p.empty())  
	{  
		if (flag) cout << " "; else flag = 1;  
		cout << ss[p.top()];  p.pop();  
	}  
另一种末尾不留空格的方法，flag初始为0，不打印space而置flag为1。之后flag为1后，每次打印space。
而我是判断是否为最后一次输入，如果是，不打印数字+space，而只打印数字。对比来看，上述方法比我的方法通用性更好。 
*/
	
/* 
int main(void){
	long long l;
	scanf("%d",&l);
	int sum; 
	deque<int> sd;
	while(l!=0){
		sum+=l%10;
		l/=10;
	}
	while(sum!=0){
		sd.push_back(sum%10);
		sum/=10; 
	} 
	char match[10][6]={"zero","one","two","three","four","five","six","seven","eight","nine"};
	while(!sd.empty()){
		printf("%s ",match[sd.back()]);
		sd.pop_back(); 		
	} 
	printf("\b"); 
	return 0;
} 
*/

/*
关于char*类型能否被scanf 
	char* m;
	char s[10];
//	m=s;
	scanf("%s",m); 
*/
