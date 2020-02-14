#include<iostream>
using namespace std;

class node
{
	public:
		string key;
		int value;
		node* next;
	
		node(string k, int v)
		{
			key = k;
			value = v;	
		}

		~node()
		{
			if(next!=NULL)
				delete next;	
		}
};

class HashTable
{
	int cs;
	int ts;
	node** buckets;

	int hashFunc(string key)
	{
		int ans =0, p=1;
		int L = key.length();
		for(int i=0;i<L;i++)
		{
			ans+=key[L-i+1]*p;
			p = p*37;
			p=p%ts;
			ans = ans%ts;
		}
		return ans;
	}
	
	public:
	HashTable(int defaultSize=7)
	{
		cs =0;
		ts = defaultSize;
		buckets = new node*[ts];
		for(int i=0;i<ts;i++)
		{
			buckets[i]=NULL;
		}
	}

	void rehash()
	{
		cs = 0;
		int oldts = ts;
		ts = ts*2;
		node** oldBucket = buckets;
		buckets = new node*[ts];

		for(int i=0;i<ts;i++)
		{
			buckets[i]=NULL;
		}

		for(int i=0;i<oldts;i++)
		{
			node* temp = oldBucket[i];
			if(temp!=NULL)
			{
				while(temp!=NULL)
				{
					insert(temp->key, temp->value);
					temp = temp->next;
				}
				delete oldBucket[i];
			}
		}
		delete [] oldBucket;
	}

	void insert(string key, int value)
	{
		int hash = hashFunc(key);
		node *newNode = new node(key, value);
		newNode->next = buckets[hash];
		buckets[hash] = newNode;
		
		cs++;

		float load_factor = (float) cs/ts;
		if(load_factor>0.7)
		{
			rehash();
		}
	}

	void print()
	{
		for(int i=0;i<ts;i++)
		{
			node* temp = buckets[i];
			cout<<"bucket "<<i<<" ";
			while(temp!=NULL)
			{
				cout<<temp->key<<",";
				temp=temp->next;
			}
			cout<<endl;
		}
	}
	
	int* search(string key)
	{
		int h = hashFunc(key);
		node* temp = buckets[h];
		while(temp!=NULL)
		{
			if(temp->key == key)
				return &(temp->value);
			temp = temp->next;
		}
		return NULL;
	}
	
};



















