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

node* buildTree()
{
	int d;
	cin>>d;
	
	if(d==-1)
		return NULL;
	
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void printPreorder(node* root)
{
	if(root==NULL)
		return;
	
	cout<<root->data<<" ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printPostorder(node* root)
{
	if(root==NULL)
		return;
	printPostorder(root->left);
	printPostorder(root->right);
	cout<<root->data<<" ";
}

void printInorder(node* root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}

int main()
{
	node* root = NULL;
	root = buildTree();
	printPreorder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPostorder(root);
	cout<<endl;

}
