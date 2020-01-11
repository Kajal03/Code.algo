#include<iostream>
#define ll long long
using namespace std;

void merge(ll a[], ll start,ll end)
{
	ll k=start,temp[100],i=start,mid = (start+end)/2,j=mid+1;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
			temp[k++]=a[i++];
		else if(a[i]>a[j])
			temp[k++] = a[j++];
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=end)
		temp[k++]=a[j++];
	
	for(i=start;i<=end;i++)
		a[i]=temp[i];

}

void mergeSort(ll a[], ll start, ll end)
{
	if(start==end)
		return;
	
	ll mid = (start+end)/2;

	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	merge(a,start,end);
}

int main()
{
ll n;
cin>>n;
ll a[n];
for(ll i=0;i<n;i++)
	cin>>a[i];
mergeSort(a,0,n-1);
for(ll i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}
