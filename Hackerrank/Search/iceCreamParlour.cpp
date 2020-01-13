#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,j,temp,money,flag=0;
		vector<int> a;
		cin>>money;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			a.push_back(temp);
		}

		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]+a[j]==money)
				{
					flag=1;
					break;
				}
			
			}
			if(flag)
				break;	
		}
		if(flag)
		cout<<i+1<<" "<<j+1<<endl;
		
	}
}
