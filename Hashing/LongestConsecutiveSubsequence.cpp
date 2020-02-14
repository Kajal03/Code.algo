//Longest consecutive subsequence
#include<iostream>
#include<unordered_set>

using namespace std;

int findSubsequenceLength(int *arr,int n)
{
	int count, x, max_len=0;
	unordered_set<int> mp;
	for(int i=0;i<n;i++)
		mp.insert(arr[i]);

	for(int i=0;i<n;i++)
	{
		if(mp.find(arr[i]-1)!=mp.end()) //if the no. itself is not a left boundary do nothing
		{
			continue;
		}
		else				//otherwise, assume it is a left boundary and then try to find its consecutive elements
		{
			count = 1;
			x=arr[i]+1;
			while(mp.find(x)!=mp.end())
			{
				count++;
				x++;
			}
			max_len = max(max_len, count);
		}
	}
	return max_len;
}

int main()
{

int arr[] = {4,5,1,2,6,3};
int n = sizeof(arr)/sizeof(int);

int length = findSubsequenceLength(arr,n);

cout<<length<<endl;
}
