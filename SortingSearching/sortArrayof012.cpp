#include<iostream>
using namespace std;
int main()
{
	int a[]={0,0,1,1,1,2,2,2,2};
	int n=sizeof(a)/sizeof(int), start=0,end=n-1,i;

	i=0;
	while(a[i]==0)
	{
		start++;
	}
	i=end;
	while(a[i]==2){
		end--;
	}
	i=start+1;
	while(i<=end){
		if(a[i]==0){
			swap(a[start],a[i]);
			start++;

		}
		if(a[i]==2){
			swap(a[i],a[end]);
			end--;
		}
		if(a[i]==1)
			i++;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}