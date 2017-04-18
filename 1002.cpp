/*
1002. A+B for Polynomials (25)

ʱ������
400 ms
�ڴ�����
65536 kB
���볤������
16000 B
�������
Standard
����
CHEN, Yue
This time, you are supposed to find A+B where A and B are two polynomials.

Input

Each input file contains one test case. Each case occupies 2 lines, and each line contains the information of a polynomial: K N1 aN1 N2 aN2 ... NK aNK, 
where K is the number of nonzero terms in the polynomial, Ni and aNi (i=1, 2, ..., K) are the exponents and coefficients, respectively. 
It is given that 1 <= K <= 10��0 <= NK < ... < N2 < N1 <=1000.

Output

For each test case you should output the sum of A and B in one line, with the same format as the input. 
Notice that there must be NO extra space at the end of each line. Please be accurate to 1 decimal place.

Sample Input
2 1 2.4 0 3.2
2 2 1.5 1 0.5
Sample Output
3 2 1.5 1 2.9 0 3.2
*/ 

//polynomia ����ʽ 
//exponent ָ��
//coefficient	ϵ�� 
//1 decimal place	1λС�� 

//��Ŀ����˼��˵������������ÿ����һ������ʽ����һ��������k�������ж����֮���������֣��ֱ���ָ����ϵ����
//���ڣ�Ҫ���㽫��������ʽ�ϲ�������ָͬ���ĺϲ���һ�� 

/*
abs(x)������x�ľ���ֵ��
fabs(x)����������С����x�ľ���ֵ��
pow(a, x)��a��x�η���a��x�Ǹ�����������ֵ�Ǹ���������ʹa��x����������Ҳ�ᱻת���ɸ�����������������������ʧ���ȣ��������
exp(x)��e��x�η���x�Ǹ�������e����Ȼ�����ĵ�����һ����������ֵΪ2.71828....��
*/ 
#include<stdio.h>

typedef struct {
	int exp;
	double coe;//��double����float��float������%lfȥscanf,��Ҫ��%f.
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
			if(t1[p1].coe + t2[p2].coe>1e-6||t1[p1].coe + t2[p2].coe<-1e-6){//����ע���Ǿ���ֵ<1e-6.��Σ�����ľ���ֵ����abs����fbs�� 
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
		//����ĸ�ʽ������ո����%d��%��1lf֮ǰ���� printf("%d",cnt);��%d����һ���ո�Ȼ��������%d��%��1lf֮��ӿո��������һ���ո񣬸�ʽ���� 
		p1++;
	}
	
	return 0;
}


//��ʵ����ר�����ṹ������Term����һ���������鼴�ɡ��±�Ϊexp��ֵΪcoe������Ͱ���� 













