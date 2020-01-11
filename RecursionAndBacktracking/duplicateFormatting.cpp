#include<iostream>
using namespace std;

void print(string input, int i)
{
	if(input[i]=='\0')
	{
		cout<<endl;
		return;
	}
	
	if(input[i]=='p' && input[i+1]=='i')
	{
		cout<<"3.14";
		return print(input,i+2);	
	}

	else if(i==0)
		cout<<input[i];

	else
		cout<<input[i];
	print(input,i+1);
}

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string input;
		cin>>input;
	
		print(input,0);
	}

}
