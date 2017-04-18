#include<iostream>
using namespace std;

double bestBet(void){
	double max=0,odd;	 
	int i,tag=0;
	for(i=1;i<=3;i++){
		scanf("%lf",&odd);
		if(max<odd){
			max=odd;
			tag=i;
		}
	}
	switch (tag){
	case 1:
		printf("W ");
		break;	
	case 2:
		printf("T ");
		break;
	case 3:
		printf("L ");
		break;
	}
	return max;
}

int main(void){
	printf("%.2f",bestBet()*bestBet()*bestBet()*1.3-2);
	return 0;
}

//输三个odd打印一个bet这种居然格式也可以。 
