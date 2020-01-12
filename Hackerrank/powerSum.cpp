#include<iostream>
#include<math.h>
using namespace std;

int count=0;

void findSubset(int i,int sum, int n, int x)
{
	if(i==x)
		return;
	
	if(pow(i,n)+sum==x)
		count++;

	findSubset(i+1,sum,n,x);
	
	if((sum+pow(i,n))<=x)
	 	findSubset(i+1,sum+pow(i,n),n,x);	
}

int main()
{
	
	int n,x;
	cin>>x>>n;
	
	findSubset(1,0,n,x);
	cout<<count<<endl;
	
}
