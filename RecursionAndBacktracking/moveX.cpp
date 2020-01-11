#include<iostream>
using namespace std;

void moveX(string input, int i)
{
	if(input[i]=='\0')
		return;

	if(input[i]=='x')
	{
		moveX(input,i+1);	
		cout<<input[i];
		return;
	}
	
	cout<<input[i];
	moveX(input,i+1);
		
}

int main()
{
	string input;
	cin>>input;
	moveX(input,0);
}
