/*You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.
1<=T<=10
1<=N<=10^15 
1<=K<=10^4
*/

#include<iostream>
#include<math.h>
using namespace std;
#define ll unsigned long long
int main()
{
int t;
cin>>t;
while(t--)
{
	ll n,k,start,end,mid,temp,ans;
	cin>>n>>k;
	start=0; end = (n/k)+1; 
	while(start<=end)
	{
		mid = (start+end)/2;
		if(pow(mid,k)==n)
		{
			ans= mid;
			cout<<mid<<"mid"<<endl;
			break;
		}
		if(pow(mid,k)<n)
		{
			ans = mid;
			start=mid+1;
		}
		else
			end=mid-1;
		
	}
	cout<<ans<<endl;


}


}
