//Given a matrix that is row-wise and column-wise sorted, find the submatrix with the highest sum

#include<iostream>
using namespace std;
int main()
{
	int rows,columns,max_sum,i,j,top_left_row,top_left_col,A[100][100];
	cin>>rows>>columns;


	//filling the matrix
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			cin>>A[i][j];


//creating a suffix matrix
	//column-wise addition
	for(i=rows-1;i>=0;i--){
		for(j=columns-2;j>=0;j--){
			A[i][j]+=A[i][j+1];
		}
	}

	//row-wise addition
	for(j=columns-1;j>=0;j--){
		for(i=rows-2;i>=0;i--){
			A[i][j]+=A[i+1][j];
		}
	}


	//finding the maximum sum matrix using modifications in staircase search
	max_sum=A[rows-1][columns-1];
	i=j=0;
	while(i<rows && j<columns){
		if(A[i][j]>max_sum){
			max_sum=A[i][j];
			top_left_row=i;
			top_left_col=j;
			continue;
		}

		else if(max_sum>A[i+1][j] && max_sum>A[i][j+1])
		{
			i++;
			j++;
		}

		else if(A[i+1][j]>A[i][j+1]){
			i++;
		}
		else
			j++;
	}

	cout<<endl<<"("<<top_left_row<<","<<top_left_col<<") ";
	cout<<"("<<rows-1<<","<<columns-1<<")";

	
}