#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];

		int sumL=sumR=0,i=-1,j=n;
		while(j-i>2)
		{
			if(sumL<sumR)
			{
				i++;
				sumL+=a[i];	
			}
			else
			{
				j--;
				sumR+=a[j];
			}
		}
		cout<< (sumL==sumR)? "YES\n" : "NO\n";
		
	}	

}
