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
			jumps++;
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

void deleteAtTail(node *&head)
{
	if(head==NULL)
		return;
	else if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	else
	{	
		node * temp = head;
		node * head1 = head -> next;
		while(head1->next!=NULL)
		{
			temp = temp->next;
			head1 = head1->next;
		}
		delete head1;
		temp->next=NULL;
	}
	
}

void deleteAtHead(node* &head)
{
	if(head->next==NULL)
	{
		delete head;
		head=NULL;
	}
	if(head!=NULL)
	{
		node * temp=head->next;
		delete head;
		head=temp;
	}
}

void deleteInMiddle(node *&head, int pos)
{
	if(head==NULL || pos>len(head))
		return;
	else if(pos==1)
		deleteAtHead(head);
	else if(pos==len(head))
		deleteAtTail(head);
	else
	{	
		node * temp = head;
		int jumps=1;
		while(jumps<pos-1)
		{
			temp=temp->next;
			jumps++;
		}
		node *temp2 = temp->next;
		temp->next=temp2->next;
		delete temp2;
	}
}

istream& operator>>(istream &is, node *&head)
{
	int d;
	cin>>d;
	while(d!=-1)
	{
		insertAtTail(head,d);
		cin>>d;
	}
	return is;
}

ostream & operator<<(ostream &os, node* head)
{
	while(head!=NULL)
	{
		if(head->next!=NULL)
			cout<<head->data<<" -> ";
		else 
			cout<<head->data<<endl;
		head= head->next;
	}
	return os;
}

bool searchRecursive(node *head, int key)
{
	if(head==NULL)
		return false;
	else if(head->data==key)
		return true;
	else 
		return searchRecursive(head->next,key);
}

bool searchIterative(node * head, int key)
{
	while(head!=NULL)
	{
		if(head->data==key)
			return true;
		head = head->next;
	}
	return false;
}

void reverse(node *&head)
{
	node* current = head;
	node* previous = NULL;
	node* Next;
	
	while(current!=NULL)
	{
		Next = current->next;
		current->next=previous;
		previous=current;
		current=Next;
	}
	head = previous;
}

node* reverseRec(node* head)
{
	if(head->next==NULL || head==NULL)
		return head;
	node *smallHead = reverseRec(head->next);
	node *current = head;
	current->next->next = current;
	current->next=NULL;
	return smallHead;
}

node* midPoint(node* head)
{
	node*temp=head;
	while(head->next!=NULL && head->next->next!=NULL)
	{
		head = head->next->next;
		temp=temp->next;	
	}
	return temp;
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
		
}

node* mergeSort(node* &a)
{
	if(a==NULL || a->next==NULL)
		return a;
	
	//step 1: divide in two parts
	node* mid = midPoint(a);
	node *b = mid->next;
	mid->next =NULL;
	
	//step 2: sort both parts
	a = mergeSort(a);
	b=mergeSort(b);
	
	//step 3: merge both parts
	node*c = merge(a,b);
	return c;
}


int main()
{
	node *head=NULL;
	
/*	insertAtTail(head,2);
	insertAtHead(head,5);
	insertAtHead(head,6);
	insertAtHead(head,7);
	insertMiddle(head,8,3);
	cout<<head;

	cout<<len(head);
	deleteAtTail(head);
	print(head);
	deleteAtHead(head);
	print(head);
	deleteInMiddle(head,2);
	print(head);

	cin>>head;
	cout<<head;
	searchIterative(head,2)?cout<<"Yes\n": cout<<"No\n";
	searchRecursive(head,2)?cout<<"Yes\n": cout<<"No\n";

	cin>>head;
	reverse(head);
	cout<<head;

	head = reverseRec(head);
	cout<<head;
	midPoint(head);
*/
	node *head2=NULL;
	cin>>head;
	//cin>>head2;
	head = mergeSort(head);
	cout<<head;
	//KthNodeFromEnd(head,3);	
}
