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

int len(node*head)
{
	int len=0;
	if(head==NULL)
		len=0;
	else
	{
		while(head!=NULL)
		{
			head = head->next;			
			len++;		
		}
	}
	return len;
}

void insertMiddle(node* &head, int data, int position)
{
	
	if(position==0 || head ==NULL)
		insertAtHead(head,data);
	else if(position>len(head))
		insertAtTail(head,data);
	else
	{	
		node *n = new node(data);
		node *temp = head;
		int jumps=1;
	
		while(jumps<position-1)
		{
			temp=temp->next;
		}
		n->next = temp->next;
		temp->next=n;
	}
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

int main()
{
	node *head=NULL;
	insertAtTail(head,2);
	insertAtHead(head,5);
	insertAtHead(head,2);
	insertAtHead(head,7);
	insertMiddle(head,8,2);
	print(head);
	cout<<len(head);
}
