#include<iostream>
using namespace std;
int main()
{
	float maximum, A[1000];
	int N;
	
	cin>>N;

	for(int i=0;i<N;i++){
		cin>>A[i];
	}

	maximum=A[0];
	for(int i=1;i<N;i++)
		if(A[i]>maximum)
			maximum=A[i];

	cout<<maximum;

}