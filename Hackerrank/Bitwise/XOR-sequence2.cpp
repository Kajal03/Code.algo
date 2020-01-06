#include<iostream>
using namespace std;
#define ll long long
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll l,r,ans,result=0,i;
		cin>>l>>r;
		ans=0;
		for(i=1;i<=l;i++)
			ans = ans ^ i;
		result=ans;
		for(i=l+1;i<=r;i++)
		{
			ans = ans ^i;
			result = result ^ ans;
		}
		cout<<result<<endl;
	}

}

