//Take N as input, Calculate it's reverse also Print the reverse.
#include<iostream>
using namespace std;
int main()
{
	long long int N;
	int remainder;
	cin>>N;
	while(N>0){
		remainder = N%10;
		cout<<remainder;
		N = N/10;
	}
}