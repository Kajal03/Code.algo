/*A religious king wants to build the largest temple in his kingdom . To build the largest temple he needs to find the area of the largest suitable land . Given co-ordinates which denotes rivers flowing through the point horizontally as well as vertically , find the largest area possible to make the grand temple.
Input:
An integer n denoting number of co-ordinates followed by n co-ordinates

Output Format
Largest possible area to build the grand temple

Sample Input
3
1 1
2 4
5 2
Sample Output
2

*/

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
		if(X[i+1]-X[i]-1>max_X)
			max_X = X[i+1]-X[i]-1;
		
		if(Y[i+1]-Y[i]-1>max_Y)
			max_Y = Y[i+1]-Y[i]-1;
		
	}
	cout<<(max_X)*(max_Y)<<endl;

}
