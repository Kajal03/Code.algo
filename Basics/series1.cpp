/*Take the following as input.

A number (N1)
A number (N2)
Write a function which prints first N1 terms of the series 3n + 2 which are not multiples of N2.*/


#include<iostream>
using namespace std;
int main()
{	
	int N1,N2,i,temp;
	cin>>N1>>N2;
	for(i=1;i<=N1;i++){
		temp = (3*i)+2;
		if(temp%N2!=0)
			cout<<temp<<endl;
		else
			N1++;
	}
}