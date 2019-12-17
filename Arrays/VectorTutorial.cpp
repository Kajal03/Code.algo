#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,temp,i,j;
	vector<int> A;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>temp;
		A.push_back(temp);

	}

	cout<<"\nArray before modification\n";
	for(i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	A.pop_back();

	cout<<"\nArray after modification\n";
	for(i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;	

}