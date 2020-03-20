#include<bits/stdc++.h>
using namespace std;

int minCost(int grid[100][100], int row, int column)
{
	int dp[100][100];
	
	dp[0][0] = grid[0][0];

	for(int i=1;i<row;i++)
		dp[0][i] = dp[0][i-1] + grid[0][i];

	for(int i=1;i<column;i++)
		dp[i][0] = dp[i-1][0] + grid[i][0];

	for(int i=1;i<row;i++)
	{
		for(int j=1;j<column;j++)
		{
			dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
		}
	}

	return dp[row-1][column-1];
}

int main()
{
	int grid[100][100] = {{1,2,3},{4,8,2},{1,5,3}};

	int ans = minCost(grid,3,3);

	cout<<ans<<endl;
}
