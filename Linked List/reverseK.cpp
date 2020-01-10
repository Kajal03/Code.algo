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

node* reverseK(node* head, int k)
{
	node* current =head;
	node *pc=NULL;
	node*N=NULL;
	int jumps=0;
	while(jumps<k && current!=NULL)
	{
		N = current->next;
		current->next = pc;
		pc = current;
		current = N;
		jumps++;
	}
	if(N!=NULL)
		head->next=reverseK(N,k);
	return pc;
}

int main()
{
	node* head=NULL;
	int n,k,i,d;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>d;
	insertAtTail(head,d);		
	}

	//print(head);
	//cout<<endl;
	head = reverseK(head,k);
	print(head);
}
