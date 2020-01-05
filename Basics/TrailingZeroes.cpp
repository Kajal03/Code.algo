#include<iostream>
using namespace std;
#define ll long long

int main()
{
	ll n,count=0,i;
	cin>>n;
	for(i=5;(n/i)>=1;i*=5)
		count+= n/i;
	cout<<count<<endl;
}
