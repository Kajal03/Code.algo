//Minimum window substring 
#include<iostream>
using namespace std;
int main()
{
	string input, pattern;
	cin>>input>>pattern;

	int min_len=0, start=0, count=0, start_index=0;
	int hash_str[256]={0};
	int hash_pattern[256]={0};
	for(int i=0;i<pattern.length();i++)
		hash_pattern[pattern[i]]++;

	for(int i=0;i<input.length();i++)
	{
		hash_str[input[i]]++;
		if(hash_pattern[input[i]]!=0 && hash_pattern[input[i]]>=hash_str[input[i]])
			count++;

		if(count==pattern.length())
		{
			while(hash_str[start]>hash_pattern[input[start]] || hash_pattern[input[start]]==0)
			{
				if(hash_str[input[start]]>hash_pattern[input[start]])
					hash_str[start]--;				
				start++;
			}
			if(min_len>count)
			{
				start_index =start;
				min_len = count;
			}
		}
	}
	//for(int i=start; i<start+min_len;i++)
	//	cout<<input[i];
	cout<<input.substr(start, min_len);
	cout<<endl;
}
