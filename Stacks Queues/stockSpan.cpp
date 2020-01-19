#include<iostream>
#include<stack>
using namespace std;

void findAns(int stock[], int n)
{
	int ans[n],i,currentPrice;
	stack<int> s1;
	for(i=0;i<n;i++)
	{
		currentPrice = stock[i];
		while(s1.empty() == false && stock[s1.top()]<currentPrice)	
		{
			s1.pop();
		}
		int betterDay = s1.empty() ? 0 : s1.top();
		int span = i - betterDay;
		ans[i]=span;
		s1.push(i);
			
	}
	for(i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}

int main()
{
	int stock[]={100,80,60,70,60,75,85};
	int n=sizeof(stock)/sizeof(int);

	findAns(stock,n);

}
