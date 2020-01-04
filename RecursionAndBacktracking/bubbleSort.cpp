#include<iostream>
using namespace std;

void bubbleSort(int a[], int j, int n)
{
	if(n==1)
		return;
	else if(j==n-1)
		return bubbleSort(a,0,n-1);
	else if(a[j]>a[j+1])
		swap(a[j],a[j+1]);
	
	bubbleSort(a,j+1,n);
}

int main()
{
int a[]={4,3,2,1},n=sizeof(a)/sizeof(int);
bubbleSort(a,0,n);

for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
}
