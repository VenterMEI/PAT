/*
1001. A+B Format (20)

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
Calculate a + b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

Input

Each input file contains one test case. Each case contains a pair of integers a and b where -1000000 <= a, b <= 1000000. The numbers are separated by a space.

Output

For each test case, you should output the sum of a and b in one line. The sum must be written in the standard format.

Sample Input
-1000000 9
Sample Output
-999,991


*/ 


//digit 数字
//commas 逗号 

#include<stdio.h> 

int main(){
	int a,b;
	int sz[3];
	
	scanf("%d",&a);
	scanf("%d",&b);
	a=a+b;
	
	if(a==0){
		printf("0");
	}else{
	 	if(a<0){
			a= -a;
			printf("-");
		}
		
		int b=-1;
		while(a!=0){
			b++;
			sz[b]=a%1000;
			a/=1000;
		}
		printf("%d",sz[b]);
		while(b>0){
			printf(",%03d",sz[--b]);
		}
	} 
	
	printf("\n");
 
	return 0;
}

//999999 	1    	1000000
//0 		0  		0
//-1		0		-1	




//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int a = 0, b = 0, sum = 0;
//	
//	while(scanf("%d %d", &a, &b) != EOF)
//	{
//		sum = a+b;
//		if (abs(sum)< 1000)
//			printf("%d\n", sum);
//		else if (abs(sum) <= 999999)
//			printf("%d,%03d\n", sum /1000, abs(sum) % 1000);
//		else
//			printf("%d,%03d,%03d\n", sum / 1000000, (abs(sum) %1000000) /1000, abs(sum) % 1000);
//	}
//	return 0;
//}	
