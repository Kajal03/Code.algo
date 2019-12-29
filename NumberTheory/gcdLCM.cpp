#include<iostream>
using namespace std;

int gcd(int a, int b){  //O(log(max(a,b)))
	if(b==0)
		return a;
	if(a<b)
		return gcd(b,a);
	else
		return gcd(b,a%b);
}

int lcm(int a, int b){
	//hcf x lcm = a x b
	int lcm = (a*b)/gcd(a,b);
	return lcm;
}

int main()
{
	int a,b;
	cin>>a>>b;

	cout<<gcd(a,b)<<endl;
	cout<<lcm(a,b);

}