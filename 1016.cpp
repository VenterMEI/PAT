#include<iostream>
#include<deque>
#include<algorithm>
#include<string.h>
using namespace std;

struct record//����typedef������c��д���� 
{
  char name[21];
  int time;
  int month;
  bool is_on; 
};

bool compare(record a,record b)
{
  	if(strcmp(a.name ,b.name))
  	{
   	 	if(strcmp(a.name,b.name)<0)//strcmp a<b,���ظ�����a>b,���������� 
      		return true;
   	 	else
      		return false;
  	}     
  	else 
    	return a.time<b.time; 
}

int toll[24],daytoll=0,N;
deque<record> data;
int day,hour,minute;
char flag[10];
int i,j;

double dealTime(int a,int b){ 
  	int da,ha,ma,db,hb,mb,k;
  	/*dd��hh��mm��minute��ת��*/ 
	da=a/(24*60);
  	db=b/(24*60);
  	ha=(a%(24*60))/60;
  	ma=(a%(24*60))%60;
  	hb=(b%(24*60))/60;
  	mb=(b%(24*60))%60;
  	double cost1=da*daytoll,cost2=db*daytoll;
  	for(k=0;k<ha;k++)
	{
    	cost1+=60*toll[k];
  	}
  	cost1+=ma*toll[k];
  	for(k=0;k<hb;k++)
	{
    	cost2+=60*toll[k];
  	}
  	cost2+=mb*toll[k]; 
  	printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n",da,ha,ma,db,hb,mb,b-a,(cost2-cost1)/100);
  	return (cost2-cost1)/100;
}   

int main(void)
{
  	i=0;
	while(i<24)
	{
		cin>>toll[i];
		daytoll+=60*toll[i++];//��24Сʱ�绰�Ļ���  
	}
	cin>>N;
	for(i=0;i<N;i++)
	{
		record call;
		scanf("%s %d:%d:%d:%d %s",call.name,&call.month,&day,&hour,&minute,flag);
		call.time=day*60*24+hour*60+minute;
		if(flag[1]=='n')
	 		call.is_on=true;
		else
		  	call.is_on=false;//û���Զ���ʼ�������else����ʡ��
		data.push_back(call);   
	}
	sort(data.begin(),data.end(),compare);
  

	char name[21];
	strcpy(name,data[0].name);  
	bool is_on=false;
	double amount=0;
	int time_start;
	bool is_print=0;//����is_print,���û��ƥ���on-off����ô�Ͳ���ӡ�����ϵ�ˡ� 
  	while(data.size())//data��on���͸���on��time����off��ȷ��֮ǰ��on��printfһ�С�is_changed��print total amount�� 
  	{
	    if(data[0].is_on)
	    {
	    	is_on=true;
	      	time_start=data[0].time;  
	    }
	    else if(is_on)//is_on��true����data[0].is_on��false�����ͨ������Ч�ˡ� 
	    {
	      	if(!is_print)
			{
				printf("%s %02d\n",data[0].name,data[0].month);
				is_print=1;
			 
			}   
			amount+=dealTime(time_start,data[0].time);
			is_on=false;//������ҲҪ��false���ֵ��԰��졣������false��Ϊ�˷�ֹsamename��on-off-off 
	    }
	    data.pop_front();
	    if(strcmp(name,data[0].name))
	    {
	      	if(is_print)
			{
			  	printf("Total amount: $%.02f\n",amount);
			  	is_on=false;
	      		is_print=0;
			}
			amount=0;
			is_on=false;//������false��Ϊ�˷�ֹon-changedname-off 
	      	strcpy(name,data[0].name);
	    }
  	}  
  	return 0;
}


//CYLL��CYJJ����aaaǰ�棬��Ϊaaa��Сд����д��ASCII����Сд��С��
//is_on����false�Ǳ�����ѵ㣬Ҫϸ�Ŀ��ǲ��С�����˵����flag�� 
//ʱ��ͷ��ӵ�ת��Ҳ���Բο��� 
