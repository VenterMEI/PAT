#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Record{
	char ID[16];
	int in[3];
	int out[3];
}; 

int main(void){
	int m,i;
	scanf("%d",&m);
	Record record[m]; 
	for(i=0;i<m;i++){
		scanf("%s",record[i].ID);
		scanf("%d:%d:%d",&record[i].in[0],&record[i].in[1],&record[i].in[2]);
		scanf("%d:%d:%d",&record[i].out[0],&record[i].out[1],&record[i].out[2]);
	} 
	vector<int> in_second,out_second;
	for(i=0;i<m;i++){
		in_second.push_back(record[i].in[0]*3600+record[i].in[1]*60+record[i].in[2]); 
		out_second.push_back(record[i].out[0]*3600+record[i].out[1]*60+record[i].out[2]); 
	}
//	for(i=0;i<m;i++){
//		printf("%s %d %d\n",record[i].ID,in_second.at(i) ,out_second.at(i) );
//	} 
	printf("%s ",record[min_element(in_second.begin(),in_second.end())-in_second.begin()].ID);
	printf("%s",record[max_element(out_second.begin(),out_second.end())-out_second.begin()].ID);
	return 0;
}

//��ΪSTLֻ֧�ֳ��������ݵ�min_element��max_element
//��ˣ����������ν�in_second��out_second������ṹ�塣����ʹ��min_element��max_element
//��Ȼ�����ǿ���ͨ������ < ���ţ����� > ����û�����壬��Ϊ��STL����ֻʹ����<,������ʵ�����е�Ѱ��maxҲ���ҵ�in_time��max�������������ֵ�� 
//��һ�ַ��������Լ�����sort������ֵ������compare����(��ʵ����redim <������sort�����Զ��������жϷ���true���ͱ�������1С�ڲ���2��������ڵ���)�� 
//���⣬��ʵ����second������һ�Ƚ�ʱ����Ҳ��һ���ܺõ�˼·�� 

/* 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct Record{
	char ID[16];
	int in[3];
	int out[3];
	int in_second;
	int out_second;
	bool operator<(Record b){
		return in_second<b.in_second;  
	} //����< 
	bool operator>(Record b){
		return out_second<b.out_second;  
	} //����> 
}; 

bool by_in_second(const Record &a,const Record &b){
	return a.in_second<b.in_second;
}//�Զ���compare���� 
bool by_out_second(const Record &a,const Record &b){
	return a.out_second<b.out_second;
}//�Զ���compare���� 

int main(void){
	int i;
	Record record[3];
	strcpy(record[0].ID,"p1");  
	strcpy(record[1].ID,"p2");  
	strcpy(record[2].ID,"p3");  
	record[0].in[0]=15; 
	record[0].in[1]=30;
	record[0].in[2]=28;  
	record[0].out[0]=17; 
	record[0].out[1]=00;
	record[0].out[2]=10;

	record[1].in[0]=8; 
	record[1].in[1]=00;
	record[1].in[2]=00;  
	record[1].out[0]=11; 
	record[1].out[1]=25;
	record[1].out[2]=25;	
	
	record[2].in[0]=21; 
	record[2].in[1]=45;
	record[2].in[2]=00;  
	record[2].out[0]=21; 
	record[2].out[1]=58;
	record[2].out[2]=40;

	for(i=0;i<3;i++){
		record[i].in_second=record[i].in[0]*3600+record[i].in[1]*60+record[i].in[2]; 
		record[i].out_second=record[i].out[0]*3600+record[i].out[1]*60+record[i].out[2]; 
	}

	vector<Record> rec;
	rec.push_back(record[0]);
	rec.push_back(record[1]);
	rec.push_back(record[2]);   

	printf("%s ",record[min_element(rec.begin(),rec.end())-rec.begin()].ID);//���� 
	printf("%s ",record[max_element(rec.begin(),rec.end())-rec.begin()].ID);//���� 

	printf("%s ",record[min_element(rec.begin(),rec.end(),by_in_second)-rec.begin()].ID);//�Զ���compare���� 
	printf("%s ",record[max_element(rec.begin(),rec.end(),by_out_second)-rec.begin()].ID);//�Զ���compare���� 
	
	return 0;
} 
*/ 
