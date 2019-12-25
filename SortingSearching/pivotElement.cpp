#include<iostream>
using namespace std;
int main(){
	int a[] = {1,2,3,4,5}, i,n = sizeof(a)/sizeof(int),end=n,start=0,mid,res;

	while(start<=end){
		mid = (start+end)/2;
		if(a[mid]<a[mid-1] && mid>start)
		{
			res=a[mid-1];
			break;
		}
		else if(a[mid]>a[mid+1] && mid<end)
		{
			res=a[mid];
			break;
		}
		else if(a[start]<a[mid] && a[mid]<a[end]){
			start=mid+1;
		}
		else{
			end=mid-1;
		}
	}
	if(start>end){
		cout<<"pivot element does not exit";
		return 0;
	}
	cout<<res<<endl;
}