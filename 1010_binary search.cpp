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
	left++;//这里要+1，因为radix肯定大于数字串中任一数字的大小。 
	right=value2+1;//这里也要+1， 但容易被忽略。理由是同上的。譬如value2=10，N1=a。那么a的radix的right是10就错了，left>right(11>10)不进入while循环，结果是impossible。 
	while(left<=right){//结束的条件是<=而不是小于。<的话mid最后只能再测试一下left，以为奇数/2去尾的。right作radix的可行性还没有测试。 
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

//a decimal number 一个十进制数   a binary number  一个二进制数
//遍历字符串，再学习一下。
//for(i=0;str[k];i++){……}
//二分查找的right，left的细节此题也值得注意。 
//radix确实可能是一个很大的数，所以用从left到right暴力搜索的方式会有一个测试点显示运算超时。
//但题目是有一点问题的，它强调了有多种可能时取radix最小的那个。但二分查找应该是中间的那个radix。所以另外三个测试点其实是错误的测试点，那三个测试点是以二分查找的radix做答案而不是最小radix。  
