#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class node
{
    public:
	char data;
	int count;
	unordered_map<char, node*> children;
	bool terminal;
	node(char d)
	{
		data = d;
		count=1;	
	}
};

class Trie
{
   public:
	node* root;

	Trie()
	{
		root = new node('\0');	
	}
	
	void addWord(string word)
	{
		node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			char ch = word[i];
			if(temp->children.count(ch))
			{
				temp->count++;
				temp = temp ->children[ch];
			}
			else
			{
				node* n = new node(ch);
				temp->children[ch]=n;
				temp = n;
				//temp->count++;
			}
		}
		temp->terminal=true;
	}

	void findPrefixUtil(node* root, char tempString[], int index, vector<string> *result)
	{
		if(root==NULL)
			return;

		if(root->count==1)
		{
			tempString[index]='\0';
			//cout<<tempString<<endl;
			result->push_back(tempString);
			return;
		}
		
		for(int i=0;i<256;i++)
		{
			
			
			if(root->children[i]!=NULL)
			{
				tempString[index]=i;
				//cout<<tempString<<endl;
				findPrefixUtil(root->children[i],tempString, index+1, result);
			}
		}
	}

	vector<string> findUniquePrefix()
	{
		node* temp = root;
		char tempString[10000];
		vector<string> result;
		findPrefixUtil(temp, tempString, 0, &result);

		return result;
	}

};

int main()
{

	int n;
	Trie t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string input;
		cin>>input;
		t.addWord(input);
	}

	vector<string> result = t.findUniquePrefix();

	for(auto x:result)
	{
		cout<<x<<endl;
	}

	cout<<result.size()<<endl;
}












