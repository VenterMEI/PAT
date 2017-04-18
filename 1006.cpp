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

//因为STL只支持常类型数据的min_element和max_element
//因此，上面我无奈将in_second和out_second分离出结构体。单独使用min_element和max_element
//当然，我们可以通过重载 < 符号（重载 > 符号没有意义，因为在STL库中只使用了<,所以其实下例中的寻找max也是找的in_time的max）来排序和找最值。 
//另一种方法就是自己定义sort，找最值函数的compare函数(其实就是redim <，告诉sort，当自定义的这个判断返回true，就表明参数1小于参数2。否则大于等于)。 
//此外，此实验用second代替逐一比较时分秒也是一个很好的思路。 

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
	} //重载< 
	bool operator>(Record b){
		return out_second<b.out_second;  
	} //重载> 
}; 

bool by_in_second(const Record &a,const Record &b){
	return a.in_second<b.in_second;
}//自定义compare函数 
bool by_out_second(const Record &a,const Record &b){
	return a.out_second<b.out_second;
}//自定义compare函数 

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

	printf("%s ",record[min_element(rec.begin(),rec.end())-rec.begin()].ID);//重载 
	printf("%s ",record[max_element(rec.begin(),rec.end())-rec.begin()].ID);//重载 

	printf("%s ",record[min_element(rec.begin(),rec.end(),by_in_second)-rec.begin()].ID);//自定义compare函数 
	printf("%s ",record[max_element(rec.begin(),rec.end(),by_out_second)-rec.begin()].ID);//自定义compare函数 
	
	return 0;
} 
*/ 
