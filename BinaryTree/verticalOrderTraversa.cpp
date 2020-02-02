
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

class obj
{
	public:
	node* nodeData;
	int distance;
};

void verticalOrderTraversal(node* root)
{
	map<int,vector<int>> verticalLevels;
	queue<pair<node*, int>> q;
	
	pair<node*, int> p = make_pair(root,0);
	q.push(p);
	while(!q.empty())
	{
		pair<node*, int> temp = q.front();
		q.pop();
		verticalLevels[temp.second].push_back(temp.first->data);
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
        	for (int i=0; i<it->second.size(); ++i) 
        	    cout << it->second[i]<< " "; 
        	cout << endl; 
    	} 
	
}


int main()
{
	node* root = NULL;
	root = buildFromPreorder();
	//BFSiterative(root);

	verticalOrderTraversal(root);
}











