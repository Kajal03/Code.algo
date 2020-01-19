#include<iostream>
using namespace std;
int main()
{
	int row,column,i,j,startCol,startRow,endCol,endRow;
	cin>>row>>column;
	int a[row][column];
	startRow=0;
	startCol=0;
	endRow=row-1;
	endCol=column-1;

	int value=1;
	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			a[i][j]=value;
			value++;
		}
	}

	for(i=0;i<row;i++)
	{
		for(j=0;j<column;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}

	while(startRow<=endRow && startCol<=endCol)
	{
		for(i=startRow;i<=endRow;i++)
			cout<<a[i][startCol]<<" ";
		startCol++;
		
		if(startCol<=endCol)
		{
			for(i=startCol;i<=endCol;i++)
				cout<<a[endRow][i]<<" ";
			endRow++;
		}

		if(startCol<=endCol)
		{
			for(i=endRow;i>=startRow;i--)
				cout<<a[i][endCol]<<" ";
			endCol--;
		}
	
		if(startCol<=endCol)
		{
			for(i=endCol;i>=startCol;i--)
				cout<<a[startRow][i]<<" ";
			startRow++;
		}
		
	
	}
}











