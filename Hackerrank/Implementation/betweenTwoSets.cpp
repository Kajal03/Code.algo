#include<iostream>
using namespace std;
int main()
{
	int n,m,i,maximum=INT8_MAX,flag,j,count=0;
	cin>>n>>m;
	int A[n], B[m];
	for(i=0;i<n;i++)
		cin>>A[i];
	
	for(i=0;i<m;i++)
	{
		cin>>B[i];
		maximum=min(maximum,B[i]);
	}

	for(i=1;i<=maximum;i++)
	{
		flag=0;		
		for(j=0;j<n;j++)
		{
			if(i%A[j]!=0)
			{
				flag=1;
				break;
			}		
			if(flag==1)
				break;		
		}
		for(j=0;j<m;j++)
		{
			if(B[j]%i!=0)
			{
				flag=1;
				break;
			}
			if(flag==1)
				break;
		}
		if(flag==0)
			count++;
	}
	cout<<count<<endl;

}
