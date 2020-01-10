
#include<iostream>
using namespace std;

class node
{
    public:
	int data;
	node* next;
	node(int d)
	{
		data = d;
		next = NULL;
	}

};

void insertAtHead(node* &head, int d)
{
	if(head==NULL)
	{
		head = new node(d);

		return;
		
	}	
		
	node * newNode = new node(d);
	newNode->next = head;
	head = newNode;
}

void insertAtTail(node* &head,int data)
{
	if(head==NULL)
	{
		//cout<<"done1";		
		insertAtHead(head,data);
		
		return;
	}

	node *n = new node(data);
	node *temp=head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
}
void print(node* head)
{
	
	while(head!=NULL)
	{
		cout<<(head->data)<<" -> ";
		head = head->next;
	}
	cout<<endl;
}

void KthNodeFromEnd(node *head,int k)
{
	node*fast=head;
	node* slow = head;
	while(k--)
	{
		fast=fast->next;
	}
	while(fast!=NULL)
	{
		fast=fast->next;
		slow=slow->next;
	}
	cout<<slow->data<<endl;
	
}


int main()
{
node* head=NULL;
int d;
cin>>d;
while(d!=-1)
{
	insertAtTail(head,d);
	cin>>d;
}
cin>>d;
KthNodeFromEnd(head,d);

}

















