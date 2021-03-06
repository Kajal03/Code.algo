/*You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. 
You need to find the maximum sum of consecutive number.

First line contains integer t which is number of test case. For each test case, 
it contains an integer n which is the size of numbers and next line contains n space separated integers.

 Here we can conclude that this algorithm works because it explains the fact the array's sum
could have been maximum if the minimum sum elements sum were not present so we should
exclude it.
*/

#include<iostream>
using namespace  std;

int kadane(int A[], int size){
	
	int curSum = 0, maxSum=0, i;
	
	for(i=0;i<size;i++){
		curSum+=A[i];
		if(curSum<0)
			curSum=0;
		maxSum = max(curSum,maxSum);
	}
	
	return maxSum;
}

int main()
{
	int n, A[1000],cumm=0,candidate1=0, candidate2=0,i,T;
	cin>>T;
	while(T--){
		cin>>n;
		cumm=0;
		for(i=0;i<n;i++)
			cin>>A[i];

		candidate1 = kadane(A,n);

		for(i=0;i<n;i++){
			cumm+=A[i];
			A[i]=-A[i];
		}
		candidate2 = cumm + kadane(A,n);

		cout<<max(candidate1,candidate2)<<endl;
	}

}