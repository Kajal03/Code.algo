/* Given a floor of size 4 x N. Find the number of ways to tile the floor with tiles of size 4 x 1.
A tile can either be placed horizontally or vertically.*/

#include<iostream>
using namespace std;

int findTile(int n){
	if(n==0)
		return 1;

	if(n<=3)
		return 1;

	if(n==4)
		return 2;

	return findTile(n-1) + findTile(n-2);
}

int main()
{
	int N, result;
	cin>>N;

	result = findTile(N);

	cout<<result;
}