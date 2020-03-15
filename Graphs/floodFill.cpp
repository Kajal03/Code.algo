#include<bits/stdc++.h>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

void printMatrix(char input [50][50], int row, int column)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
			cout<<input[i][j];
		cout<<endl;
	}
}



void floodFillAlgo(char input[50][50], int i, int j, char previous_char, char after_char, int row, int column)
{
	//base case
	if(i<0 || j<0 || i>=row || j>=column)
		return;

	if(input[i][j]!=previous_char)
		return;

	input[i][j] = after_char;
	for(int k=0;k<4;k++)
	{
		floodFillAlgo(input, i+dx[k], j+dy[k], previous_char, after_char, row, column);
	}
}

int main()
{
	int row,column;
	char input[50][50];

	cin>>row>>column;

	for(int i=0;i<row;i++)
		for(int j=0;j<column;j++)
			cin>>input[i][j];

	printMatrix(input, row,  column);

	cout<<endl<<endl;
	floodFillAlgo(input, 5, 11, '.', 'R',row, column);

	printMatrix(input, row, column);
}
