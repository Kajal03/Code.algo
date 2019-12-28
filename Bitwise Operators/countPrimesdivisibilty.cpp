//find out number of numbers between 1 to n which are divisible by any of the primes less than 20

#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ll t,n,no,result,i,ans,pos,denom,setBits;
	int primes[]={2,3,5,7,11,13,17,19};
	cin>>t;
	
	while(t--){
		cin>>n;
		no=(1<<8)-1;  //generates all subsets
		result=0;
		for(i=1;i<=no;i++){
			ans=i;
			pos=0;
			denom=1;
			setBits=__builtin_popcount(i);
			while(ans>0){
				if((ans&1)==1)
					denom *= primes[pos];
				pos++;
				ans=ans>>1;
			}
			if(setBits%2==0) 
				result-=(n/denom);  //for principle of inclusion and exclusion
			else
				result+=(n/denom);
		}
		cout<<result<<endl;

	}
}