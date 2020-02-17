#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n, sum=0;
		cin>>n;
		ll* costs = new ll[n];
		ll* minimum_petrol = new ll[n];
		
		ll min = LLONG_MAX;
		for(ll i=0;i<n;i++)
			cin>>costs[i];

		for(ll i=0;i<n;i++)
			cin>>minimum_petrol[i];


		for(ll i=0;i<n;i++)
		{

			if(costs[i]<min)
				min = costs[i];
			sum+= min*minimum_petrol[i];
		}
		cout<<sum<<endl;
	}
}
