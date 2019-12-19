/* Take as input S, a string. Write a program that inserts between each pair of 
characters the difference between their ascii codes and print the ans.
Input: abc
Output: a2c-1b
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	char A[100];
	string d;
	vector<char> B;
	int i=0,diff,j;
	cin>>A;
	B.push_back(A[i]);

	while(A[i+1]!='\0')
	{
		diff=A[i+1]-A[i];
		d = to_string(diff);
		j=0;
		while(d[j]!='\0'){
			B.push_back(d[i]);	
			j++;
		}
		
		B.push_back(A[i+1]);
		i++;
	}

	for(i=0;i<B.size();i++)
		cout<<B[i];

	return 0;
}