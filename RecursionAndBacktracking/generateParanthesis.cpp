/* Given an integer 'n'. Print all the possible pairs of 'n' balanced parentheses.
The output strings should be printed in the sorted order considering '(' has higher value than ')'.
Print the balanced parentheses strings with every possible solution on new line.
*/

#include<iostream>
#include<cstring>
using namespace std;

void validP(vector<string> a, char* result, int i, int start, int end, int n)
{
	if(i==2*n)
	{
		result[i]='\0';
		a.push_back(result);
		return;
	}

	if(start < n)
	{
		result[i]='(';
		validP(result, i+1, start+1, end, n);
	}

	if((end<start) || (start==n && end<n))
	{
		result[i]=')';
		validP(result, i+1, start, end+1, n);
	}
}

int main()
{
	int n;
	cin>>n;
	char result[100];
	validP(result,0,0,0,n);	
}
