//Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

#include<iostream>
using namespace std;
int main()
{
	int rows, columns, A[1002][1002], i, j, k, temp;
	cin>>rows;
	columns=rows;

	//Input
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			cin>>A[i][j];

	// taking the transpose along the diagonal
	for(i=0;i<rows;i++){
		for(j=0;j<i;j++){
			temp=A[i][j];
			A[i][j] = A[j][i];
			A[j][i]=temp;
		}
	}


	//swapping first and last column, secong and second to last column and so on...
	i=0; j=rows-1;
	while(i<j){
		k=0;
		while(k<columns){
			temp = A[i][k];
			A[i][k] = A[j][k];
			A[j][k] = temp;
			k++;
		}
		i++; j--;
	}


	//Output
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++)
			cout<<A[i][j]<<" ";

		cout<<endl;
	}

}
