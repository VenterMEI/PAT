#include<iostream>
#include<string>
using namespace std;

char str[1010];
string s; 
int p,l,r,maxlen;

int main(void)
{
	cin.getline(str,1010);
	s=str; //getline和get只能操作char str[]，而不能操作string 
	for(p=0;p<s.length();p++)
	{
		l=r=p;//如果这个对称是奇数的。 
		while(l>=0&&r<s.length())//不能在这里--l和++r。因为如果--l不合法，就直接break了，r就没机会++了。不能满足l和r出循环时同时不合法的条件。 
		{
			if(s[l]!=s[r])
				break;
			l--;
			r++;		
		//无论是过界或不等，出循环时，l和r都是非法的。也就是说，出来的时候l和r都不会指向真正的边界，而一定是比边界大1，这样可以统一操作r-l-1。			
		}
		if(maxlen<r-l-1)
			maxlen=r-l-1;	
		l=p;
		r=p+1;//如果这个对称是偶数的。 
		while(l>=0&&r<s.length())//这里不能++l和--r，不但因为单侧--直接break，还因为可能p和p+1就不等，这样l和r已经非法，判断时++，——会使len比实际值偏大。 
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

//cin和scanf是面向单词的，get和getline是面向行的。getline和get的使用需要头文件：string。 
//get和getline读取一行，使用时，形如cin.get/getline(string str,int size)。读取一行，至换行符或读取size-1个字符后结束，末尾加'\0'结尾后赋给str。
//只能处理char str[]类型，不能处理 string类型。
//get()和getline()区别：get读到行末不处理换行符。getline读到行末读取换行符并丢弃。
//相对来说，getline更简单，get则便于检查。 
//cin.get()==getchar()          cin.getline(string str,int size)==gets(s)  

//考虑下特殊情况，只输1个字符和不输字符。 
//不要使用&&的右式中采用++，--，因为可能操作不到，甚至进入死循环。 
//这里有两种方法，一种是从指针p1从头慢慢走，p2从末尾追，不相等就p2左移，p1还原，相等就同时向中间移。当p1==p2时记录长度。 
//另一种指针p从头慢慢走，指针l从p出发，指针r从p或p+1出发。当l，r所指不等或l，r到边界是就记录长度。相对来说，后者代码简便，而且更容易break。 
