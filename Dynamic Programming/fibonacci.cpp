#include<bits/stdc++.h>
using namespace std;

int memo[1000];

int fib(int n)
{
	if(n==0)
		return 0;

	if(n==1)
		return 1;

	if(memo[n]!=-1)
		return memo[n];

	memo[n] = fib(n-1) + fib(n-2);
	
	return memo[n];

}

int main()
{
	int n;
	cin>>n;
	
	for(int i=0;i<1000;i++)
		memo[i]=-1;

	cout<<fib(n)<<endl;
}

