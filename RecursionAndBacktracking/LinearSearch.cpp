#include<iostream>
using namespace std;

void search(int *A, int n, int target)
{
	if(n==0 && A[n]!=target)
		cout<<-1<<endl;
		
	else if(A[n]==target)
		cout<<n<<endl;
	else
		search(A,n-1,target);
}

int main()
{
int A[] = {2,5,8,1,6,7};
int n= sizeof(A)/sizeof(int);

int target = 3;

search(A,n-1,target);
}
