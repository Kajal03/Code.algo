//Fast exponentiation using Bitwise Operators
#include<iostream>
using namespace std;
int main()
{
	int a,n,ans=1,last_bit;
	cin>>a>>n;
	while(n>0){
		last_bit = n & 1;
		if(last_bit){
			ans *= a;
		}
		a*=a;
		n=n>>1;
	}

	cout<<ans;
}