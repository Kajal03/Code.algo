#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void shuffle(int a[], int n)
{
	int i=n-1,j;
	srand(time(NULL));
	
	for(;i>0;i--)
	{
		j = rand()%(i+1);
		swap(a[i],a[j]);
	}
}

int partition(int a[], int start, int end)
{
	int i=start-1, j=start, pivot=a[end];
	for(;j<end;j++)
	{
		if(a[j]<=pivot)
		{
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[end]);
	return i+1;

}

void quickSort(int a[], int start, int end)
{
	if(start>=end)
		return;
	
	int p = partition(a,start,end);
	quickSort(a,start,p-1);
	quickSort(a,p+1,end);
}

int main()
{
	int a[] = {1,2,8,4,5,6,7};
	int n=sizeof(a)/sizeof(int);
	
	shuffle(a,n);
	
	quickSort(a,0,n-1);
	

	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	
}
