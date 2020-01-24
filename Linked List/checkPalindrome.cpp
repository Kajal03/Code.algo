#include<iostream>
#include"myHeader.h"
using namespace std;
int main()
{
	node* head=NULL;
	int n,i,d,flag=0,jumps;
	cin>>n;
	for(i=0;i<n;i++)
	{	
		cin>>d;
		insertAtTail(head,d);
	}

	int l = len(head);
	
	if(l==1)
	{
		return true;
	}
	
	if(l==2)
	{
		if(head->data==head->next->data)
			return true;
		else
			return false;
	}
	

	node* head2=head;

	jumps = l/2;
	jumps--;
	while(jumps--)
	{	
		head2=head2->next;		
	}

	node* temp = head2->next;
	head2->next=NULL;

	if(l&1)
		head2 = temp->next;
	else
		head2 = temp;

	head2 = reverse(head2);
	
	node* temp1=head, *temp2=head2;

	while(temp1!= NULL || temp2!=NULL)
	{
		if(temp1->data!=temp2->data)
		{
			flag=1;
			break;
		}
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	flag? cout<<"False\n" : cout<<"True\n";
		
}
