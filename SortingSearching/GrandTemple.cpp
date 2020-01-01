#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int n,i,temp1,temp2,max_X=-1,max_Y=-1;
	vector<int>X,Y;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp1>>temp2;
		X.push_back(temp1);
		Y.push_back(temp2);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
	for(i=0;i<n-1;i++)
	{
		if(X[i+1]-X[i]>max_X)
			max_X = X[i+1]-X[i];
		
		if(Y[i+1]-Y[i]>max_Y)
			max_Y = Y[i+1]-Y[i];
		
	}
	cout<<max_X*max_Y<<endl;

}
