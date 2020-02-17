#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n,temp;
	cin>>n;
	vector<int> result;
	int arr[n];
	map<int, int> mp;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		mp[arr[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(mp.count(temp)!=0 && mp[temp]>0)
		{
			result.push_back(temp);
			mp[temp]--;
		}
	}
	sort(result.begin(), result.end());
	cout<<"[";
	int i;
	for(i=0;i<result.size()-1;i++)
		cout<<result[i]<<", ";
	cout<<result[i]<<"]";

}
