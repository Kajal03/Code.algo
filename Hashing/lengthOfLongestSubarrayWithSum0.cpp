//Length of longest subarray with sum = 0

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
	int arr[] = {1,2,-2,-1};
	int n=sizeof(arr)/sizeof(int), i, prefix_sum=0, j, max_len=0;

	unordered_map<int, int> m;
	for(i=0;i<n;i++)
	{
		prefix_sum+=arr[i];
		
		if(arr[i]==0 && max_len==0)
			max_len = 1;
		if(prefix_sum==0)
			max_len = max(i+1, max_len);
		else if(m.count(prefix_sum)==1)
			max_len = max((i - m[prefix_sum]), max_len);
		
		else
			m[prefix_sum]=i;
		
	}

	cout<<max_len<<endl;

}
