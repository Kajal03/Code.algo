#include<iostream>
using namespace std;
int main()
{
	int i,j,n, A[100],temp,k;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			k=j-1;
			temp=A[j];
			while(temp<A[k] && k>=0){
				A[k+1]=A[k];
				k--;
			}
			A[k+1]=temp;

		}
	}

	for(i=0;i<n;i++)
		cout<<A[i]<<" ";
}