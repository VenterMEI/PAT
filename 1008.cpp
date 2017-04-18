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

//elevator 	电梯
//denote	表示，表明，意味着	 
/* 
这不科学。我把else改成else if(current>request[i])， 
防止出现current==request[i}]的情况，还要额外算5s等待。
结果严谨的版本不能全对，不严谨的反而全对。
可能current==request[i}]时候就是要等5s。 
*/ 
