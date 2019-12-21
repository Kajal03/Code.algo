//Inbuilt sort function
#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(int a, int b){
	return a>b;  //says that when a>b then return true
}

int main()
{
	int n,i,a[]={1,4,2,6,8,5};
	n = sizeof(a)/sizeof(int);

	//sort() uses randomized quick sort internally
	sort(a,a+n);  //[a,an+) which means last index is excluded

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;


	sort(a,a+n,myCompare); //we are passing a reference to the function and not calling it

	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}