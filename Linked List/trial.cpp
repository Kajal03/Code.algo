#include<iostream>
#include"myHeader.h"
using namespace std;
int main()
{
	int n,d,i;
	node *head=NULL;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>d;
		insertAtTail(head,d);
	}
}
