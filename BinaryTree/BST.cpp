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

TreeNode* deleteInBST(TreeNode* root, int d)
{
	if(root==NULL)
	{
		return NULL;
	}
	else if(root->data > d)
	{
		root->left = deleteInBST(root->left,d);
		return root;
	}
	else if(root->data == d)
	{
		//3 cases possible
		//when leaf node is to be deleted
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			return NULL;
		}

		//when it has only one child
		if(root->left==NULL && root->right!=NULL)
		{
			TreeNode* temp = root->right;
			delete root;
			return temp;
		}
		if(root->left!=NULL && root->right==NULL)
		{
			TreeNode* temp = root->left;
			delete root;
			return temp;
		}

		//when it has both the children
		if(root->right!=NULL && root->left!=NULL)
		{	
			TreeNode* temp = root->right;
			while(temp->left!=NULL) //find the inorder successor in right subtree
			{
				temp= temp->left;
			}
			root->data = temp->data;
			root->right = deleteInBST(root->right, root->data);
			return root;
		}
	}
	else
	{
		root->right = deleteInBST(root->right, d);
		return root;
	}
}


bool checkBST(TreeNode* root, int lower=INT8_MIN, int higher = INT8_MAX)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->data >= lower && root->data <= higher && checkBST(root->left, lower, root->data) && checkBST(root->right, root->data, higher))
	{
		return true;
	}
	else
		return false;
}

class LinkedList
{
	public:
	TreeNode* head, *tail;
};

LinkedList flatten(TreeNode* root)
{
	LinkedList l;
	if(root==NULL) // can happen only if we paas en empty tree
	{
		l.tail = l.head =NULL;
		return l;
	}

	//3 cases arise
	//it is a leaf node
	if(root->left==NULL && root->right ==NULL)
	{
		l.head=l.tail=root;
		return l;
	}

	//if there is subtree on only one side
	if(root->left==NULL && root->right!=NULL)	
	{
		LinkedList rightLinkedList = flatten(root->right);
		l.head = root;
		root->right = rightLinkedList.head;
		l.tail = rightLinkedList.tail;
		return l;
	}
	if(root->left!=NULL && root->right==NULL)
	{
		LinkedList leftLinkedList = flatten(root->left);
		l.head = leftLinkedList.head;
		leftLinkedList.tail->right = root;
		l.tail = root;
		return l;
	}

	else
	{
		LinkedList leftLinkedList = flatten(root->left);
		LinkedList rightLinkedList = flatten(root->right);
		l.head = leftLinkedList.head;
		leftLinkedList.tail->right = root;
		root->right = rightLinkedList.head;
		l.tail = rightLinkedList.tail;
		return l;
	}
}

TreeNode* buildFromPreorder(int preorder[], int start, int end)
{
	if(start>end)
	{
		return NULL;
	}
	
	TreeNode* root = new TreeNode(preorder[start]);
	if(start==end)
	{
		return root;
	}

	int i=start+1;
	while(preorder[i]<root->data && i<=end)
	{
		i++;
	}
	root->left = buildFromPreorder(preorder,start+1,i-1);
	root->right = buildFromPreorder(preorder,i,end);
	return root;
}

//catlan no. - no. of BST = (2nCn)/(n+1)
// no. of bst = sumation over i (f(i-1) + f(n-i) )
//first term denotes no. of subtrees from left part, if we make ith node to be the root and right term denotes no. of subtrees made from right part

//no. of binary tree = n! * no. of BST
//bst gave us no. of structures, now we can arrange n numbers in those structures in n! ways

int main()
{
/*
	int input[] = {1,2,5,3,0,7,4};
	int n = sizeof(input)/sizeof(int);

	TreeNode* root=NULL;

	for(int i=0;i<n;i++)
	{
		root = insert(root,input[i]);		
	}

	BFSiterative(root);
	cout<<endl;

	root=deleteInBST(root,2);

	cout<<endl;
	BFSiterative(root);

	bool check = checkBST(root);
	cout<<endl<<check<<endl;


	LinkedList l = flatten(root);
	TreeNode* temp = l.head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->right;
	}
	cout<<endl;
*/

	int preorder[] ={10, 5, 1, 7, 40, 50};
	int n=sizeof(preorder)/sizeof(n);
	TreeNode* root = buildFromPreorder(preorder,0,n-1);
	BFSiterative(root);
	cout<<endl;
}
















