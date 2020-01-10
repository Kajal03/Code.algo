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
		cout<<(head->data)<<" ";
		head = head->next;
	}
	cout<<endl;
}

node* KthNodeFromEnd(node *head,int k)
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
	return slow;
	
}

int main()
{
	int n,i,d,k;
	
	node *head=NULL;
	
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>d;
		insertAtTail(head,d);
	
	}
	cin>>k;
	k=k%n;
	if(k==0 || k==n)
	{
		print(head);
		return 0;
	}
	
	node* slow = KthNodeFromEnd(head,k);
	node* current = head;
	while(current->next!=slow)
	{
		current = current->next;
	}
	current->next=NULL;
	node* temp = slow;
	
	while(slow->next!=NULL)
	{
		slow = slow->next;
	}
	slow->next= head;
	head=temp;

	print(head);


}














