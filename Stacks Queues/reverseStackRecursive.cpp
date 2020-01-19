#include<iostream>
#include<stack>
using namespace std;

void reverse(stack<int> &s1)
{
	if(s1.empty())
	{
		return;
	}

	int temp = s1.top();
	s1.pop();
	reverse(s1);
	s1.push(temp);
}

int main()
{

	int temp;
	stack<int> s1;
	for(int i=0;i<4;i++)
	{
		cin>>temp;
		s1.push(temp);
	}

	reverse(s1);

	for(int i=0;i<4;i++)
	{
		temp = s1.top();
		s1.pop();
		cout<<temp<<" ";
	}
}
