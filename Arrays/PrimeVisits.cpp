//Sieve of eratosthenes
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,j,a,b,count=0,t;
	ll primes[1000001]={0};


	// 1 - composite, 0- prime
	primes[0]=primes[1]=1;
	primes[2]=0;

    	for(i=4;i<=1000000;i+=2) //set all even nos. as composite
        	primes[i]=1;
    
	for(i=2;i<=1000000;i++)
	{	
		if(!primes[i]){
			for(j=i*i;j<=1000000;j+=2*i)
				primes[j]=1;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		count=0;

		for(i=a;i<=b;i++)
			if(primes[i]==0)
				count++;
		cout<<count<<endl;
	}
	
}
