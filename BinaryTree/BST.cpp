#include<iostream>
#include<queue>
using namespace std;
class TreeNode
{
	public:
	int data;
	TreeNode *left, *right;

	TreeNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

TreeNode* insert(TreeNode* root, int d)
{

	if(root==NULL)
	{
		TreeNode* newNode = new TreeNode(d);
		return newNode;
	}

	if(root->data < d)
	{
		root->right = insert(root->right,d);
	}
	else
	{
		root->left = insert(root->left,d);
	}
	
	return root;	
}

TreeNode* inorder(TreeNode* root)
{
	if(root==NULL)
		return NULL;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

void BFSiterative(TreeNode* root)
{
	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);
	
	while(!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			if(!q.empty())
			{
				q.push(NULL);
			}
		}

		else
		{
			cout<<temp->data<<" ";
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}
	}
}

bool search(TreeNode* node, int d)
{
	if(node==NULL)
		return false;

	if(d==node->data)
		return true;

	if(d < node->data)
		return search(node->left, d);
	else
		return search(node->right, d);
}

int main()
{
	int input[] = {1,2,9,3,0,7,4};
	int n = sizeof(input)/sizeof(int);

	TreeNode* root=NULL;

	for(int i=0;i<n;i++)
	{
		root = insert(root,input[i]);		
	}

	BFSiterative(root);
	
	cout<<search(root, 5)<<endl;
}















