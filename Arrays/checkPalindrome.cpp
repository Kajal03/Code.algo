/* Take as input N, a number. Take N more inputs and store that 
in an array. Write a recursive function which tests if the array is 
a palindrome and returns a Boolean value. Print the value returned. */

#include<iostream>
using namespace std;
int main()
{
	int n, i, j;
	cin>>n;

	char A[100];
	for(i=0;i<n;i++)
		cin>>A[i];

	
	for(i=0,j=n-1;i<j;i++,j--)
		if(A[i]!=A[j])
			break;


	if(i>=j)
		cout<<"true";

	else
		cout<<"false";
}