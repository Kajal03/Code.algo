#include<iostream>
#include"myHeader.h"
using namespace std;

bool exists(node* head, int d)
{
	while(head!=NULL)
	{
		if(head->data==d)
			return true;
		head = head->next;
	}
	return false;
}

node* createCycle(node* head)
{
	int d,flag=0;
	cin>>d;
	
	while(d!=-1)
	{
		insertAtTail(head,d);
		cin>>d;
		if(exists(head,d))
		{
			flag=1;
			break;
		}
	}
	if(flag)
	{
		node* temp=head;
		while(temp->data != d)
		{
			temp=temp->next;
		}
		
		if(temp->next==NULL)
		{
			temp->next=temp;
			return head;
		}
		node* p=temp->next;
		
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=temp;
	}
	
	return head;

}

void detectCycle(node* head)
{
	node* slow=head->next, *fast=head->next->next;
	while(fast!=slow)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	fast=head;
	
	if(slow==head)
	{
		while(fast->next!=head)
		{
			fast=fast->next;
		}
		fast->next=NULL;
		return;
	}	

	while(fast->next!=slow->next)
	{
		fast=fast->next;
		slow=slow->next;

	}
	slow->next=NULL;
	
}

int main()
{
	int n1, n2,i,j,A[100],alen=0,flag=0,d;
	
	node* head=NULL;
	
	head = createCycle(head);
	
	detectCycle(head);
	print(head);
	
}












