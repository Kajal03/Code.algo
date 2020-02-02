/*
FIND SUM AT LEVEL K
Take input of a generic tree using buildtree() function and also take input K the level at which we need to find the sum.

Input Format:
Take a generic tree input where you are first given the data of the node and then its no of children. The input is of preorder form and it is assured that the no of children will not exceed 2. The input of the tree is followed by a single integer K.

Constraints:
1 <= Nodes in tree <=1000
1<K<10

Output Format
A single line containing the sum at level K.

Sample Input
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2

Sample Output
20

*/

#include<iostream>
#include<queue>
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
	int noOfChildren;
	cin>>noOfChildren;
	if(noOfChildren==0)
		return root;
	
	root->left = buildFromPreorder();

	if(noOfChildren==2)
		root->right = buildFromPreorder();
	
	else
		root->right = NULL;
	
	return root;
}


int kthLevel(node* root, int k)
{
	if(root==NULL)
		return 0;
	if(k==0)
	{
		return root->data;
	}

	int s1 = kthLevel(root->left, k-1);
	int s2 = kthLevel(root->right, k-1);
	return s1+s2;
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


int main()
{
	node* root = NULL;
	root = buildFromPreorder();
	//BFSiterative(root);
	int level;
	cin>>level;

	int sum = kthLevel(root,level);
	cout<<sum<<endl;
}





