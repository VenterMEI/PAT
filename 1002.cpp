/*
1002. A+B for Polynomials (25)

时间限制
400 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. 
It is given that 1 <= K <= 10，0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/ 

//polynomia 多项式 
//exponent 指数
//coefficient	系数 
//1 decimal place	1位小数 

//题目的意思是说给你两行数，每行是一个多项式。第一个数字是k，代表有多少项。之后两两出现，分别是指数和系数。
//现在，要求你将两个多项式合并，将相同指数的合并到一起。 

/*
abs(x)：整数x的绝对值。
fabs(x)：浮点数（小数）x的绝对值。
pow(a, x)：a的x次方，a和x是浮点数，返回值是浮点数（即使a和x都是整数，也会被转换成浮点数，因此整数运算可能损失精度，造成误差）。
exp(x)：e的x次方，x是浮点数，e是自然对数的底数（一个无理数，值为2.71828....）
*/ 
#include<stdio.h>

typedef struct {
	int exp;
	double coe;//是double不是float。float不能用%lf去scanf,而要有%f.
}Term; 

int main(){
	//input
	int k1,k2,p1,p2,cnt;
	
	scanf("%d",&k1);
	Term t1[k1];
	for(p1=0;p1<k1;p1++){
		scanf("%d",&t1[p1].exp);
		scanf("%lf",&t1[p1].coe);
	}
	scanf("%d",&k2);
	Term t2[k2];
	for(p2=0;p2<k2;p2++){
		scanf("%d",&t2[p2].exp);
		scanf("%lf",&t2[p2].coe);
	}
	
	//calculate	
	cnt=p1=p2=0;
	Term t3[20];
	while(p1<k1&&p2<k2){
		if(t1[p1].exp<t2[p2].exp){
			t3[cnt++]=t2[p2++];
		}else if(t1[p1].exp>t2[p2].exp){
			t3[cnt++]=t1[p1++];
		}else{
			if(t1[p1].coe + t2[p2].coe>1e-6||t1[p1].coe + t2[p2].coe<-1e-6){//首先注意是绝对值<1e-6.其次，浮点的绝对值不是abs而是fbs。 
				t3[cnt].exp = t1[p1].exp;
				t3[cnt++].coe = t1[p1].coe + t2[p2].coe;
			}
			p1++;
			p2++;
		}
	}
	while(p1<k1){
		t3[cnt++]=t1[p1++];
	}
	while(p2<k2){
		t3[cnt++]=t2[p2++];
	}
	
	//output
	printf("%d",cnt);
	p1=0;
	while(p1<cnt){
		printf(" %d %.1lf",t3[p1].exp,t3[p1].coe);
		//这里的格式输出，空格给在%d和%。1lf之前。若 printf("%d",cnt);的%d后又一个空格，然后这里在%d和%。1lf之后加空格，则最后会多一个空格，格式错误。 
		p1++;
	}
	
	return 0;
}


//其实不用专门做结构体类型Term，用一个数字数组即可。下标为exp，值为coe。类似桶排序 













