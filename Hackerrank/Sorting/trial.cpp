#include<iostream>
using namespace std;
int main()
{
	int i,v,n;
	cin>>v>>n;
	int A[n];
	for(i=0;i<n;i++)	
		cin>>A[i];
	for(i=0;i<n;i++)
		if(A[i]==v)
		{
			cout<<i<<endl;
			break;
		}
	if(i==n)
		cout<<-1<<endl;
}
