#include<iostream>
using namespace std;
int main()
{
	int n, A[1000], m, B[1000],i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];

	cin>>m;
	for(i=0;i<m;i++)
		cin>>B[i];

	for(i=n-1,j=m-1;i>=0 && j>=0;i--,j--){
		result=A[i]+B[j]+result;
		if(result>=10){
			cout<<result%10<<", ";
			result = result/10;
		}
	}

	if(n>m){
		while(i--){
			result=A[i]+result;
			if(result>=10){
				cout<<result%10<<", ";
			}
		}
	}

	
}