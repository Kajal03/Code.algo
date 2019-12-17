//Staircase Search

#include<iostream>
using namespace std;
int main()
{
	int A[100][100], rows, columns, i, j, key;
	cin>>rows>>columns;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)  //Input the matrix
			cin>>A[i][j];

	cin>>key;
	i=0;j=columns-1;   //start from top right corner
	while(i<rows && columns>0){     //loop until the ker=y is found or you have finished either column or rows
		if(A[i][j]==key){
			//cout<<"Found at position "<<i<<" "<<j;
			cout<<"1";
			break;
		}
		if(A[i+1][j]<=key){   //move like a staircase, always downward, and when not feasible to move downwards then move left
			i++;
		}
		else 
			j--;
	}
	if(i==rows || columns == -1)
		//cout<<"Not Found";
		cout<<"0";
}