#include<iostream>
#include<queue>
#include<math.h>

using namespace std;
typedef long long int ll;

ll calculateDistance(pair<ll, ll> p1)
{	
	return (p1.first*p1.first + p1.second*p1.second);
}

void checkK(priority_queue<ll> &pq, int k)
{
	if(pq.size()>k)
		pq.pop();
}

int main()
{
	priority_queue<ll> Kdistances;
	int k,queries;
	ll dis,type;
	cin>>queries>>k;
	pair<ll, ll> p;
	while(queries--)
	{
		cin>>type;
		switch(type)
		{
			case 1: cin>>p.first;
				cin>>p.second;
				dis = calculateDistance(p);
				Kdistances.push(dis);
				checkK(Kdistances,k);
				break;

			case 2: cout<<Kdistances.top()<<endl;
				break;
		};
	}

}
