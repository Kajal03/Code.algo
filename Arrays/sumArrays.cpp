#include<iostream>
using namespace std;
int main()
{
	int n,m, A[1000]={0},B[1000]={0},C[1005]={0},i,j,sum,carry=0,end;
	cin>>n;
	for(i=n-1;i>=0;i--)
		cin>>A[i];
	cin>>m;
	for(i=m-1;i>=0;i--)
		cin>>B[i];
	
	end = m<n?n+1:m+1;
	i=0;
	while(end--)
	{
		sum = A[i]+B[i]+carry;
		C[i]=sum%10;
		carry=sum/10;
		i++;
	}
    if(C[i-1]==0)
        i-=2;
    else i--;    

	for(;i>=0;i--)
	cout<<C[i]<<", ";
	cout<<"END\n";
	

	
}
