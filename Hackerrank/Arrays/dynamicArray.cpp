#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n,q,i,j,a,x,y,lastAnswer=0,seq,size1;
	cin>>n>>q;
	vector<vector<int>> A(n);

	for(i=0;i<q;i++)
	{
		cin>>a>>x>>y;
		seq = (x^lastAnswer)%n;
		if(a==1)
			A[seq].push_back(y);
			
		else
		{
			size1 = y%(A[seq].size());
			lastAnswer=A[seq][size1];
			cout<<lastAnswer<<endl;
		}
			
	}
}
