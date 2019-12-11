//Given a binary number ,help Von Neuman to find out its decimal representation. For eg 000111 in binary is 7 in decimal.
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int N,i,sum,remainder;
	long long int binary;
	cin>>N;
	while(N--){
		i = 0;
		sum = 0;
		cin>>binary;
		while(binary>0)
		{
			remainder = binary%10;
			sum += pow(2,i)*remainder;
			binary=binary/10;
			i++;
		}
		cout<<sum<<endl;
	}
}