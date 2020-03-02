#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int input[n];
		for(int i=0;i<n;i++)
			cin>>input[i];

		int arr1[n], arr2[n];
		arr1[0]=1;
		for(int i=1;i<n;i++)
		{
			if(input[i]>=input[i-1])
			{
				arr1[i]=arr1[i-1]+1;
			}
			else
			{
				arr1[i]=1;
			}
		}
	
		arr2[n-1]=1;
		for(int i=n-2;i>=0;i--)
		{
			if(input[i]>=input[i+1])
			{
				arr2[i]=arr2[i+1]+1;
			}
			else
			{
				arr2[i]=1;
			}
		}

		int max_len = 0;
		for(int i=0;i<n;i++)
		{
			max_len = max(max_len, arr1[i]+arr2[i]-1);
		}
		cout<<max_len<<endl;
	}
}
