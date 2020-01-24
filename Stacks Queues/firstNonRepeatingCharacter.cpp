//First non-repeating character in a stream
#include<iostream>
#include<map>
#include<queue>
using namespace std;

int main()
{
	map<char,int> freq;
	queue<char> qu;
	char ch;
	cin>>ch;

	while(ch!='.')
	{
		freq[ch]++;
		qu.push(ch);
		while(!qu.empty())
		{
			if(freq[qu.front()]>1)
				qu.pop();
			else
			{
				cout<<qu.front()<<endl;
				break;
			}
		}
		if(qu.empty())
			cout<<"-1"<<endl;

		cin>>ch;
	}
}
