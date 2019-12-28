#include<iostream>
using namespace std;
int main()
{
	int n,i=1,ans=0;
	cin>>n;
	while(n>0){
		ans += (n&1) *i; //if the last bit is 1 we will add it to our answer 
		n=n>>1;
		i*=10;
	}
	cout<<ans;
}