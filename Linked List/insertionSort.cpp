#include<iostream>
#include"myHeader.h"
using namespace std;

void sort(node* &head, node* temp)
{
	if(head==NULL || temp->data < head->data)
	{
		temp->next=head;
		head=temp;
		return;
	}
	node *current=head;
	while(current->next!=NULL && current->next->data < temp->data )
	{
		current = current->next;
	}
	temp->next=current->next;
	current->next=temp;
}

void insertionSort(node* &head)
{
	node* sorted=NULL;
	node* current=head;
	node* Next;
	while(current!=NULL)
	{
		Next = current->next;
		sort(sorted, current);
		current = Next;
	}
	head = sorted;
}

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

	insertionSort(head);
	print(head);
}
