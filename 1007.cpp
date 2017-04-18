#include<iostream>
using namespace std;

int main(void){
	int num,i=0;
	scanf("%d",&num);
	int sq[num];
	while(i<num){
		scanf("%d",&sq[i++]);
	} 
	
	int max=-1,sum=-1,max_start,max_end,start,end;
	for(i=0;i<num;i++){
		if(sum<0 && sq[i]>=0){
			sum=sq[i];
			start=end=i;	
		}else if(sum>=0){
			sum+=sq[i];
			end++;
		}
		if(max<sum){
				max=sum;
				max_start=start;
				max_end=end;
		}
	}
	if(max==-1){
		printf("0 %d %d",sq[0],sq[num-1]);
	}else{
		printf("%d %d %d",max,sq[max_start],sq[max_end]);
	}
	
	return 0;
} 

//神奇的在线处理，陈越姥姥在第一节课就讲过。 
