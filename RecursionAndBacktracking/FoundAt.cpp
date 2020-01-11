#include<iostream>
#include<vector>
#define ll long long
using namespace std;

ll foundAt(vector<ll> A, ll n, ll target)
{
	if(n==-1)
		return -1;
	if(A[n]==target)
		return n;
	return foundAt(A,n-1,target);
}

int main()
{
	ll n,temp,i,result,target;
	vector<ll> A;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}
	cin>>target;
	result = foundAt(A,n-1,target);
	cout<<result<<endl;

}

