#include<iostream>
using namespace std;
int main()
{
	int n;
	int *p = new int[5];

	
	//creating 2D arrays using dynamic memory allocation
	int **q = new int *[5];

	for(int i=0;i<5;i++)
		q[i]=new int[4];

	for(int i=0;i<5;i++)
		delete [] q[i];

	delete [] q;
}