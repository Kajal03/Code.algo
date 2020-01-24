//Stack using queue - pop efficient

#include<iostream>
#include<queue>
using namespace std;

class Stack
{
	queue<int> *primary, *secondary;
	
	public:
	
	Stack()
	{
		primary = new queue<int>();
		secondary = new queue<int>();
	}

	void push(int d)  //O(n)
	{
		secondary->push(d);
		while(!primary->empty())
		{
			secondary->push(primary->front());
			primary->pop();
		}
		swap(primary,secondary);

	}

	int top()
	{
		return primary->front();
	}

	void pop()   //O(1)
	{
		int d = primary->front();
		primary->pop();
	}
};

int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	cout<<s.top()<<endl;
	s.pop();
	cout<<s.top()<<endl;
}
