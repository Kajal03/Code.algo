#include<bits/stdc++.h>
using namespace std;


//dp[i][j] represents from ith bottle to jth bottle 
//for i>j data will be invalid

int wine(int arr[1000], int n)
{
	int dp[1000][1000];
	int year = n;

	for(int i=0;i<n;i++)
		dp[i][i] = year * arr[i]; //for i=j means only bottle...one bottle will be left in the last year only

	--year;

	for(int len = 2;len<=n;len++)
	{
		int start = 0, end = n-len;
		while(start<=end)
		{
			int endWindow = start + len - 1;
			dp[start][endWindow] = max((arr[start]*year + dp[start+1][endWindow]),(arr[endWindow]*year+dp[start][endWindow-1]));
			start++;
		}
		--year;
	}

	return dp[0][n-1];
}

int main()
{
	int n;
	cin>>n;

	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	cout<<wine(arr,n)<<endl;
}
