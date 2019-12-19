// multiply two nos. without using multiplication operator

#include<iostream>
using namespace std;

int multiply(int a, int b){
	if(b==1)
		return a;

	if(b==0 || a==0)
		return 0;

	if(a<0 && b<0)
		return multiply(-a,-b);

	if(b>0)
		return a + multiply(a,b-1);

	if(b<0)
		return b + multiply(b,a-1);
}

int main()
{
	int a,b;
	cin>>a>>b;
	cout<<multiply(a,b);
}