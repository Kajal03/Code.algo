#include<iostream>
#include<string>
using namespace std;
#define ll long long

bool checkMirror(char a, char b)
{
	int i = a - '0';
	int j = b - '0';
	

	if(i==1 && j==1)
		return true;
	if((i==2 && j==7) ||(i==7 && j==2))
		return true;
	if((i==3 && j==8) || (i==8 && j==3))
		return true;
	if((i==4 && j==5) || (i==5 && j==4))
		return true;
	if((i==6 && j==9) || (i==9 && j==6))
		return true;
		
	return false;
	
}


int main()
{
	ll t,i,j;
	cin>>t;
	while(t--)
	{
		string input;
		cin>>input;
		for(i=0,j=input.length()-1;i<j;i++,j--)
		{	
			if(!checkMirror(input[i],input[j]))
				break;
			
		}
		if(input[i]=='0' ||input[j]=='0')
			cout<<"false"<<endl;
		else if(i>=j)
			cout<<"true"<<endl;
		else
			cout<<"false\n";
	}
}


