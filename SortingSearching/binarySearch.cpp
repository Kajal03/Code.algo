//binary search

#include<iostream>
using namespace std;

int binarySearch(int A[], int end, int key){
	
	while(start<=end){
		int mid = (start + end)/2;

		if(key==A[mid])
			return mid;

		if(key<A[mid])
			end = mid-1;

		else
			start = mid+1;
	}
	return -1;
	
}

int main()
{
	int A[100],n,i,key;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];

	cin>>key;
	int index = binarySearch(A,n-1,key);

	cout<<index;
}