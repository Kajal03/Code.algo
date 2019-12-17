/*Take the following as input.
A character (ch) Write a function that returns ‘U’, if it is uppercase; 
‘L’ if it is lowercase and ‘I’ otherwise. Print the value returned.
*/

#include<iostream>
using namespace std;

char checkType(char ch){
	if(ch>='a' && ch<='z')
		return 'L';

	if(ch>='A' && ch<='Z')
		return 'U';

	return 'I';
}

int main()
{
	char ch,result;
	cin>>ch;

	result = checkType(ch);
	cout<<result;
}