#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool myCompare(string A, string B)
{
	int i=0;
	if(A[i]!=B[i])
		return A[i]<B[i];
	while(A[i]==B[i])
	{
		i++;
	}
	if(A[i]=='\0')
		return false;
	if(B[i]=='\0')
		return true;
}

int main()
{
int n,i;
string temp;
cin>>n;
vector<string> A;

for(i=0;i<n;i++)
{
cin>>temp;
A.push_back(temp);
}

sort(A.begin(),A.end(),myCompare);

for(i=0;i<n;i++)
	cout<<A[i]<<endl;

}
