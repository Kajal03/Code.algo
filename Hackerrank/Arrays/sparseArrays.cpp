#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int main()
{
	int n,q,count,i,j;
	vector<string>A,queries;
	vector<int>result;
	cin>>n;
	
	string temp;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}

	cin>>q;
	for(i=0;i<q;i++)
	{
		cin>>temp;
		count=0;
		for(j=0;j<n;j++)
		{
			if(A[j]==temp)
				count++;
		}
		cout<<count<<endl;
	}
	

}
