//Sieve of eratosthenes
#include<iostream>
using namespace std;
#define ll long long int
int main()
{
	ll n,i,j,count,t;
	ll primes[1000000]={0};
	
	

	
	primes[0]=primes[1]=1;
	primes[2]=0;

    	for(i=4;i<=1000000;i+=2) //set all even nos. as composite
        	primes[i]=1;
    
	for(i=3;i<=1000000;i++)
	{	
		if(!primes[i]){
			for(j=i*i;j<=1000000;j+=2*i)
				primes[j]=1;
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>n;
		i=0,count=0;
		while(count<n){
			if(primes[i]==0)
				count++;
			i++;
		}
		cout<<i-1<<endl;
    	}
    
	
}
