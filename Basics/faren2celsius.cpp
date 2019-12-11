/*Take the following as input.

Minimum Fahrenheit value
Maximum Fahrenheit value
Step

Print as output the Celsius conversions. Use the formula C = (5/9)(F – 32)*/


#include<iostream>
using namespace std;
int main()
{
	int min, max, step;
	float i;
	cin>>min>>max>>step;
	for(i=min; i<=max;i+=step){
		cout<<i<<" "<<(int)((5.0/9)*(i-32))<<endl;
	}
}