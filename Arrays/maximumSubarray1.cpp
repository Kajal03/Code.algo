//Find the maximum sum subarray in O(n^2)

#include<iostream>
using namespace std;
int main()
{
	int A[1000],n,max,sum,i,j, first, last, cumSum[1000];
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>A[i];

	cumSum[0]=A[0];
	for(i=1;i<n;i++){
		cumSum[i]=cumSum[i-1]+A[i];
	}

	int currentSum=0;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(currentSum<cumSum[j]-cumSum[i])
				{
					currentSum=cumSum[j]-cumSum[i];
					first = i+1;
					last = j;
				}
		}
	}

	cout<<"\n Cummulative Sum is "<<currentSum<<endl;
	if(currentSum>0){
		cout<<"Subarray :-  ";
		for(i=first;i<=last;i++)
			cout<<A[i]<<" ";
		cout<<endl;
	}

}