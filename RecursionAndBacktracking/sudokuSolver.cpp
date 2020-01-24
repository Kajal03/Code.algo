#include<iostream>
#include<cmath>
using namespace std;

bool canPlace(int maze[][1000], int i, int j, int n, int number)
{
	for(int row=0;row<n;row++)
	{
		//row nad column check
		if(maze[i][row]== number || maze[row][j]==number)
		{
			return false;
		}
	}

	int rn = sqrt(n);
	int sx = (i/rn)*rn;
	int sy= (j/rn)*rn;

	for(int x=sx;x<rn+sx;x++)
	{
		for(int y = sy;y<rn+sy;y++)
		{
			if(maze[x][y]==number)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int maze[][1000], int i, int j, int n)
{
	if(i==n)
	{
		for (int row=0;row<n;row++)
		{
			for(int col=0;col<n;col++)
				cout<<maze[row][col]<<" ";
			cout<<endl;	
		}
		return true;
	}

	if(j==n)
		return solveSudoku(maze,i+1,0,n);

	if(maze[i][j]!=0)
		return solveSudoku(maze,i,j+1,n);

	for(int number = 1;number<=n;number++)
	{
		if(canPlace(maze,i,j,n,number))
		{
			maze[i][j]=number;
			bool couldWeSolveForward = solveSudoku(maze,i,j+1,n);
			if(couldWeSolveForward)
			{
				return true;
			}
		}
	}	//we could not solve so we will backtrack
	
	maze[i][j]=0;
	return false;
}

int main()
{
	int n,i,j;	
	cin>>n;
	int maze[n][1000];
		/* = {{5, 3, 0, 0, 7, 0, 0, 0, 0}, 
			  {6, 0, 0, 1, 9, 5, 0, 0, 0}, 
			  {0, 9, 8, 0, 0, 0, 0, 6, 0}, 
			  {8, 0, 0, 0, 6, 0, 0, 0, 3}, 
			  {4, 0, 0, 8, 0, 3, 0, 0, 1}, 
			  {7, 0, 0, 0, 2, 0, 0, 0, 6},
			  {0, 6, 0, 0, 0, 0, 2, 8, 0}, 
			  {0, 0, 0, 4, 1, 9, 0, 0, 5}, 	
			  {0, 0, 0, 0, 8, 0, 0, 7, 9}};
		*/
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			cin>>maze[i][j];

	bool a = solveSudoku(maze,0,0,n);
}
