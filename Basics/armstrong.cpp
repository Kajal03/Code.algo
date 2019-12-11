/*Take the following as input.

A number
Write a function which returns true if the number is an armstrong number and false otherwise, where armstrong number is defined as follows

371 is an Armstrong number as 371 = 3^3 + 7^3 + 1^3
Print the value returned. */

#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,temp,sum=0,digit;
	cin>>n;
	temp=n;
	while(temp>0){
		digit=temp%10;
		temp/=10;
		sum+=pow(digit,3);
	}
	if(n==sum)
		cout<<"true";
	else 
		cout<<"false";
}