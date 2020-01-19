#include<iostream>
#include<list>
using namespace std;

class Queue
{
 list<int> q;
 int current_size=0;

 public:
	Queue()
	{
		current_size=0;
	}

	bool isempty()
	{
		return current_size==0;
	}

	void enqueue(int data)
	{
		q.push_back(data);
		current_size++;
	}

	void dequeue()
	{
		if(!isempty())
		q.pop_front();
		current_size--;
	}

	int getFront()
	{
		return q.front();
	}

};

int  main()
{
	Queue q;
	for(int i=0;i<5;i++)
		q.enqueue(i);

	cout<<q.getFront()<<endl;
	q.dequeue();
	cout<<q.getFront()<<endl;
}
