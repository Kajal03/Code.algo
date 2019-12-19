//find efficiently a^b

#include<iostream>
using namespace std;

int power(int n, int i){
	
	if(i==1)
		return n;

	return n * power(n,i-1);
}

int main()
{
	int n,i;
	cin>>n>>i;

	cout<<power(n,i);

	return 0;
}