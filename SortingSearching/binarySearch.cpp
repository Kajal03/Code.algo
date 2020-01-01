#include<iostream>
#include<vector>
#define ll long long
using namespace std;

ll binarySearch(vector<ll> A, ll n, ll target)
{
	ll start=0,end=n-1,mid;
	while(start<=end)
	{
		mid = (start+end)/2;
		if(A[mid]==target)
			return mid;
		if(A[mid]<target)
			start=mid+1;
		if(A[mid]>target)
			end = mid-1;
	}
	return -1;
	
}

int main()
{
ll n,i,temp,target;
vector<ll> input;
cin>>n;
for(i=0;i<n;i++)
{
cin>>temp;
input.push_back(temp);
}
cin>>target;
temp = binarySearch(input,n,target);
cout<<temp;
}

