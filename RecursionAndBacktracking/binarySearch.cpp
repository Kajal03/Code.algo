#include<iostream>
using namespace std;

int binarySearch(int *A, int low, int high, int key)
{
	int mid=(low+high)/2;
	if(low>high)
		return -1;
	
	else if(A[mid]==key)
		return mid;
	else if(A[mid]<key)
		return binarySearch(A,mid+1,high,key);
	else if(A[mid]>key)
		return binarySearch(A,low,mid-1,key);
}

int main()
{
int A[]={1,2,3,4,5,6,7,8};
int n=sizeof(A)/sizeof(int), key = 8;
cout<<binarySearch(A,0,n-1,key)<<endl;
}
