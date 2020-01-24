//Queue using stack
#include<iostream>
#include<stack>
using namespace std;

stack<int> pushStack, popStack;

class Queue
{
	public:
	void enqueue(int d)
	{
		pushStack.push(d);
	}

	int front()
	{
		if(!popStack.empty())
		{
			int d = popStack.top();
			//popStack.pop();
			return d;
		}
		else
		{
			while(!pushStack.empty())
			{
				int d = pushStack.top();
				pushStack.pop();
				popStack.push(d);
			}
			int d = popStack.top();
			//popStack.pop();
			return d;
		}
	}
	
	void dequeue()
	{
		if(!popStack.empty())
		{
			int d = popStack.top();
			popStack.pop();
			//return d;
		}
		else
		{
			while(!pushStack.empty())
			{
				int d = pushStack.top();
				pushStack.pop();
				popStack.push(d);
			}
			int d = popStack.top();
			popStack.pop();
			//return d;
		}
	}

};

int main()
{

	Queue q1;
	q1.enqueue(3);
	q1.enqueue(4);
	q1.dequeue();
	cout<<q1.front()<<endl;
	q1.enqueue(5);
	cout<<q1.front()<<endl;
//	cout<<q1.dequeue()<<endl;
}
