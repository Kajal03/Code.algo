//Counting sort
#include<iostream>
using namespace std;
int main()
{
	int n,a[1000000],i,j,k=0,freq[1000000]={0};
	cin>>n;

	for(i=0;i<n;i++)
		cin>>a[i];

	for(i=0;i<n;i++)
	{
		freq[a[i]]++;
	}

	for(i=0;i<1000000;i++){
		while(freq[i]>0){
			a[k]=i;
			k++;
			freq[i]--;
		}
	}

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}