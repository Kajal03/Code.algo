#include<iostream>
#include<math.h>
using namespace std;

//given a no. we have to invert it's indivisual digits using 9-x such that
// the we get the highest resulting no. 
int main()
{
	long long int n,temp,result=0;
	int i=0,digit;
	cin>>n;
	temp=n;
	while(temp>0){
		digit = temp%10;
		temp/=10;
		if(temp<0 && digit==9)  //if the first digit is 9 then we cannot inc=vert it because else the no. of digits will reduce
			result+=digit*pow(10,i);
		else{
			digit = max(digit, 9-digit);
			result+=digit*pow(10,i);
			i++;
		}
	}
	cout<<result<<endl;
}