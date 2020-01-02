#include<iostream>
using namespace std;

void fact(int n)
{
	int i,j, limit=1, carry, result, A[1000003];
	for(i=0;i<1000003;i++)
		A[i]=1;
	for(i=2;i<=n;i++)
	{
		j=0;
		while(j<limit)
		{
			result = (A[j] * i) + carry;
			A[j]=result%10;
			carry = result/10;
			j++;
		}
		if(carry>0)
		while(carry>0)
		{
			A[j]=carry%10;
			carry = carry/10;
			j++; limit++;
		}
	}
	for(i=limit-1;i>=0;i--)
		cout<<A[i];
	cout<<endl;
}


int main()
{
int n;
cin>>n;
fact(n);
}
