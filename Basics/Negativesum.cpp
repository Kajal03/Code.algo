//Given a list of numbers, stop processing input after the cumulative sum of all the input becomes negative.
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n, sum=0;
	while(sum>=0){
		cin>>n;
		sum+=n;
		if(sum>=0)
			cout<<n<<endl;
		else
			break;
	}
}