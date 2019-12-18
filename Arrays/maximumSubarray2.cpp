/* You are given a one dimensional array that may contain both positive 
and negative integers, find the sum of contiguous subarray of numbers which 
has the largest sum. For example, if the given array is {-2, -5, 6, -2, -3, 1, 5, -6},
 then the maximum subarray sum is 7.

 The first line consists of number of test cases T. Each test case consists of N followed by N integers.

*/


#include<iostream>
using namespace std;
int main()
{
	int n, maxSum, curSum, i, j,T;
	long long int A[100000000];
	cin>>T;
	while(T--){
		cin>>n;

		for(i=0;i<n;i++)
			cin>>A[i];

		maxSum=curSum=0;
		
		for(i=0;i<n;i++){
			curSum+=A[i];  //find the sum
			if(curSum<0)  // if it becomes negative then we will make it zero
				curSum=0;
			maxSum = max(curSum,maxSum);
		}

		cout<<maxSum<<endl;

	}
}