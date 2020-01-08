#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define ll long long

bool check(string a, string b)
{
	if(a.length()>b.length())
		return false;
	else if(a.length()<b.length())
		return true;
	else
		return a<b;
}

int main()
{
	ll n,i,j;
	cin>>n;
	string A[n];
	for(i=0;i<n;i++)
		cin>>A[i];
	
	sort(A,A+n,check);
	for(i=0;i<n;i++)
		cout<<A[i]<<endl; 
}
