#include<iostream>
#include<string>
using namespace std;

string num1,num2,tmp;
int step,i=0,j,k; 
int main(void)
{
	cin>>num1>>step;
	while(i<step)
	{
		num2.assign(num1.rbegin(),num1.rend());
		if(num1==num2) break;
		i++;
		tmp=num1; 
//		num1.clear();
		k=0;
		for(j=0;j<num2.size();j++)
		{
			int x=tmp[j]-'0';
			int y=num2[j]-'0';//ʵ����������jӦ�ôӺ���ǰ�ӵģ�����Ϊ���������Կ���͵������
//			num1+=(char)((x+y+k)%10+'0');
			num1[j]=(char)((x+y+k)%10+'0');
			k=(x+y+k)/10; 
		}
		if(k)
			num1+=(char)(k+'0');			
		tmp.assign(num1.rbegin(),num1.rend());
		num1=tmp;
	}
	
	cout<<num1<<endl<<i;
	return 0;
}

//�����ѧϰһ��string��Ĳ����� 
//Ϊʲô֮ǰ�Ĳ���num1[j]�Ĳ���
//�����Ҫʹ��num1[j]��������num1[j]�Ѵ��ڵ�����²ſ��ԣ�����clear()��num1[j]=��������δ���ٵ�λ�ã���Ҫͨ��+=�ַ�/�ַ�������ӡ� 
//���ڽ�λ�����Բ�ȡ����ӣ�������ķ�ʽ����������ʡȥ�Գ�������ͷ���Ų顣 
