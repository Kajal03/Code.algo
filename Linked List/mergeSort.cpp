#include<iostream>
using namespace std;

class node
{
	public :
	int data;
	node* next;
	
	node(int d)
	{
		next=NULL;
		data=d;
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



node* merge(node* a, node*b)
{
	if(a==NULL)
		return b;
	else if(b==NULL)
		return a;
	node *c;
	if(a->data < b->data)
	{
		c=a;
		c->next = merge(a->next,b);
	}
	else
	{
		c=b;
		c->next = merge(a,b->next);
	}
	return c;
}

node* midPoint(node* a)
{
	node*temp=a;
	while(a!=NULL && a->next!=NULL)
	{
		a = a->next->next;
		temp=temp->next;
	}
	return a;
}

node* mergeSort(node* a)
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

istream & operator>>(istream& is, node * a)
{
	int d;
	cin>>d;
	while(d!=-1)
	{
		insertAtTail(a,d);
		cin>>d;
	}
	return is;
}


ostream & operator<<(ostream &os, node* a)
{
	while(a->next!=NULL)
	{
		cout<<a->data<<" -> ";
		a=a->next;
	}
	cout<<a->data<<endl;
	return os;
	
}


int main()
{
	node* head1 = NULL;
	node* head2 = NULL;
	
	cin>>head1;
	head1 = mergeSort(head1);
	cout<<head1;
	
	
}
