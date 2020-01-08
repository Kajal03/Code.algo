#include<iostream>
using namespace std;
#define ll long long
int main()
{
	ll size,operations,low,high,i,j,max=0,value;
	cin>>size>>operations;
	ll A[size]={0};
	for(i=0;i<operations;i++)
	{
		cin>>low>>high>>value;
		for(j=low-1;j<=high-1;j++)
		{
			A[j]+=value;
			if(max<A[j])
				max=A[j];
		}
	}
	for(i=0;i<size;i++)
	cout<<A[i]<<" ";

	cout<<max<<endl;
}
