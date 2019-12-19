/*One of the important aspect of object oriented programming is readability 
of the code. To enhance the readability of code, developers write function 
and variable names in Camel Case. You are given a string, S, written in 
Camel Case. FindAllTheWordsContainedInIt.
*/

#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string s1;
	cin>>s1;

	int i=1;
	cout<<s1[0];
	while(s1[i]!='\0'){
		if(s1[i]>='A' && s1[i]<='Z')
			cout<<endl;
		
		cout<<s1[i];
		i++;
	}
}