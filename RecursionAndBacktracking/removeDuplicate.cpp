#include<iostream>
using namespace std;

void print(string input, int i)
{
	if(input[i]=='\0')
		return;
	
	if(i==0)
		cout<<input[i];

	if(input[i]!=input[i+1])
		cout<<input[i+1];
	
	print(input,i+1);
}

int main()
{
	string input;
	cin>>input;
	
	print(input,0);
	cout<<endl;
}
