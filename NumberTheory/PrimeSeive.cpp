//Sieve of eratosthenes
//The Sieve of Eratosthenes uses an extra O(n) memory and its runtime complexity is O(n log log n)
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,j;
	ll primes[1000000]={0};
	
	cin>>n;

	// 0 - composite, 1- prime
	primes[0]=primes[1]=1;
	primes[2]=0;

    for(i=4;i<=n;i+=2) //set all even nos. as composite
        primes[i]=1;
    
	for(i=2;i<=n;i++)
	{	
		if(!primes[i]){
			for(j=i*i;j<=n;j+=2*i)
				primes[j]=1;
		}
	}

	for(i=0;i<n;i++)
		if(primes[i]==0)
		cout<<i<<" ";
	
}
