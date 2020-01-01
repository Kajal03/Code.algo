#include<ostream>
using namespace std;

int foundAt(int *A, int n, int target,int i=0)
{
	if(n==1 && A[0]!=target)
		return -1;
	else if(n==1 && A[0]==target)
		return n;
}

int main()
{
	int n,temp,i,result,target;
	vector<int> A;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}
	cin>>target;
	result = foundAt(A,n,target);
	cout<<result;

}

