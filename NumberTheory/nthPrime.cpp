#include<iostream>
#include<math.h>
#include<cstring>
#include<bitset>
#define M INT32_MAX
#define ll unsigned long long
using namespace std;
int main(){
ll n,i,count,j;
bitset <M> primes;
for(i=0;i<M;i++)
primes[i]=1;
cin>>n;

primes[0]=primes[1]=0;
primes[2]=1;
for(i=4;i<M;i+=2)
	primes[i]=0;

for(i=3;i<M;i+=2)
{
	for(j=i*i;j<M;j+=i)
	{
		primes[j]=0;
	}
}

i=0;count=0;
while(count<n)
{	
	if(primes[i]==1)
		count++;
	i++;
}
cout<<i-1<<endl;

return 0;
}
