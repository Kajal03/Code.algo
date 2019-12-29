//Sieve of eratosthenes
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,j,count;
	ll primes[10000000]={0};
	
	cin>>n;

	// 0 - composite, 1- prime
	primes[0]=primes[1]=1;
	primes[2]=0;

    for(i=4;i<=100000000;i+=2) //set all even nos. as composite
        primes[i]=1;
    
	for(i=2;i<=10000000;i++)
	{	
		if(!primes[i]){
			for(j=i*i;j<=n;j+=2*i)
				primes[j]=1;
		}
	}

	i=0,count=0;
	while(count<n){
		if(primes[i]==0)
			count++;

		i++;
	}
	cout<<primes[i-1]<<endl;
	
}