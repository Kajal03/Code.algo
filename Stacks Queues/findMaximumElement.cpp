//program to find the maximum element at every stage in O(1) time
//To do so, we will maintain one auxillary stack, the top of which will store the current maximum element in the stack

#include<iostream>
#include<stack>
using namespace std;

class Stack
{
	stack<int>primary_stack;
	stack<int>max_stack;

	public:

	void push(int d)
	{
		if(max_stack.empty() || d>=max_stack.top())
			max_stack.push(d);
		primary_stack.push(d);
	}
	
	void pop()
	{
		if(max_stack.top()==primary_stack.top())
			max_stack.pop();
		primary_stack.pop();
	}	

	int findMaxElement()
	{
		return max_stack.top();
	}

};

int main()
{
	Stack s;
	s.push(1);
	cout<<s.findMaxElement()<<endl;
	s.push(4);
	s.push(3);
	cout<<s.findMaxElement()<<endl;
	s.pop();
	s.pop();
	s.push(5);
	cout<<s.findMaxElement()<<endl;
}
