#include<iostream>
#include<cstring>
using namespace std;
#define ll long long

int main()
{
	ll n,i,no,sum=0,prefix[1000005],ans=0;
	memset(prefix,0,sizeof(prefix));
	cin>>n;
	prefix[0]=1;
	for(i=0;i<n;i++){
		cin>>no;
		sum+=no;
		sum = sum%n;
		prefix[sum]++;
	}

    for(i=0;i<n;i++)
        cout<<prefix[i]<<" ";
	for(i=0;i<n;i++)
		ans += (prefix[i] * (prefix[i]-1))/2;

	cout<<endl<<ans;

}