#include<iostream>
using namespace std;

bool isPalindrome(char *A, int i, int j)
{
	if(i==j || i==j-1){
		return true;
	}

	if(A[i]==A[j]){
		return isPalindrome(A,i+1,j-1);
	}

	if(A[i]!=A[j])
		return false;
}
int main()
{
	int n;
	char A[100];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];

	cout<<isPalindrome(A,0,n-1);


}