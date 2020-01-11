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

node* even_after_odd(node*&head)
{
	node*even, *odd, *evenH=NULL, *oddH=NULL;
	int e=0,o=0;
	while(head!=NULL)
	{
		if(head->data&1)
		{
			if(!o)
			{
				oddH=head;
				odd=oddH;
				o++;
			}
			else
			{
				odd->next=head;
				odd=odd->next;
			}
			
		}
		else
		{
			if(!e)
			{
				evenH=head;
				even=evenH;
				e++;
			}
			else
			{
				even->next=head;
				even=even->next;
			}
		}
		head=head->next;
	}
	even->next=NULL;
	if(oddH==NULL)
		return evenH;
	else
		odd->next=evenH;
	return oddH;

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
	head = even_after_odd(head);
	print(head);
}

