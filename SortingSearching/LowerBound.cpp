#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
int n,t,temp,i,target;
vector<int>input;
cin>>n;
for(i=0;i<n;i++)
{
cin>>temp;
input.push_back(temp);
}

cin>>t;
while(t--)
{
	cin>>target;
	auto itr1 = lower_bound(input.begin(),input.end(),target);
	if(itr1==input.end())
	{
		cout<<"-1 -1\n";
		continue;
	}
	auto itr2 = upper_bound(input.begin(),input.end(),target);
	cout<<itr1-input.begin()<<" "<<itr2-input.begin()-1<<endl;
	
}

}

