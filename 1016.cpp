#include<iostream>
#include<deque>
#include<algorithm>
#include<string.h>
using namespace std;

struct record//不用typedef，那是c的写法。 
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
   	 	if(strcmp(a.name,b.name)<0)//strcmp a<b,返回负数。a>b,返回正数、 
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
  	/*dd：hh：mm和minute的转化*/ 
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
		daytoll+=60*toll[i++];//打24小时电话的花费  
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
		  	call.is_on=false;//没有自动初始化，这个else不能省。
		data.push_back(call);   
	}
	sort(data.begin(),data.end(),compare);
  

	char name[21];
	strcpy(name,data[0].name);  
	bool is_on=false;
	double amount=0;
	int time_start;
	bool is_print=0;//加入is_print,如果没有匹配的on-off，那么就不打印这个联系人。 
  	while(data.size())//data是on，就更新on和time。是off，确认之前是on，printf一行。is_changed，print total amount。 
  	{
	    if(data[0].is_on)
	    {
	    	is_on=true;
	      	time_start=data[0].time;  
	    }
	    else if(is_on)//is_on是true并且data[0].is_on是false，这段通话就有效了。 
	    {
	      	if(!is_print)
			{
				printf("%s %02d\n",data[0].name,data[0].month);
				is_print=1;
			 
			}   
			amount+=dealTime(time_start,data[0].time);
			is_on=false;//在这里也要置false，又调试半天。这里置false是为了防止samename的on-off-off 
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
			is_on=false;//这里置false是为了防止on-changedname-off 
	      	strcpy(name,data[0].name);
	    }
  	}  
  	return 0;
}


//CYLL和CYJJ排在aaa前面，因为aaa是小写，大写的ASCII都比小写的小。
//is_on的置false是本题的难点，要细心考虑才行。或者说少立flag。 
//时间和分钟的转化也可以参考。 
