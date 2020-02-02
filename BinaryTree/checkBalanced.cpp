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


int checkBalanced(node* root)
{
	if(root==NULL)
		return 0;

	int leftHeight = checkBalanced(root->left);
	int rightHeight = checkBalanced(root->right);

	if(leftHeight<0 || rightHeight<0 || (abs(leftHeight-rightHeight)>=2))
		return -3;

	return max(leftHeight, rightHeight) + 1;
}


int main()
{
	node *root = buildFromPreorder();
	int isBalanced = checkBalanced(root);
	if(root>0)
		cout<<"true";
	else
		cout<<"false";
}
