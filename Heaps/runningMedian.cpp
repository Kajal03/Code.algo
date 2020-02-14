#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int main()
{
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	int i;
	cin>>i;
	while(i!=-1)
	{
		if(minHeap.size()==0)
		{
			minHeap.push(i);
			cout<<i<<endl;
		}
		else if(maxHeap.size()==0)
		{
			maxHeap.push(i);
			int temp = i + minHeap.top();
			cout<<endl<<temp/2.0<<endl;
			
		}
		else
		{
			if(i<maxHeap.top())
				maxHeap.push(i);
			else
				minHeap.push(i);

			if(((int)maxHeap.size()-(int)minHeap.size()) > 1)  //heap.size() returns unsigned int so when we subtract one unsigned 										   //int from another, the result changes.Therefore, we need to 									   //typecast it into int
			{
				int temp = maxHeap.top();
				maxHeap.pop();
				minHeap.push(temp);
			}
			else if(((int)minHeap.size() - (int)maxHeap.size())> 1)
			{
				int temp = minHeap.top();
				minHeap.pop();
				maxHeap.push(temp);
			}

			if((minHeap.size() + maxHeap.size()) % 2 ==1)
			{
				int temp = minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
				cout<<endl<<temp<<endl;
			}
			else
			{	
				int temp = minHeap.top() + maxHeap.top();
				cout<<endl<<temp/2.0<<endl;
			}
		
		}
		cin>>i;
	}

}
