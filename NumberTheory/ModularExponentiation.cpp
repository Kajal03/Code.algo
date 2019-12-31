//Given three numbers a,b,c. Calculate (a^b)mod c.

#include<iostream>
#include<math.h>
using namespace std;
int main() {
	long long int a,b,c,temp;
	cin>>a>>b>>c;
	if(b==1)
	{
		cout<<a%c<<endl;
		return 0;
	}
	if(b%2==1){
		temp=a;
		b--;
	}
	else
		temp=1;

	while(b>0){
		temp *=a;
		temp%=c;
		b--;
	}
	if(c==1)
	cout<<"0";
	else
	cout<<temp;
}

