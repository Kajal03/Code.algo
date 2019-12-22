#include<iostream>
using namespace std;
int main()
{
	int n, A[100],key,mid,i,ans=-1;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];
	cin>>key;

	int start=0,end=n-1;
	while(start<=end){
		mid=(start+end)/2;
		if(A[start]<=A[mid]){   //Left part is sorted
			if(key==A[mid]){
				ans=mid;
				break;
			}
			
			if(key<A[mid] && key>A[start])
				end=mid-1;
			
			else
				start=mid+1;
		}

		//mid lies in the second line
		if(key>A[mid] && key<=A[end])
			start=mid+1;
		
		else
			end=mid-1;
		
	}

	cout<<ans;
}