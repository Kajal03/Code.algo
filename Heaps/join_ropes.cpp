#include<vector>
#include<iostream>
#include<queue>

using namespace std;

int join_ropes(int* ropes, int size)
{
	int cost = 0;
	priority_queue<int, vector<int>, greater<int>> p(ropes, ropes+size); //by default it is a max heap, so to make a min-heap we need 										     //comparitor function
	while(p.size()>1)
	{
		int first = p.top();
		p.pop();
		int second = p.top();
		p.pop();
		cost+=first+second;
		p.push(first+second);
	}
	return cost;
}

int main()
{
	int n;
	cin>>n;
	int ropes[n];
	for(int i=0;i<n;i++)
		cin>>ropes[i];

	int cost = join_ropes(ropes,n);
	cout<<cost<<endl;
}
