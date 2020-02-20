#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.second < p2.second);
}

int main()
{
	unordered_map<int, int> mp;
	int n,count=0, temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		mp[temp]=count;
		count++;
	}

	vector<pair<int, int>> v;
	for(auto it=mp.begin(); it!=mp.end(); it++)
	{
		v.push_back(make_pair(it->first, it->second));
	}

	sort(v.begin(), v.end(), compare);
	
	for(auto it=v.begin();it!=v.end();it++)
	{
		cout<<it->first<<endl;
	}
}
