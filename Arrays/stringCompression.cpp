/* Take as input S, a string. Write a function that does basic 
string compression. Print the value returned. E.g. for input 
“aaabbccds” print out a3b2c2d1s1.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	char A[100],d1;
	string d;
	vector<char> B;
	int i=0,diff,j,count;
	cin>>A;
	

	while(A[i]!='\0')
	{
		B.push_back(A[i]);
		count = 1;
		d1=A[i];
		
		i++;
		while(A[i]==d1){
			i++;
			count++;
		}
		d = to_string(count);
		j=0;
		while(d[j]!='\0'){
			B.push_back(d[j]);	
			j++;
		}
		
	}

	for(i=0;i<B.size();i++)
		cout<<B[i];

	return 0;
}