#include<iostream>
using namespace std;
int main()
{
	int n,A[1000], maxSum=0, curSum=0, i, j;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];

	for(i=0;i<n;i++){
		curSum+=A[i];  //find the sum
		if(curSum<0)  // if it becomes negative then we will make it zero
			curSum=0;
		maxSum = max(curSum,maxSum);
	}

	cout<<"Maximum sum is "<<maxSum<<endl;
}