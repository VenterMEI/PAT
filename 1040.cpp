#include<iostream>
#include<string>
using namespace std;

char str[1010];
string s; 
int p,l,r,maxlen;

int main(void)
{
	cin.getline(str,1010);
	s=str; //getline��getֻ�ܲ���char str[]�������ܲ���string 
	for(p=0;p<s.length();p++)
	{
		l=r=p;//�������Գ��������ġ� 
		while(l>=0&&r<s.length())//����������--l��++r����Ϊ���--l���Ϸ�����ֱ��break�ˣ�r��û����++�ˡ���������l��r��ѭ��ʱͬʱ���Ϸ��������� 
		{
			if(s[l]!=s[r])
				break;
			l--;
			r++;		
		//�����ǹ���򲻵ȣ���ѭ��ʱ��l��r���ǷǷ��ġ�Ҳ����˵��������ʱ��l��r������ָ�������ı߽磬��һ���Ǳȱ߽��1����������ͳһ����r-l-1��			
		}
		if(maxlen<r-l-1)
			maxlen=r-l-1;	
		l=p;
		r=p+1;//�������Գ���ż���ġ� 
		while(l>=0&&r<s.length())//���ﲻ��++l��--r��������Ϊ����--ֱ��break������Ϊ����p��p+1�Ͳ��ȣ�����l��r�Ѿ��Ƿ����ж�ʱ++��������ʹlen��ʵ��ֵƫ�� 
		{
			if(s[l]!=s[r])
				break;
			l--;
			r++; 
		}	
		if(maxlen<r-l-1)
			maxlen=r-l-1;
	} 
	cout<<maxlen;
	return 0;	
} 

//cin��scanf�����򵥴ʵģ�get��getline�������еġ�getline��get��ʹ����Ҫͷ�ļ���string�� 
//get��getline��ȡһ�У�ʹ��ʱ������cin.get/getline(string str,int size)����ȡһ�У������з����ȡsize-1���ַ��������ĩβ��'\0'��β�󸳸�str��
//ֻ�ܴ���char str[]���ͣ����ܴ��� string���͡�
//get()��getline()����get������ĩ�������з���getline������ĩ��ȡ���з���������
//�����˵��getline���򵥣�get����ڼ�顣 
//cin.get()==getchar()          cin.getline(string str,int size)==gets(s)  

//���������������ֻ��1���ַ��Ͳ����ַ��� 
//��Ҫʹ��&&����ʽ�в���++��--����Ϊ���ܲ�������������������ѭ���� 
//���������ַ�����һ���Ǵ�ָ��p1��ͷ�����ߣ�p2��ĩβ׷������Ⱦ�p2���ƣ�p1��ԭ����Ⱦ�ͬʱ���м��ơ���p1==p2ʱ��¼���ȡ� 
//��һ��ָ��p��ͷ�����ߣ�ָ��l��p������ָ��r��p��p+1��������l��r��ָ���Ȼ�l��r���߽��Ǿͼ�¼���ȡ������˵�����ߴ����㣬���Ҹ�����break�� 
