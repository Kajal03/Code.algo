#include<iostream>
using namespace std;

bool isSafe(char board[][100],int i, int j, int n)
{
	//board[i][j]=1;

	for(int k=i-1;k>=0;k--)
	{
		if(board[k][j]==1)
			return false;
	}
	int row=i-1;
	int col=j+1;

	while(row>=0 && col<n)
	{
		if(board[row][col]==1)
			return false;
		row--;
		col++;
	}

	row=i-1;
	col=j-1;
	
	while(row>=0 && col>=0)
	{
		if(board[row][col]==1)
			return false;
		row--;
		col--;
	}
	return true;
}

bool solveNQueen(char board[][100], int row, int n)
{
	if(row==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(board[i][j]==1)
					cout<<"Q ";
				else
					cout<<"_ ";
			}
			cout<<endl;
		}
		cout<<endl;
		return false;
	}

	for(int j =0;j<n;j++)
	{
		
		if(isSafe(board,row,j,n))
		{	
			board[row][j]=1;
			if(solveNQueen(board,row+1,n))
			{
				return true;
			}	
			board[row][j]=0;
		}

	}
	return false;
	
}

int main()
{
	int n;
	cin>>n;
	char board[100][100]={0};
	bool ch = solveNQueen(board,0,n);
	

}
