/*Heaps

In 0-based indexing
Left Child = i*2 + 1
Right Child = i*2 + 2
Parent = floor((i-1)/2)

In 1-based indexing
Left Child = 2*i
Right Child 2* i + 1
Parent = i/2
*/

/* time complexity of heap sort is O(n log n). But the constants that are ignored in big o natation in heap sort are larger than
merge sort or quick sort. So, after experimental analysis we conclude that heap sort is slow.*/

#include<iostream>
#include<vector>
using namespace std;


void upheapify(vector<int> &max_heap, int index)
{
	if(index==0)
		return;
	
	if(max_heap[(index-1)/2] < max_heap[index])
	{
		int temp = max_heap[index];
		max_heap[index] = max_heap[(index-1)/2];
		max_heap[(index-1)/2] = temp;
		upheapify(max_heap, (index-1)/2);
	}
	else
		return;
}

void insert(vector<int> &max_heap, int key)
{
	max_heap.push_back(key);
	upheapify(max_heap, max_heap.size()-1);
}

void downheapify(vector<int> &max_heap, int index)
{
	int leftChild = index*2 + 1;
	int rightChild = index*2 + 2;

	if(leftChild>=max_heap.size()) //no children
		return;

	if(rightChild>=max_heap.size()) //no right child but has left child
	{
		if(max_heap[index]<max_heap[leftChild])	
		{
			swap(max_heap[leftChild],max_heap[index]);
			downheapify(max_heap,leftChild);
		}
	}
	else //both children exists
	{
		int i = max_heap[leftChild] > max_heap[rightChild] ? leftChild : rightChild;
		if(max_heap[index]<max_heap[i])
		{
			swap(max_heap[index], max_heap[i]);
			downheapify(max_heap, i);
		}
	}
}

void delete_peak(vector<int> &max_heap)
{
	swap(max_heap[0],max_heap[max_heap.size()-1]);
	max_heap.pop_back();
	downheapify(max_heap, 0);
}

void display(vector<int> &max_heap)
{
	for(int i=0;i<max_heap.size();i++)
		cout<<max_heap[i]<<" ";
	cout<<endl;
}

void deleteAtIndex(vector<int> &max_heap, int index)
{
	if(index>=max_heap.size())
		return;

	int temp = max_heap[index];
	max_heap[index] = INT8_MAX;
	upheapify(max_heap, index);
	delete_peak(max_heap);
	
}

void buildHeap(vector<int> max_heap)
{
	for(int i=max_heap.size()/2;i>=0;i--)
	{
		downheapify(max_heap, i);
	}
}

int main()
{
	vector<int> max_heap;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		max_heap.push_back(temp);

	}
	buildHeap(max_heap);

	display(max_heap);
/*	for(int i=0;i<n;i++)
	{
		delete_peak(max_heap);
		display(max_heap);
	}
*/
	deleteAtIndex(max_heap, 0);
	display(max_heap);
}
