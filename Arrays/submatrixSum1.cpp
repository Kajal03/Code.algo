//Given n queries representing the top left and bottom right index of a matrix,we have to print the sum of that submatrix
#include<iostream>
using namespace std;
int main()
{
	int n, A[100][100],i,j,queries,B[100],rows,columns,sum,tl1,tl2,br1,br2;
	
	cin>>rows>>columns;

	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			cin>>A[i][j];

	cin>>queries;   //no. of queries

	for(i=0;i<queries*4;i++){  //4 cordinates for each query
		cin>>B[i];
	}


	for(i=0;i<rows;i++)    //adding column-wise
		for(j=1;j<columns;j++)
			A[i][j] += A[i][j-1];

	for(i=1;i<rows;i++)      //adding row-wise
		for(j=0;j<columns;j++)
			A[i][j] += A[i-1][j];


	for(i=0;i<=(queries*4)-4;i+=4){
		tl1=B[i]; tl2=B[i+1]; br1=B[i+2]; br2=B[i+3];
		if(tl1>0 && tl2>0)
			sum=A[br1][br2] - A[tl1-1][br2] - A[br1][tl2-1] + A[tl1-1][tl2-1];

		else if(tl1==0 && tl2==0)
			sum=A[br1][br2];

		else if(tl1==0)
			sum=A[br1][br2] - A[br1][tl2-1];

		else if(tl2==0)
			A[br1][br2] - A[tl1-1][br2];
		
		cout<<sum<<endl;
	}


}