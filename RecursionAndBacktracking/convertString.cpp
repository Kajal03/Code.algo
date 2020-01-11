#include<iostream>
#define ll long long
using namespace std;

void convertString(string input,ll &output, int i)
{
	if(input[i]=='\0')
		return;
	int digit = input[i] - '0';
	output = (output*10) + digit; 
	
	convertString(input,output,++i);
	
}

int main()
{
	string input;
	cin>>input;
	ll output=0;
	convertString(input,output,0);
	
	cout<<output<<endl;
}

