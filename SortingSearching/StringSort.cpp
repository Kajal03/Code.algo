/* Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool myCompare(string A, string B)
{
	int i=0;
	if(A[i]!=B[i])
		return A[i]<B[i];
	while(A[i]==B[i])
	{
		i++;
	}
	if(A[i]=='\0')
		return false;
	if(B[i]=='\0')
		return true;
	else
	        return A[i]<B[i];
}

int main()
{
int n,i;
string temp;
cin>>n;
vector<string> A;

for(i=0;i<n;i++)
{
cin>>temp;
A.push_back(temp);
}

sort(A.begin(),A.end(),myCompare);

for(i=0;i<n;i++)
	cout<<A[i]<<endl;

}
