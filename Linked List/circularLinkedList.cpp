#include<iostream>
using namespace std;

class node
{	
	public:
	int data;
	node* next;

	node(int d)
	{
		next=NULL;
		data = d;
	}
};

void insert(node*& head, int d)
{
	if(head==NULL)
	{
		head =new node(d);
		head->next=head;
		return;
	}

	node *temp = new node(d);
	node *temp2 = head;
	temp->next=head;
	while(temp2->next!=head)
	{
		temp2 = temp2->next;
	}
	temp2->next=temp;
	temp=head;
}

void print(node* head)
{
	node* temp = head;
	while(temp->next!=head)
	{
		cout<<temp->data<<" -> ";
		temp = temp->next;
	}
	cout<<temp->data<<endl;
}

int main()
{
	node* head=NULL;
	insert(head,2);
	//insert(head,3);
	//insert(head,4);
	print(head);
}
