#include<iostream>
using namespace std;

void clearBit(int n, int i){
	int mask = ~(1<<i);
	n = n & mask;
	cout<<n;
	

}

void checkOdd(int n){
	n= n&1;
	if(n==1)
		cout<<"Odd";
	else
		cout<<"Even";
}

void setBit(int n, int i){
	int mask = 1<<i;
	n = n | mask;
	cout<<n;
}

void getBit(int n, int i){
	int mask = 1<<i;
	n = n & mask;
	if(n>0)
		cout<<"1";
	else
		cout<<"0";
}

void updateBit(int n, int i, int v){
	
	int mask = ~(1<<i);
	n = n & mask;
	n = n | (v<<i);
	cout<<n;
}

void cleariBits(int n,int i){
	int mask = (~0)<<(i);
	n = n & mask;
	cout<<n;
}

void clearRange(int n,int i, int j){
	int mask1 = (~0)<<i;
	int mask2 = ~((~0)<<j);
	mask1 = mask1 | mask2;
	n = n& mask1;
	cout<<n;
}

int main()
{
	int n=27, i=1;
	//clearBit(n,i);
	//checkOdd(n);
	//setBit(n,i);
	//getBit(n,i);
	//updateBit(n,i,0);
	//cleariBits(n,i);
	clearRange(n,4,1);
}