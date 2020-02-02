
#include<iostream>
#include<queue>
#include<map>
#include<utility>

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
	node* root=NULL;
	queue<node*> q;
	if(d!=-1)
	{
		root = new node(d);
		q.push(root);
	}
	while(!q.empty())
	{
		node* temp = q.front();
		q.pop();
		cin>>d;
		if(d!=-1)
		{
			node* leftChild = new node(d);
			temp->left = leftChild;
			q.push(leftChild);
		}
		else
			temp->left=NULL;
		cin>>d;
		if(d!=-1)
		{
			node* rightChild = new node(d);
			temp->right = rightChild;
			q.push(rightChild);
		}
		else
			temp->right = NULL;
	}
	return root;
}

void TopView(node* root)
{
	map<int,int> verticalLevels;
	queue<pair<node*, int>> q;
	
	pair<node*, int> p = make_pair(root,0);
	q.push(p);
	while(!q.empty())
	{
		pair<node*, int> temp = q.front();
		q.pop();
		if(verticalLevels.count(temp.second)==0)
			verticalLevels[temp.second]=(temp.first->data);
		if(temp.first->left!=NULL)
		{
			pair<node*, int> temp1 = make_pair(temp.first->left,temp.second-1);
			q.push(temp1);
		}
		if(temp.first->right!=NULL)
		{
			pair<node*, int> temp2 = make_pair(temp.first->right,temp.second+1);
			q.push(temp2);
		}
		
	}
	
	auto it = verticalLevels.begin();
	for (; it!=verticalLevels.end(); it++) 
    	{ 
        	cout<<it->second<<" ";
    	} 
	
}


void bottomView(node* root)
{
	map<int,int> verticalLevels;
	queue<pair<node*, int>> q;
	
	pair<node*, int> p = make_pair(root,0);
	q.push(p);
	while(!q.empty())
	{
		pair<node*, int> temp = q.front();
		q.pop();
		verticalLevels[temp.second]=(temp.first->data);
		if(temp.first->left!=NULL)
		{
			pair<node*, int> temp1 = make_pair(temp.first->left,temp.second-1);
			q.push(temp1);
		}
		if(temp.first->right!=NULL)
		{
			pair<node*, int> temp2 = make_pair(temp.first->right,temp.second+1);
			q.push(temp2);
		}
		
	}
	
	auto it = verticalLevels.begin();
	for (; it!=verticalLevels.end(); it++) 
    	{ 
        	cout<<it->second<<" ";
    	} 
	
}

int main()
{
	node* root = NULL;
	root = buildTree();

	bottomView(root);
}











