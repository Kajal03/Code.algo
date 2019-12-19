//find efficiently a^b
// time complexity is O(log b)
#include<iostream>
using namespace std;

int power(int n, int i){
	
	if(i==1)
		return n;

	long long int a;

	a = power(n,i/2);
	
	if(i%2==0)
		return a*a;

	else
		return n*a*a;
}


int main()
{
	int n,i;
	long long int a;
	cin>>n>>i;

	a=power(n,i);

	cout<<a;

	return 0;
}