//Wave sort the given elemts

#include<iostream>
using namespace std;
int main()
{
	int n, A[100],i,j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];

	for(i=0;i<n;i+=2){
		if(i>0 && A[i-1]>A[i])
			swap(A[i-1], A[i]);

		if(A[i+1]>A[i] && i<n-1)
			swap(A[i+1],A[i]);
	}

	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
}