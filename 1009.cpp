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
					if(p[k].coe<10e-2&&p[k].coe>-10e-2){//��������Ӻ�ʹϵ��Ϊ0��ҲҪ����ɾ���� 
						p.erase(p.begin()+k);
					} 
					is_same=1;
					break;
				}
			}
			if(!is_same&& (t.coe>10e-3||t.coe<-10e-3)){//����Ҫ�жϣ��û�Ϊ0�Ĳ����롣����0.1*0.2 
				p.push_back(t);
			}
		}
	}
	
	cout<<p.size();
	sort(p.begin(),p.end(),by_exp);
	while(!p.empty()){
		//�����������ж�ϵ���Ƿ�Ϊ0����Ϊ�������ﲻ��ӡ0����ϵ���Ѿ����ˡ� 
		printf(" %d %.1f",p.back().exp,p.back().coe);
		p.pop_back(); 
	} 
	return 0;
}

//ע��ϵ��coeΪ0�����������ʽ��Ŀ��һ���۷ֵ㡣���������ʱ���ж�ϵ���Ƿ�Ϊ0����Ϊ��Ҫ��ӡp��size������Ӧ����ѹ������ʱ�ж��Ƿ�Ӧ��ѹ�룬Ȼ��Ӻͺ��жϺ��Ƿ�Ϊ0�� 
//��ϰ���䣺��ʵ�Կ����������ʱ�жϡ�����һ��p��ȷ���ж���Ԫ�����������������0���ж�����ֻ��Ҫһ�Σ��������ֽṹ����ȷ�ʸ��ߡ� 
//scanf һ��doubleҪ��lf�� 
//��ʵ�������������Ͱ����ã��������Ѿ�������ѭ����n^3�ĸ��Ӷ��ˣ����뻹���߳����߳������׳���Ͱ����ѹ�벻�ùܣ��ӺͲ��ùܣ�������������������ʱ�Ѻùؾͺã��򵥶���ȷ�� 
