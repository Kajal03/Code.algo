#include<iostream>
#include<queue>
#include<utility>  //for pair
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

int height(node* root)
{
	if(root==NULL)
		return 0;
	
	int left_tree = height(root->left);
	int right_tree = height(root->right);
	
	return max(left_tree, right_tree) + 1;
}

void printKthLevel(node* root, int k)
{
	if(root==NULL)
		return;
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}

	printKthLevel(root->left, k-1);
	printKthLevel(root->right, k-1);
}

void levelOrderPrint(node* root) // O(n^2)
{
	int ht = height(root);
	
	for(int i=1;i<=ht;i++)
	{
		printKthLevel(root, i);
		cout<<endl;
	}
}

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

int countNodes(node *root)
{
	if(root==NULL)
		return 0;

	return 1 + countNodes(root->left) + countNodes(root->right);
}

int sumNodes(node *root)
{
	if(root==NULL)
		return 0;

	return root->data + sumNodes(root->left) + sumNodes(root->right);
}

pair<int, int> optimisedDiameter(node* root)
{
	if(root==NULL)
	{
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int> p1, p2, p3;
	p1 = optimisedDiameter(root->left);
	p2 = optimisedDiameter(root->right);
	
	p3.first = p1.second + p2.second; //first contains diameter, seconds contains height
	p3.second = max(p1.second, p2.second) +1;
	
	p3.first = max(max(p3.first, p1.first), p2.first);

	return p3;
	
}

int diameter(node *root)
{
	if(root==NULL)
		return 0;
	
	int leftHeight = height(root->left);
	int rightHeight = height(root->right);
	int d1 = leftHeight + rightHeight;

	int d2 = diameter(root->left);
	int d3 = diameter(root->right);

	return max(max(d1, d2),d3);
}

int sumReplacement(node* root)
{
	if(root==NULL)
		return 0;

	if(!root->left && !root->right)
		return root->data;

	int temp = root->data;
	int leftSum = sumReplacement(root->left);
	int rightSum = sumReplacement(root->right);

	root->data = leftSum + rightSum;
	return (temp + leftSum + rightSum);
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

node* buildBalancedTree(int inputArray[], int start, int end)
{
	if(start>end)
		return NULL;

	int mid = (start+end)/2;

	node * newNode = new node(inputArray[mid]);
	newNode ->left = buildBalancedTree(inputArray, start, mid-1);
	newNode ->right = buildBalancedTree(inputArray, mid+1, end);

	return newNode;

}

int main()
{
//	node* root = NULL;
//	root = buildTree();
/*
	printPreorder(root);
	cout<<endl;
	printInorder(root);
	cout<<endl;
	printPostorder(root);
	cout<<endl;

	levelOrderPrint(root);

	BFSiterative(root);
	cout<<countNodes(root)<<endl;

	cout<<sumNodes(root)<<endl;

	cout<<diameter(root)<<endl;

	pair<int, int> p;
	p = optimisedDiameter(root);

	cout<<"Height of tree is "<<p.second<<endl;
	cout<<"Diameter of tree is "<<p.first<<endl;

	BFSiterative(root);
	sumReplacement(root);
	BFSiterative(root);


	checkBalanced(root)<0?cout<<"Not balanced\n" : cout<<"Balanced\n";
*/
	int inputArray[] = {1,2,3,4,5,6,7,8,9};
	int n= sizeof(inputArray)/sizeof(int);

	node *root = buildBalancedTree(inputArray, 0, n-1);

	BFSiterative(root);

}
