#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef long long int ll;
typedef pair<ll,pair<ll,ll>> customPair;

vector<ll> mergeSortedArrays(vector<vector<ll>> arr) //T(n) = O(nk log k)
{
	priority_queue<customPair,vector<customPair>, greater<customPair>> pq;
	vector<ll> result;
	for(ll i=0;i<arr.size();i++)
	{
		pq.push({arr[i][0],{i,0}});
	}
	while(!pq.empty())
	{
		customPair temp = pq.top();
		pq.pop();
		result.push_back(temp.first);
		ll array_no = temp.second.first;
		ll index = temp.second.second;
		if(index+1<arr[array_no].size())
		{
			pq.push({arr[array_no][index+1],{array_no,index+1}});
		}
	}
	return result;

}

int main()
{
	ll k,n,temp;
	cin>>k>>n;
	vector<vector<ll>> result;
	
	for(ll i = 0;i<k;i++)
	{
		vector<ll> arr;
		for(ll j = 0;j<n;j++)
		{
			cin>>temp;
			arr.push_back(temp);
		}
		result.push_back(arr);
	}

	vector<ll> result1 = mergeSortedArrays(result);
	for(auto i = result1.begin();i!=result1.end();i++)
		cout<<*i<<" ";
}
