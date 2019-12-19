//Selection Sort

#include<iostream>
using namespace std;
int main()
{
	int n,i,j,A[100],min;
	cin>>n;

	for(i=0;i<n;i++)
		cin>>A[i];

	for(j=0;j<n;j++){
		min=j;
		for(i=j+1;i<n;i++)
			if(A[min]>A[i])
				min=i;
		swap(A[j],A[min]);
	}

	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
}