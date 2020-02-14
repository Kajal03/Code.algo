#include<iostream>
#include<math.h>

using namespace std;

class trieNode
{
  public:
	int data;
	trieNode* left; //carries 0
	trieNode* right; //carries 1

	trieNode(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}

};

void insert(trieNode* head, int number)
{
	trieNode* temp = head;
	for(int i=31;i>=0;i--)
	{
		int digit = (number >> i) & 1;
		if(digit==1)
		{
			if(temp->right!=NULL)
			{
				temp = temp->right;
			}
			else
			{
				trieNode* n = new trieNode(digit);
				temp->right = n;
				temp = n;
			}
		}
		else
		{
			if(temp->left!=NULL)
			{
				temp = temp->left;
			}
			else
			{
				trieNode* n = new trieNode(digit);
				temp->left = n;
				temp = n;
			}
		}
	}

}

int findMaxXOR(trieNode* head, int *arr, int size)
{
	int digit, number, max_xor=-1;
	for(int j=0;j<size;j++)
	{
		trieNode* temp = head;
		number = arr[j];
		int current_xor=0;
		if(temp->left==NULL && temp->right==NULL)
		{
			insert(temp, number);
		}
		else
		{
			for(int i=31; i>=0;i--)
			{
				digit = (number >> i) & 1;
				
				if(digit==1) //we need to find 0 which is left child
				{
					if(temp->left!=NULL) //that means we found 0, we will move towards it else we will move to right
					{
						current_xor += (int)pow(2,i);
						temp = temp->left;
						
					}
					else
					{
						temp = temp->right;
					}
				}
				else
				{
					if(temp->right!=NULL)
					{
						current_xor += (int)pow(2,i);
						temp = temp->right;
					}
					else
					{
						temp = temp->left;
					}
				}
			}
			max_xor = max(current_xor, max_xor);
			insert(head, number);
		}
	}
	return max_xor;
}

int main()
{
	trieNode* root = new trieNode('\0');
	int n;
	cin>>n;
	int arr[n];
	for(int i =0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<findMaxXOR(root, arr, n)<<endl;

}










