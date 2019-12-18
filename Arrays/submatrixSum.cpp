// Sum of all submatrices of a given matrix
#include<iostream>
using namespace std;
int main()
{
	int rows, columns,i,j,sum=0,temp,A[100][100],n;

	cin>>n;
	rows=columns=n;

	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			A[i][j]=1;
			//cin>>A[i][j];
			

	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl<<endl;
/*	for(i=0;i<rows;i++)
	{
		for(j=0;j<columns;j++)
			cout<<A[i][j]<<" ";
		cout<<endl;
	}*/

	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			sum+=A[i][j]*(i+1)*(j+1)*(rows-i)*(columns-j);
		}
	}

	cout<<"Sum = "<<sum;

}