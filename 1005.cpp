#include<iostream>
#include<deque>
#include<string.h>
using namespace std;

int main(void){
	char line[102];
//	char* line;//error char*���ܱ�scanf����Ϊ����ָ����ָ��ַ��δ�����٣����ܴ�Ŷ����� 
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
int��.214*10^10��21.4�ڡ�long long ��20λ����10^100��100λ�����Բ�����long longȥscanf��
���ڳ���������Ӧ�����ַ���ȥscanf 

char*���ܱ�scanf����Ϊ����ָ����ָ��ַ��δ�����٣����ܴ�Ŷ�����

for(i=0;line[i];i++){
		sum+=line[i]-'0';
}
����ֵ��ѧϰ��1��forѭ�������ַ�����'\0'==false��2�������ַ�-�ַ�0==val(�����ַ�)
��һ�ֱ����ַ���ʽ��char *s=line; while(*s!='\0'){ ������s++;} 

������ת���ַ�\b��ɾ��ĩβ�Ŀո�\b����delete���京���ǽ�������һ����insert����ʽ���롣��������룬���˵��Ǹ����ݲ��ᱻ���ǡ����ԣ�������\b��ɾ��ĩβ�ո� 

	int flag = 0;  
	while (!p.empty())  
	{  
		if (flag) cout << " "; else flag = 1;  
		cout << ss[p.top()];  p.pop();  
	}  
��һ��ĩβ�����ո�ķ�����flag��ʼΪ0������ӡspace����flagΪ1��֮��flagΪ1��ÿ�δ�ӡspace��
�������ж��Ƿ�Ϊ���һ�����룬����ǣ�����ӡ����+space����ֻ��ӡ���֡��Ա������������������ҵķ���ͨ���Ը��á� 
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
����char*�����ܷ�scanf 
	char* m;
	char s[10];
//	m=s;
	scanf("%s",m); 
*/
