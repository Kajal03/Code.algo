#include<iostream>
using namespace std;
int main()
{
	int mat[100][100], size, temp,i,j,k;
	cin>>size;

	for(i=0;i<size;i++)
		for(j=0;j<size;j++)
			cin>>mat[i][j];

	//First operation that is taking transpose against the diagonal
	for(i=0;i<size;i++)
	{
		for(j=0;j<i;j++){
			if(i!=j){
				temp = mat[i][j];
				mat[i][j]= mat[j][i];
				mat[j][i]= temp;
			}
		}
	}

	//Second operation that is taking the mirror image of the matrix
		for(j=0,k=size-1;j<k;j++,k--){
		for(i=0;i<size;i++){
			//if(i!=j){
				temp = mat[i][j];
				mat[i][j]=mat[i][k];
				mat[i][k] = temp;

			//}
		}
	}


	cout<<endl;
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}