#include<bits/stdc++.h>
using namespace std;


void naiveSearch(string input, string pattern)
//time complexity - O(nm), O(n)

{
	for(int i=0;i<=input.size() - pattern.size();i++)
	{
		int j;
		for(j=0;j<pattern.size();j++)
		{
			if(input[i+j]!=pattern[j])
				break;
		}
		
		if(j==pattern.size())
			cout<<"Pattern found at "<<i<<endl;
	}
}

int main()
{
	string input = "aabaacaadaabaaabaa";
	string pattern = "aaba";

	naiveSearch(input, pattern);
}
