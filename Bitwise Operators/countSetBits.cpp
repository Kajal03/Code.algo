//Count the number of set bits in a number
#include<iostream>
using namespace std;

void countBits1(int n){
	int ans = 0;
	while(n>0){
		ans+= n & 1;
		n = n>>1;
	}
	cout<<ans<<endl;
}

void countBits2(int n){
	int ans = 0;
	while(n>0){
		n = n & (n-1);
		ans++;
	}
	cout<<ans<<endl;
}

int main()
{
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		cout<<__builtin_popcount(n)<<endl;	
	}
	//countBits1(n);
	//countBits2(n);
	

	return 0;
}