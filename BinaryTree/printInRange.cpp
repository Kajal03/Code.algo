/*
PRINT BST KEYS IN THE GIVEN RANGE
You are given an array of integers. First of all , You have to form a binary search tree from given integers. Now you have provided two integers k1 and k2. You have to print all nodes of BST within the range k1 and k2 (including k1 and k2).

Input Format:
First line contains integer t as number of test cases. Each test case contains three lines. First line contains an integer n which is length of the array and second line contains n space separated integer. Third line contains the value of k1 and k2.

Constraints:
1 < t < 20 1 < n < 50

Output Format
For each test case you have to print preorder traversal of the tree first and then print all nodes within the range k1 and k2 (inclusive).

Sample Input
1
5
4 3 2 5 6
3 5

Sample Output
# Preorder : 4 3 2 5 6 
# Nodes within range are : 3 4 5 

*/

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

void preorder(TreeNode* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

TreeNode* inorder(TreeNode* root, int lower, int higher)
{
	if(root==NULL)
		return NULL;
	
	inorder(root->left,lower,higher);
	if(root->data<=higher && root->data>=lower)
		cout<<root->data<<" ";
	inorder(root->right,lower,higher);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,data,lower, higher;
		cin>>n;
		TreeNode *root=NULL; 
	
		for(int i=0;i<n;i++)
		{
			cin>>data;
			root = insert(root, data);
		}

		cin>>lower>>higher;
		
		cout<<"# Preorder : ";
		preorder(root);
		cout<<endl<<"# Nodes within range are : ";
		inorder(root,lower,higher);

	}
}










