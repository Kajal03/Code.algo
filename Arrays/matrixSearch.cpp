//matrix search
#include<iostream>
using namespace std;

int main()
{
	int n,m, A[100][100],i,j,target;
	cin>>n>>m;
	for(i=0;i<n;i++){
	for(j=0;j<m;j++)
		cin>>A[i][j];
	}

	cin>>target;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(target==A[i][j]){
				cout<<"1";
				break;
			}
		}
	}
	if(i==n && j==m){
		cout<<"0";
	}
}