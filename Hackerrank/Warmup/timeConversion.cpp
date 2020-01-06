#include<iostream>
#include<string>
using namespace std;
int main()
{
	int i;	
	string input;
	cin>>input;
	int length = input.length();
	if(input[length-2]=='A')
	{
		if(input[0]=='1' && input[1]=='2')
			input[0]=input[1]='0';		
		
	}
	else
	{
		int ans = ((input[0]-'0')*10) + (input[1]-'0');
		if(ans!=12)
		{
			ans+=12;
			input[1]=(ans%10)+'0';
			ans=ans/10;
			input[0]=ans+'0';
		}
	
	}
	for(i=0;i<length-2;i++)
		cout<<input[i];
}
