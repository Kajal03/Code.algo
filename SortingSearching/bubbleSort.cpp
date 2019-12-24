//Bubble Sort

#include<iostream>
using namespace std;
int main()
{
	int n, input[100],i,j;
	cin>>n;
	
	for(i=0;i<n;i++)
		cin>>input[i];

	for(i=0;i<n;i++){
		for(j=0;j<n-1;j++){
			if(input[j]>input[j+1]){
				swap(input[j], input[j+1]);
			}
		}
	}

	for(i=0;i<n;i++)
		cout<<input[i]<<" ";
}