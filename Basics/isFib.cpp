/* Take an element n and then check whether it is in the fibonacci series or not */
#include<iostream>
using namespace std;

int main()
{
	int n, sum=0,a = 0, b=1, c;
	cin>>n;
	while(sum<=n){
		sum = a+b;
		a=b;
		b=sum;
		if(sum==n){
			cout<<"Yes it is in fibonacci";
			break;
		}

	}
	if(sum>n){
		cout<<"It is not in fibonacci";
	}
}