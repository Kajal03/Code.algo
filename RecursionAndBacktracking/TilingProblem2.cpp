#include<iostream>
#include<math.h>
using namespace std;

int findTile(int n,int m){
	if(n==0)
		return 1;

	if(n<m)
		return 1;

	if(n==m)
		return 2;

	return findTile(n-1,m) + findTile(n-m,m);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N,M, result;
		cin>>N>>M;
	
		cout<<(findTile(N,M))%(1000000007)<<endl;
	}
}
