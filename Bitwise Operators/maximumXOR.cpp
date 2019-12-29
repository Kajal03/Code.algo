//We are given two coins of value x and y. We have to find the maximum of value of a XOR b where x <= a <= b <= y.
#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	int num = x^y,pos,i=1,result;
	while(num>0){
		if((num&1)==1){
			pos=i;
		}
		num=num>>1;
		i++;
	}
	result = ~((~0)<<pos);
	cout<<result;

}