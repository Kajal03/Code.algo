#include<bits/stdc++.h>
using namespace std;


int maxProfit(int len, int profit[1000])
{
	if(len==0)
		return 0;

	int dp[1000]={0};
	
	for(int i=1;i<=len;i++)
	{
		int best =-1;
		for(int j=1;j<=i;j++)
			best = max(best, profit[j]+dp[i-j]);
		dp[i]=best;
	}

	return dp[len];
}

int main()
{
	int len=4;
//	cin>>len;
	int profit[len];

//	for(int i=0;i<len;i++)
//		cin>>profit[i];

	profit[1]=2;
	profit[2]=3;
	profit[3]=2;
	profit[4]=5;
	
	cout<<"Maximum profit is : "<<maxProfit(len, profit);
}
