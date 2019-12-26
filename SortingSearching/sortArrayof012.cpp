//Given an array of 0's, 1's amd 2's, sort the array efficiently

#include<iostream>
using namespace std;
int main()
{
	int a[100], n,i;
	cin>>n;
	int start=0,end=n-1;

	for(i=0;i<n;i++)
		cin>>a[i];

	i=0;
	while(i<=end){
		if(a[i]==0){ 
			swap(a[start],a[i]);
			start++; i++;

		}
		else if(a[i]==2){
			swap(a[i],a[end]);
			end--;
		}
		else if(a[i]==1)
			i++;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}