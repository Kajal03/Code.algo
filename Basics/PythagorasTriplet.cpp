#include<iostream>
using namespace std;
int main()
{
	long long int N;
	int m,n,side1,side2;
	cin>>N;
	if(N%2!=0){
		m = (N+1)/2;
		n = (N-1)/2;
		side1 = 2*m*n;
		side2 = m*m + n*n;
	}
	else{
		m = N/2;
		n = 1;
		side1 = m*m - 1;
		side2 = m*m + 1;
	}
	if((int)side1==side1 && (int)side2==side2 && side1!=0 && side2!=0)
		cout<<side1<<" "<<side2;
	else
		cout<<"-1";
}
