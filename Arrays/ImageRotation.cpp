#include<iostream>
using namespace std;
int main()
{
	int rows,columns, input[1002][1002], output[1002][1002], i,j;
	cin>>rows;
	columns=rows;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			cin>>input[i][j];

	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			output[j][columns-i-1] = input[i][j];

	cout<<"The matrix rotated by 90 degrees clockwise is :\n";

	for(i=0;i<columns;i++)
		{
			for(j=0;j<rows;j++)
				cout<<output[i][j]<<" ";
		cout<<endl;
		}
		
}
