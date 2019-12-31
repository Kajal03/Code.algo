#include<iostream>
#include<math.h>
#include<cstring>
#define ll unsigned long long
using namespace std;
int main(){
ll n,i,count,j;
bool primes[INT32_MAX];
memset(primes,true,INT32_MAX);
cin>>n;

primes[0]=primes[1]=false;
primes[2]=true;
for(i=4;i<INT32_MAX;i+=2)
	primes[i]=false;

for(i=3;i<INT32_MAX;i+=2)
{
	for(j=i*i;j<INT32_MAX;j+=i)
	{
		primes[j]=false;
	}
}

i=0;count=0;
while(count<n)
{	
	if(primes[i]==true)
		count++;
	i++;
}
cout<<i-1<<endl;

return 0;
}
