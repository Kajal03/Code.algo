#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[11], int n)
{
	int dp[100];
	for(int i=0;i<n;i++) dp[i]=1;

	int best = -1;
	
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(arr[j]<=arr[i]) //jth element can be absorbed by the ith element
			{
				int curLen = 1 + dp[j];
				dp[i] = max(curLen, dp[i]);
			}	
		}

		best = max(best, dp[i]);
	}

	return best;
}

int main()
{
	int arr[11]= {10, 22, 9, 33, 21, 50, 41, 60, 80, 6};
	int n= sizeof(arr)/sizeof(int);

	cout<<LIS(arr, n);
}
