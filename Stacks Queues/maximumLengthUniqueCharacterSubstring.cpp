#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int max_length=1, current_length=1,i;
	int index[256];

	for(i=0;i<256;i++)
		index[i]=-1;

	string a;
	cin>>a;
	
	index[a[0]]=0;


	for(i=1;a[i]!='\0';i++)
	{
		if(index[a[i]]==-1 || index[a[i]] < i - current_length)
		{
			current_length++;
		}
		else
		{
			current_length = i - index[a[i]] ;	
		}

		max_length =  max(max_length, current_length);
		index[a[i]]=i;
		
	}
	cout<<max_length<<endl;
}
