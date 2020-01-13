#include<iostream>
#include<stack>
using namespace std;


void transfer(stack<int> &s1, stack<int> &s2, int n)
{
	for(int i=0;i<n;i++)
	{
		int x=s1.top();
		s1.pop();
		s2.push(x);
	}
}

void reverse(stack<int> &s1)
{
	stack<int>s2;
	for(int i=0;i<s1.size();i++)
	{
		int x=s1.top();
		s1.pop();
		transfer(s1,s2,s1.size()-i-1);
		s1.push(x);
		transfer(s2,s1,s2.size());
		
	}

}

int main()
{
	stack<int> s1;
	for(int i=0;i<4;i++)
		s1.push(i);

	reverse(s1);

	for(int i=0;i<4;i++)
	{
		cout<<s1.top()<<" ";
		s1.pop();
	}
	
}
