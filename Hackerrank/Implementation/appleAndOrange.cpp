#include<iostream>
using namespace std;
int main()
{
	int start,end,apple_tree,orange_tree,apple_queries,orange_queries,i,apple=0,orange=0;
	cin>>start>>end>>apple_tree>>orange_tree>>apple_queries>>orange_queries;
	int A[apple_queries],B[orange_queries];

	for(i=0;i<apple_queries;i++)
	{
		cin>>A[i];
		A[i]+=apple_tree;
		if(A[i]>=start && A[i]<=end)
			apple++;
	}

	for(i=0;i<orange_queries;i++)
	{
		cin>>B[i];
		B[i]+=orange_tree;
		if(B[i]>=start && B[i]<=end)
			orange++;
	}

	cout<<apple<<endl<<orange;



}
