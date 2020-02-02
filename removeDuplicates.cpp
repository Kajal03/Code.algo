//remove duplicates from a sorted array
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(2);
	int n = arr.size();

	int i=0,j,temp;

	for(j=1;j<n;j++)
	{
		if(arr[i]!=arr[j])
		{
			arr[i+1]=arr[j];
			i++;
		}
	}
	cout<<i+1<<endl;
}
