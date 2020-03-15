#include<bits/stdc++.h>
using namespace std;

int steps(int n)
{
	if(n==0)
		return 0;

	int memo[1000];
	memo[1]=0;

	for(int i=2;i<=n;i++)
	{

		int f1,f2,f3;
		f1=f2=f3=INT8_MAX;

		if(i%2==0)
			f1 = 1 + memo[i/2];

		if(i%3==0)
			f2 = 1 + memo[i/3];

		f3 = memo[i-1] + 1;

		memo[i] = min(f1, min(f2,f3));
	}

	return memo[n];

}

int main()
{
	int n;
	cin>>n;

	cout<<steps(n)<<endl;
}
