#include<iostream>
#include<vector>
using namespace std;
int func2(int a, int b)
{
	if(b==0)
		return a;
	if(b>a)
		return func2(b,a);
	return func2(a%b,b);
}
int func(int a,int b)
{
	int gcd = func2(a,b);
	return (a*b)/gcd;
}
int main()
{
int t;
cin>>t;
while(t--)
{
	int n, k,num,i,lcm=INT8_MAX;
	vector<int> A;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>num;
		A.push_back(num);
	}
	for(i=0;i<n;i++)
		lcm = min(lcm, func(A[i],k));
	cout<<lcm<<endl;
}
}
