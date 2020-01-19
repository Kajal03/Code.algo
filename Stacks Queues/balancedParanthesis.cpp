#include<iostream>
#include<stack>
using namespace std;

bool checkBalanced(string input)
{
	int len= input.length();
	stack<int> s1;
	for(int i=0;i<len;i++)
	{
		if(input[i]=='(')
			s1.push('(');
		if(input[i]==')')
		{
			if(s1.size()==0 || s.top()!='(')
				return false;
			else
			{
				s1.pop();
			}
		}
	}
	if(s1.size()==0)
		return true;
	else
		return false;
}

int main()
{
	string input;
	getline(cin,input);
	
	checkBalanced(input)? cout<<"Yes\n" : cout<<"No\n";
	
}
