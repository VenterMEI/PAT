#include<iostream>
using namespace std;

int value_of_char(char * p){
	char c=*p;
	int value;
	if(c-60<0){
		value=c-'0';
	}else{
		value=c-'a'+10;
	}
	return value;
}

int getRadix(char * s1,char * s2,unsigned long long radix){
	unsigned long long value2=0,value1=0,left=0,right,mid;	
	while(*s2!='\0'){
		value2=value2*radix+value_of_char(s2++);
	}
	char * p=s1;
	while(*p!='\0'){
		if(left<value_of_char(p)){
			left=value_of_char(p);
		}
		p++;
	} 	
	left++;//����Ҫ+1����Ϊradix�϶��������ִ�����һ���ֵĴ�С�� 
	right=value2+1;//����ҲҪ+1�� �����ױ����ԡ�������ͬ�ϵġ�Ʃ��value2=10��N1=a����ôa��radix��right��10�ʹ��ˣ�left>right(11>10)������whileѭ���������impossible�� 
	while(left<=right){//������������<=������С�ڡ�<�Ļ�mid���ֻ���ٲ���һ��left����Ϊ����/2ȥβ�ġ�right��radix�Ŀ����Ի�û�в��ԡ� 
		mid=(right+left)/2;
		p=s1;
		value1=0;
		while(*p!='\0'){
			value1=value1*mid+value_of_char(p++);
		}
		if(value1==value2){
			printf("%d",mid);
			return 0;
		}
		if(value1<value2){
			left=mid+1;
		}else{
			right=mid-1;
		}
	}
	printf("Impossible"); 
	return 0;
}

int main(void){
	char  N1[12],N2[12];
	int tag;
	unsigned long long radix;
	scanf("%s%s%ld%ld",N1,N2,&tag,&radix);
	if(tag==1){
		getRadix(N2,N1,radix);
	}else{
		getRadix(N1,N2,radix);
	}
	return 0;
} 

//a decimal number һ��ʮ������   a binary number  һ����������
//�����ַ�������ѧϰһ�¡�
//for(i=0;str[k];i++){����}
//���ֲ��ҵ�right��left��ϸ�ڴ���Ҳֵ��ע�⡣ 
//radixȷʵ������һ���ܴ�����������ô�left��right���������ķ�ʽ����һ�����Ե���ʾ���㳬ʱ��
//����Ŀ����һ������ģ���ǿ�����ж��ֿ���ʱȡradix��С���Ǹ��������ֲ���Ӧ�����м���Ǹ�radix�����������������Ե���ʵ�Ǵ���Ĳ��Ե㣬���������Ե����Զ��ֲ��ҵ�radix���𰸶�������Сradix��  
