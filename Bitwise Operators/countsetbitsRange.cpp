#include<iostream>
using namespace std;
int main()
{
	int q,a,b,ans;
	cin>>q;
	while(q--){
		ans=0;
		cin>>a>>b;
		while(a<=b){
			ans+=__builtin_popcount(a);
			a++;
		}
		cout<<ans<<endl;
	}
}