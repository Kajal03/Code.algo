/*
We are given an array containg n numbers. All the numbers are present 
twice except for one number which is only present once. Find the unique 
number without taking any extra spaces and in linear time. ( Hint - Use Bitwise )
*/

#include<iostream>
using namespace std;
int main()
{
	int n,num,result=0;
	cin>>n;
	for(int i=0;i<n;i++)	
	{
		cin>>num;
		result = result ^ num;
	}

	cout<<result<<endl;
}