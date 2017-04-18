#include<iostream>
#include<string>
using namespace std;

int k;
string s1[55],s2[55];
int s[55],i,j,t;

int main() 
{
	for(i=1;i<=13;i++)
	{
		s1[i]+='S';
		if(i>=10)
			s1[i]+='1';
		s1[i]+=(char)(i%10+'0');	
	}
	for(i=14;i<=26;i++)
	{
		s1[i]+='H';
		if(i>=23)
			s1[i]+='1';
		s1[i]+=(char)((i-13)%10+'0');	
	}
	for(i=27;i<=39;i++)
	{
		s1[i]+='C';
		if(i>=36)
			s1[i]+='1';
		s1[i]+=(char)((i-26)%10+'0');	
	}
	for(i=40;i<=52;i++)
	{
		s1[i]+='D';
		if(i>=49)
			s1[i]+='1';
		s1[i]+=(char)((i-39)%10+'0');	
	}
	s1[53]="J1",s1[54]="J2";
	
	cin>>k;
	for(i=1;i<=54;i++)
		cin>>s[i];
	for(i=1;i<55;i++)
	{
		t=s[i];
		for(j=1;j<k;j++)
			t=s[t];
		s2[t]=s1[i];
	}	
	if(k=0)
		for(i=1;i<55;i++)
		{
			if(i!=1)
				cout<<" ";
			cout<<s1[i];	
		}
	else
		for(i=1;i<55;i++)
		{
			if(i!=1)
				cout<<" ";
			cout<<s2[i];	
		}	
	return 0;
}

//预处理其实不用这么麻烦，把整个字符串构造出来。可以把s1和s2都改成int。然后打印的时候处理int即可。 
/* 
#include<cstdio>      
#include<cstring>      
#include<cmath>      
#include<algorithm>      
#include<queue>      
using namespace std;  
typedef long long ll;  
const int maxn = 1e5 + 5;  
int nt[maxn], n, v[2][maxn], now;  
  
void write(int x)  
{  
    if (x > 52) { printf("J%d", x - 52); return; }  
    if (x > 39) { printf("D%d", x - 39); return; }  
    if (x > 26) { printf("C%d", x - 26); return; }  
    if (x > 13) { printf("H%d", x - 13); return; }  
    printf("S%d", x);  
}  
  
int main()  
{  
    scanf("%d", &n);  
    for (int i = 1; i <= 54; i++) scanf("%d", &nt[i]), v[now][i] = i;  
    while (n--)  
    {  
        for (int i = 1; i <= 54; i++) v[now ^ 1][nt[i]] = v[now][i];  
        now ^= 1;  
    }  
    for (int i = 1; i <= 54; i++)  
    {  
        write(v[now][i]);  
        printf("%s", i < 54 ? " " : "\n");  
    }  
    return 0;  
} 
*/
