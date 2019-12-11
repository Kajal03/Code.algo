/*Take the following as input.
A number
A digit
Write a function that returns the number of times digit is found in the number. Print the value returned. */

#include<iostream>
using namespace std;
int main()
{
	long long int n;
	int result,temp,count=0,key;
	cin>>n;
	cin>>key;
	while(n>0){
		temp=n%10;
		n/=10;
		if(temp==key)
			count++;
	}	
	cout<<count;
}