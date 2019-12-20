#include<iostream>
using namespace std;

bool isPrime(int n){
	int i;
	if(n==0 || n==1)
		return false;
	for(i=2;i<=n/2;i++){
		if(n%i==0)
			break;
	}
	if(i>n/2)
		return true;
	else
		return false;
}

int main()
{
	int low, high, count,t;
	cin>>t;
	while(t--){
		cin>>low>>high;
		count=0;
		for(int i=low;i<=high;i++)
			if(isPrime(i))
				count++;
					
		cout<<count;
	}
}