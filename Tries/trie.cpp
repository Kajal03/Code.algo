#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

class Node
{
   public:
	bool terminal;
	char data;
	unordered_map<char, Node*> children;

	Node(char d)
	{
		data = d;
		terminal = false;
	}
};

class Trie
{
   public:
	Node* root;
	int count;

	Trie()
	{
		root = new Node('\0');  //the root is null
		count =0;
	}

	void addWord(string word)
	{
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			char ch = word[i];
			if(temp->children.count(ch)!=0)
			{
				temp = temp->children[ch];
			}
			else
			{
				
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
		count++;
	}

	bool searchWord(string word)
	{
		Node* temp = root;
		for(int i=0;i<word.size();i++)
		{
			char ch = word[i];
			if(temp->children.count(ch)!=0)
			{
				temp = temp->children[ch];
			}
			else
			{
				return false;
			}
		}
		return temp->terminal; //if it is teminal then return true else return false
	}
};

int main()
{
	Trie t;
	string word = "abc";
	t.addWord(word);
	cout<<t.searchWord("ab")<<endl;
}
