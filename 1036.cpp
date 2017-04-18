#include<iostream>
#include<string>
using namespace std;

int n;
string name,id;
int grade;
char gender;
int mingrade=101,maxgrade=-1;
string minname,maxname,minid,maxid;

int main(void)
{
	cin>>n;
	while(n--)
	{
		cin>>name>>gender>>id>>grade;
		if(gender=='M'&&grade<mingrade)
		{
			minname=name;
			minid=id;
			mingrade=grade;
		}
		if(gender=='F'&&grade>maxgrade)
		{
			maxname=name;
			maxid=id;
			maxgrade=grade;	
		}	
	}
	if(maxgrade!=-1)
		cout<<maxname<<" "<<maxid<<endl;
	else
		cout<<"Absent"<<endl;
	if(mingrade!=101)
		cout<<minname<<" "<<minid<<endl; 
	else
		cout<<"Absent"<<endl;
	if(mingrade!=101&&maxgrade!=-1)
		cout<<maxgrade-mingrade<<endl;
	else
		cout<<"NA"<<endl;		
	return 0;	
} 
