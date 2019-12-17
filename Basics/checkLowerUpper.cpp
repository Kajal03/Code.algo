//Print "lowercase" if user enters a character between 'a-z' , 
//Print "UPPERCASE" is character lies between 'A-Z' and print "Invalid" 
//for all other characters like $,.^# etc.

#include<iostream>
using namespace std;
int main()
{
	char input;
	cin>>input;

	if(input>='a' && input<='z')
		cout<<"lowercase";

	else if(input>='A' && input<='Z')
		cout<<"UPPERCASE";

	else
		cout<<"Invalid";
}