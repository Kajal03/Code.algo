#include<iostream>
using namespace std;

void merge(int a[], int start,int end)
{
	int k=start,temp[100],i=start,mid = (start+end)/2,j=mid+1;
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

void mergeSort(int a[], int start, int end)
{
	if(start==end)
		return;
	
	int mid = (start+end)/2;

	mergeSort(a,start,mid);
	mergeSort(a,mid+1,end);
	merge(a,start,end);
}

int main()
{
int a[]={6,3,8,1,9,0,-2,7},n=sizeof(a)/sizeof(int);
mergeSort(a,0,n-1);
for(int i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}
