#include<iostream>
#include<deque>
#include<cstring>
using namespace std;

char num1[21];
int digit[10]={}; 
int i,j,doub=0;
int num2[22]={}; 
bool flag=true;

int main(void)
{
	cin>>num1;
	for(i=0;i<strlen(num1);i++)
	{
		j=num1[i]-'0';
		digit[j]++;	
	}
	//����num1��scanf��Ȼ��¼��digit��ٽ�num1ת��Ϊ���ֲ���2�������������ȥ����digit��������doub�ǿ��ܳ���int��Χ�ģ�����һ�в�����Ӧ�����ַ�������ɡ� 
//	j=1;
//	for(i=strlen(num1)-1;i>=0;i--)
//	{
//		doub=doub+(num1[i]-'0')*j;
//		j*=10;
//	}
//
//	doub*=2;
//	j=doub;
//	while(j)
//	{
//		i=j%10;
//		digit[i]--;
//		j/=10;
//	}
//	for(i=0;i<10;i++)
//	{
//		if(digit[i])
//		{
//			flag=false;
//			break;
//		}
//	}
	for(i=strlen(num1)-1;i>=0;i--)
	{
		j=(num1[i]-'0')*2+num2[i+1];
		num2[i]+=j/10;
		num2[i+1]=j%10;
		digit[j%10]--;
	}
	if(j/10){//λ����ͬ����Ȼ����
		flag=false;
	} 
	for(i=0;i<10;i++)
	{
		if(digit[i])
		{
			flag=false;
			break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	if(num2[0])
		cout<<num2[0];
	for(i=1;i<=strlen(num1);i++)
		printf("%d",num2[i]);	
	return 0;
}

//�����Ȼʹ��stringȥscanf��һ�򼴱�long long ��19λ����Լ9.2*10^18��unsinged long long��20λ,�ǲ�����ȫ��ʾ����20λ�����ֵġ�
//string���ŵ��Ǽ������㣬�������鼴�ɡ�int���е���double���㣬*2���ɡ�
//�����������塣1.���в�����Ҫ����������ɣ���int��long long�����ܳ������̡�2.Ҫ���ǵ���ͷ��λ��num2��num1�Ŀռ��1λ�� 
