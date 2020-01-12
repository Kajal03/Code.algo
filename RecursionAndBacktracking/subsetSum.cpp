#include<iostream>
using namespace std;

bool findSubset(int*a, int i,int sum, int n)
{
	if(i==n)
		return false;
	
	if(a[i]+sum==0)
		return true;

	return findSubset(a,i+1,sum,n) || findSubset(a,i+1,sum+a[i],n);
	
	
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];

		findSubset(a,0,0,n)?cout<<"Yes"<<endl: cout<<"No"<<endl;
	}
}
