#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		if(q==1)
		{
			if(s.empty())
				cout<<"No Code\n";
			else
			{
				int d = s.top();
				s.pop();
				cout<<d<<endl;
			}
		}
		else
		{
			int d;
			cin>>d;
			s.push(d);
		}
	}
}
