#include<iostream>
using namespace std;

int lowerBound(int A[], int n, int key){
	int ans = -1, mid,start=0,end=n-1;
	while(start<=end){
		mid = (start+end)/2;
		if(key==A[mid]){
			ans = mid;      //even though we have found our key we will move in the left part to check 
			end = mid-1;	// for any other occurences of key , but will save our answer in some variable so that if we 
							//do not find our key this is first occrence only
		}
		if(key<A[mid]){
			end=mid-1;
		}
		if(key>A[mid]){
			start = mid+1;
		}
	}
	return ans;
}

int upperBound(int A[],int n, int key){
	int start=0,end=n-1,ans=-1,mid;
	while(start<=end){
		mid=(start+end)/2;
		if(key==A[mid]){   //even though we found key we will search in the right part to look for any other occurence of the key
			ans=mid;		//we will store our index in a variable so that if we do no find key, this will be the answer
			start=mid+1;
		}
		if(key>A[mid])
			start=mid+1;
		else
			end=mid-1;
	}
	return ans;
}


int main()
{
	int n,A[100],i,j,key,T;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>A[i];
	//cin>>T;
	//while(T--){
	cin>>key;

	int index = lowerBound(A,n,key);  //finding the fisrt occurence of the key
	cout<<index<<" ";

	index = upperBound(A,n,key);   //finding the last occurence of the key
	cout<<index<<endl;
	//}
}