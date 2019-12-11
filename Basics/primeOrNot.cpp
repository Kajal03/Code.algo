//Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".

#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=2;i<n/2 + 1;i++){
		if(n%i==0)
			break;
	}
	if(i==n/2 +1)
		cout<<"Prime";
	else
		cout<<"Not Prime";
	
}