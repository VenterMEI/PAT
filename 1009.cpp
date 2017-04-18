#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

typedef struct ploy{
	int exp;
	double coe;
}ploy;

bool by_exp(ploy p1,ploy p2){
	return p1.exp<p2.exp;
}

int main(void){
	int num1,num2,i,j;
	scanf("%d",&num1);
	ploy p1[num1];
	for(i=0;i<num1;i++){
		scanf("%d %lf",&p1[i].exp,&p1[i].coe);
	}
	scanf("%d",&num2);
	ploy p2[num2];
	for(i=0;i<num2;i++){
		scanf("%d %lf",&p2[i].exp,&p2[i].coe);
	}

	deque<ploy> p;
	ploy t;
	int is_same,k;
	for(i=0;i<num1;i++){
		for(j=0;j<num2;j++){
			is_same=0;
			t.exp=p1[i].exp+p2[j].exp;
			t.coe=p1[i].coe*p2[j].coe;
			for(k=0; k<p.end()-p.begin();k++){
				if(p[k].exp==t.exp){
					p[k].coe += t.coe;
					if(p[k].coe<10e-2&&p[k].coe>-10e-2){//这里如果加和使系数为0，也要将其删除。 
						p.erase(p.begin()+k);
					} 
					is_same=1;
					break;
				}
			}
			if(!is_same&& (t.coe>10e-3||t.coe<-10e-3)){//这里要判断，让积为0的不进入。比如0.1*0.2 
				p.push_back(t);
			}
		}
	}
	
	cout<<p.size();
	sort(p.begin(),p.end(),by_exp);
	while(!p.empty()){
		//不是在这里判断系数是否为0，因为就算这里不打印0，单系数已经错了。 
		printf(" %d %.1f",p.back().exp,p.back().coe);
		p.pop_back(); 
	} 
	return 0;
}

//注意系数coe为0的情况，多项式题目的一个扣分点。不但输出的时候判断系数是否为0，因为还要打印p的size，所以应该在压入容器时判断是否应该压入，然后加和后判断和是否为0。 
//复习补充：其实仍可以最终输出时判断。先走一遍p，确认有多少元素再输出。这样两次0的判断现在只需要一次，而且这种结构的正确率更高。 
//scanf 一个double要用lf。 
//其实这种情况还是用桶排序好，我这里已经是三重循环，n^3的复杂度了，代码还很冗长。冗长就容易出错。桶排序压入不用管，加和不用管，就在最后遍历两遍数组时把好关就好，简单而正确。 
