/* Take as input S, a string. Write a function that returns the character with maximum frequency. 
Print the value returned.

*/

#include<iostream>
using namespace std;
int main()
{
	char A[100];
	int i=0,max=0;
	int B[100] = {0};

	cin>>A;

	while(A[i]!='\0'){
		B[A[i]-'a']++;
		i++;
	}

	for(i=1;i<26;i++){
		if(B[i]>B[max])
			max=i;
	}

	cout<<(char)('a' + max );



}