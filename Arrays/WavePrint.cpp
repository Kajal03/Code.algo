// Take as input a two-d array. Wave print it column-wise.

#include<iostream>
using namespace std;
int main()
{
	int rows, columns, A[100][100], i,j;
	
	cin>>rows>>columns;
	for(i=0;i<rows;i++)
		for(j=0;j<columns;j++)
			cin>>A[i][j];
	
	j=0;
	while(j<columns){
		if(j%2==0)
		{	
			i=0;
			while(i<rows){
				cout<<A[i][j]<<", ";
				i++;
			}
		}

		else 
		{
			i=rows-1;
			while(i>=0){
				cout<<A[i][j]<<", ";
				i--;
			}
		}

		j++;
	}

	cout<<"END";

}