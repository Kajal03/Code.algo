#include<bits/stdc++.h>
using namespace std;

int subString(string input, int start, int end)
{
	int no = 0;
	for(int i = start;i<end;i++)
	{
		no *=10;
		no += input[i]-'0';
	}
	return no;
}

bool isValid(int start, int end, bool *visited)
{

	for(int i= start;i<end;i++)
	{
		if(visited[i])
			return false;
	}
	return true;

}

void markVisited(int start, int end, bool *visited)
{

	for(int i =start; i<end;i++)
	{
		visited[i] = true;
	}
}

bool isCB(int no)
{
	int cb[] = {2,3,5,7,11,13,17,19,23,29};
	if(no == 0 || no == 1)
		return false;

	for(int i=0;i<10;i++)
	{
		if(no==cb[i])
			return true;
	}

	for(int i = 0;i<10;i++)
	{
		if(no%cb[i]==0)
			return false;
	}

	return true;
}

int main()
{
	int n, count=0;
	cin>>n;
	string input;
	cin>>input;

	bool visited[n] = {0};
	
	for(int len = 1; len<=n;len++)
	{
		for(int i=0; i+len<=n; i++)
		{
			int end_index = i + len;
			int no = subString(input, i, end_index);
			
			if(isValid(i, end_index, visited) && isCB(no))
			{
				count++;
				markVisited(i, end_index, visited);
			}
		}
	}
	cout<<count<<endl;

}
