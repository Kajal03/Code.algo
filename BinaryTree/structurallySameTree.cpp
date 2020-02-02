#include<queue>
#include<iostream>
using namespace std;
class node
{
   public:
	int data;
	node *left, *right;

	node(int d)
	{
		data = d;
		left=NULL;
		right = NULL;
	}
};

void BFSiterative(node* root)
{
	queue<node*> qu;
	qu.push(root);
	qu.push(NULL); // to mark a level is complete
	while(!qu.empty())
	{		
		node * temp = qu.front();
		if(temp==NULL)
		{
			cout<<endl;			
			qu.pop();
			if(!qu.empty())
				qu.push(NULL);
		}
		else
		{
			cout<<temp->data<<" ";
			qu.pop();
			if(temp->left)
				qu.push(temp->left);
			if(temp->right)
				qu.push(temp->right);
		}
	}
}

node* buildFromPreorder()
{
	int key;
	cin>>key;
	node* root = new node(key);
	string input;
	cin>>input;
	if(input=="true")
	{
		root->left = buildFromPreorder();
	}
	else
	{
		root->left = NULL;
	}

	cin>>input;
	if(input == "true")
	{
		root->right = buildFromPreorder();
	}
	else
	{
		root->right = NULL;
	}
	return root;
}

bool checkStructuallyIdentical(node* root1, node* root2)
{
	if(root1==NULL && root2==NULL)
		return true;

	if(root1!=NULL && root2!=NULL)
	{
		return (checkStructuallyIdentical(root1->left, root2->left) && checkStructuallyIdentical(root1->right, root2->right));
	}
	
	else
		return false;
}

bool checkIdentical(node* root1, node* root2)
{
	if(root1==NULL && root2==NULL)
		return true;

	if(root1!=NULL && root2!=NULL)
	{
		if(root1->data == root2->data)
			return checkIdentical(root1->left, root2->left) && checkIdentical(root1->right, root2->right);
		else
			return false;
	}
	return false; //when node is NULL and the other one is not
}



int main()
{
	node *root1 = buildFromPreorder();
	BFSiterative(root1);
	cout<<endl;
	node *root2 = buildFromPreorder();
	BFSiterative(root2);
	cout<<endl;

	cout<<checkStructuallyIdentical(root1, root2)<<endl;

	cout<<checkIdentical(root1, root2)<<endl;

}
