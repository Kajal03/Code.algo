#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
using namespace std;
int main()
{
int t;
cin>>t;
while(t--)
{
	int n,i;
	ll sum=0;
	cin>>n;
	int A[100005];
	for(i=0;i<n;i++)
	{
		cin>>A[i];
		sum+=A[i];
	}
	long double denom = 10*M_PI*n;
	
	cout<<fixed<<setprecision(17)<<sum/denom<<endl;
	

}
}
