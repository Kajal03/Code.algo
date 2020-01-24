/* You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from position (i,j), down or right on the grid.
Initially rat is on the position (1,1). It wants to reach position (N,M). Find the rightmost path through which, rat can reach this position. A path is rightmost, if the rat is at position (i,j), it will always move to (i,j+1), if there exists a path from (i,j+1) to (N,M).


*/


#include<iostream>
using namespace std;

bool findPath(char maze[1005][1005],int sol[1005][1005],int i, int j, int n, int m)
{
	if(i==n && j==m)
	{
		sol[i][j]=1;  //if reached last cell then solution found so print the solution found
		for(int row=0;row<=n;row++)
		{
			for(int col=0;col<=m;col++)
			{
				cout<<sol[row][col]<<" ";
			}
			cout<<endl;
		}
		
		return true;
	}

	if(i>n || j>m)
		return false;

	if(maze[i][j]=='X')
		return false;

	
	sol[i][j]=1;
	bool rightSuccess = findPath(maze,sol,i,j+1,n,m);
	bool downSuccess;
	if(rightSuccess)
		return true;
	
	else
	{
		downSuccess = findPath(maze, sol,i+1,j,n,m);
		
	}
	sol[i][j]=0; //undo your step during backtracking
	
	if(rightSuccess || downSuccess)
		return true;
	
	else 
		return false;
}

int main()
{
int sol[1005][1005]={0};

char maze[1005][1005];
int n,m;
cin>>n>>m;

for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		cin>>maze[i][j];

bool ans =findPath(maze,sol,0,0,n-1,m-1);
if(ans==false)  // if no solution found then print -1
    cout<<"-1";

}
