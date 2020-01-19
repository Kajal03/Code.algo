#include<iostream>
using namespace std;

void findPermutations(char a[], int i)
{
	//Base Case
	if(a[i]=='\0')
	{
		cout<<a<<" ,";
		return;
	}

	//Recursive Case
	for(int j=i;a[j]!='\0';j++)
	{
		swap(a[i],a[j]);
		findPermutations(a,i+1);
		swap(a[j],a[i]);
	}
}

int main()
{
	char a[100];
	cin>>a;

	findPermutations(a,0);
}
