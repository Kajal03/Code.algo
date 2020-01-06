#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int main()
{
	ll t,i,r_max=-1,temp1,temp2;
	int temp;
	cin>>t;
	
	vector<int> a,l,r;
	a.push_back(0);

	for(i=0;i<t;i++)
	{
		cin>>temp1>>temp2;
		l.push_back(temp1);
		r.push_back(temp2);
		r_max = max(temp2,r_max);
	}
		
	for(i=1;i<=r_max;i++)
	{	
		temp=a[i-1]^i;
		a.push_back(temp);
	}
	ll count=0;
	while(t--)
	{	int ans=0,i;
		
		for(i=l[count];i<=r[count];i++)
			ans = ans ^ a[i];
		cout<<ans<<endl;
		count++;
	}
}
