#include<iostream>
using namespace std;

int main(void){
	int num,i;
	cin>>num;
	int request[num];
	for(i=0;i<num;i++){
		cin>>request[i];
	}
	
	int current=0,time=0;
	for(i=0;i<num;i++){
		if(current<request[i]){
			time+=5+6*(request[i]-current);
			current=request[i];
		}else{
			time+=5+4*(current-request[i]); 
			current=request[i];
		}
	}
	cout<<time;
	return 0;
} 

//elevator 	����
//denote	��ʾ����������ζ��	 
/* 
�ⲻ��ѧ���Ұ�else�ĳ�else if(current>request[i])�� 
��ֹ����current==request[i}]���������Ҫ������5s�ȴ���
����Ͻ��İ汾����ȫ�ԣ����Ͻ��ķ���ȫ�ԡ�
����current==request[i}]ʱ�����Ҫ��5s�� 
*/ 
