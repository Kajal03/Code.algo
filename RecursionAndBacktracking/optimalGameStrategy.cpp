#include<iostream>
using namespace std;

int findMaxWin(int start, int end, int coins[])
{
	if(start==end)
	{
		return coins[start];
	}
	
	if(start+1==end)
	{
		return max(coins[start], coins[end]);
	}


	int option1 = coins[end] + min(findMaxWin(start+1, end-1,coins), findMaxWin(start,end-2,coins));
	int option2 = coins[start] + min(findMaxWin(start+2, end, coins), findMaxWin(start+1, end-1, coins));
	
	return max(option1, option2);
	
}

int main()
{
	int n;
	cin>>n;
	bool Piyush = true;
	int coins[n], value=0;
	for(int i=0;i<n;i++)
		cin>>coins[i];
	cout<<findMaxWin(0,n-1,coins)<<endl;
	
}
