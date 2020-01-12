#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,sum=0;
		cin>>n;
		int a[n],sumL[n],sumR[n];
		for(i=0;i<n;i++)
			cin>>a[i];

		for(i=0;i<n;i++)
		{
			sum+=a[i];
			sumL[i]=sum;	
		}	
		
		sum=0;		
		for(i=n-1;i>=0;i--)
		{
			sum+=a[i];
			sumR[i]=sum;		
		}
		for(i=0;i<n;i++)
		{
			if(sumL[i]==sumR[i])
				break;
		}
		
		i==n?cout<<"NO\n":cout<<"YES\n";
		
	}	

}
