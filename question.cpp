#include<iostream>
#include<cstdio>
#include<cstring>
#include<math.h>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long a=0;
int main()
{
    int l=sizeof(long long);
    cout<<pow(2,l*8)-1<<endl;
    if((pow(2,l*8)-1)>(100000.0*40000.0))
        cout<<"OK"<<endl;
    else
        cout<<"overflow"<<endl;
     //Ϊʲôdouble*int�Ϳ������������int*intȴ�������̡� 
	 //����cout����ok��Ϊʲô���������̡� 
	 a=40000*100000;
     printf("%I64d\n",a);
     a=40000.0*100000;
     printf("%I64d\n",a);
    return 0;
}
