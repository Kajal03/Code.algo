#include<iostream>
using namespace std;

void search(int a[], int n, int target,int i)
{
	if(i==n)
		return;
	if(a[i]==target)
		cout<<i<<" ";
	search(a,n,target,i+1);

}

int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int m;
	cin>>m;

	search(a,n,m,0);
}
