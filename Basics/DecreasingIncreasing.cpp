/*Take the following as input.

A number (N)
Take N more numerical inputs
The N inputs for a sequence S = s1, s2, .., sN. Compute if it is possible to split sequence into two sequences -
s1 to si and si+1 to sN such that first sequence is strictly decreasing and second is strictly increasing. Print true/false as output. */

#include<iostream>
using namespace std;

int main()
{
	int n,temp;
	long long int A[1000];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];

	temp=A[0];
	int i=1;

	while(temp>A[i]){
		temp=A[i];
		i++;
	}
	
	if(temp==A[i]){
	//	cout<<"false";
		//temp=A[i];
		i++;
		
	}
	
	//else{
		while(temp<A[i] && i<n){
			temp=A[i];
			i++;
		}
		if(i==n)
			cout<<"true";
		else
			cout<<"false";

	//}
	
}