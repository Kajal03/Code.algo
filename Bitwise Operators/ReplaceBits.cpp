#include<iostream>
using namespace std;

int clearRange(int n,int i, int j){
	int mask1 = (~0)<<i;
	int mask2 = ~((~0)<<j);
	mask1 = mask1 | mask2;
	n = n & mask1;
	return n;
}

int main()
{
	int N=15, M=2, i=1,j=3;
	//Output : 10001010100
	N = clearRange(N,j,i); //First clear that range
	M=M<<i;
	N = M | N; //then OR it with second number shifted left
	cout<<N;
}