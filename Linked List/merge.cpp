#include<iostream>
using namespace std;
#define ll long long

class node
{
    public:
	ll data;
	node* next;
	node(ll d)
	{
		data = d;
		next = NULL;
	}

};

void insertAtHead(node* &head, ll d)
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

void insertAtTail(node* &head,ll data)
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


node* merge(node* a, node* b)
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	node* c;
	if(a->data < b->data)
	{
		c = a;
		c ->next=merge(a->next,b);
	}
	else
	{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
		
}


void deleteList(node* &head)
{
	node* temp;
	while(head!=NULL)
	{
		temp=head;
		head=head->next;
		delete temp;	
	}
	
}

int main()
{
	ll n1,n2,i,d,t;
	cin>>t;
	while(t--)
	{
		node *head1=NULL;
		node *head2 = NULL;
		cin>>n1;
		for(i=0;i<n1;i++)
		{
			cin>>d;
			insertAtTail(head1,d);
	
		}
		cin>>n2;
		for(i=0;i<n2;i++)
		{
			cin>>d;
			insertAtTail(head2,d);
	
		}
		head1 = merge(head1,head2);

		print(head1);
		//deleteList(head1);
		
	}
	
}
