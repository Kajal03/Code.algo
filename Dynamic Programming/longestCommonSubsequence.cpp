#include<bits/stdc++.h>
using namespace std;

int lcs(char X[], char Y[])
{
	int m = strlen(X);
	int n = strlen(Y);
	int dp[100][100];
	
	//base cases
	for(int i=0;i<=m;i++) dp[i][0]=0;
	for(int j=0;j<=n;j++) dp[0][j]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int q=0;
			if(X[i-1]==Y[j-1])
				q = 1 + dp[i-1][j-1];

			else
				q = max(dp[i-1][j], dp[i][j-1]);

			dp[i][j]=q;
		}
	}
	
	return dp[m][n];
}

int main()
{
	string s1 = "nematode";
	string s2 = "empty";
	char str1[100], str2[100];
	strcpy(str1,s1.c_str());

	strcpy(str2,s2.c_str());

	cout<<lcs(str1, str2)<<endl;
}
