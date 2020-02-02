//You are given a sorted data of n integers. You have to form a balanced Binary Search Tree and then print preorder traversal of the tree.

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

void preorder(TreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

TreeNode* buildBalanced(int input[], int start, int end)
{
	if(start>end)
		return NULL;

	int mid = (start+end)/2;
	
	TreeNode* newNode = new TreeNode(input[mid]);
	newNode->left = buildBalanced(input, start, mid-1);
	newNode->right = buildBalanced(input, mid+1, end);
	
	return newNode;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int input[n];
		for(int i=0;i<n;i++)
			cin>>input[i];
		TreeNode* root = buildBalanced(input, 0, n-1);

		preorder(root);
		cout<<endl;
	}
}
