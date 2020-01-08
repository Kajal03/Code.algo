#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,max=INT8_MAX,i;
	vector<int>result;
	cin>>n;
	int A[n];
	for(i=0;i<n;i++)
		cin>>A[i];
	sort(A,A+n);
	for(i=0;i<n-1;i++)
	{
		if(max>abs(A[i]-A[i+1]))
			max=abs(A[i]-A[i+1]);
	}
	for(i=0;i<n-1;i++)
	{
		if(abs(A[i]-A[i+1])==max)
		{
			result.push_back(A[i]);
			result.push_back(A[i+1]);
		}
	}
	for(auto x:result)
		cout<<x<<" ";
}
