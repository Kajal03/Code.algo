#include<iostream>
using namespace std;
int main()
{
	int n,ans=0,temp,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		ans = ans ^ temp;
	}
	cout<<ans<<endl;
}
