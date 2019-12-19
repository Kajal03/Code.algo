//To check whether a given array is sorted or not using recursion
#include<iostream>
using namespace std;

bool isSorted(char *A, int n){
	if(n==1)
		return true;

	if(A[0]<A[1] && isSorted(A+1,n-1))
		return true;

	return false;
}

int main()
{
	int n,i;
	char A[100];
	cin>>n;

	for(i=0;i<n;i++)
		cin>>A[i];

	bool result = isSorted(A,n);

	if(result==true)
		cout<<"Array is sorted";

	else 
	cout<<"Array is not sorted";

	return 0;
}