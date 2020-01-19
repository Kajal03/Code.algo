#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class Stack
{
	queue<int> *q1, *q2;
	public:
		Stack()
		{
			q1 = new queue<int>();
			q2 = new queue<int>();
		}
		void push(int data)
		{
			q1->push(data);	
		}

		T top()
		{
			int n=q1->size();
			n--;
			while(n--)
			{
				q2->push(q1->front());
				q1->pop();
			}
			int x=q1->front();
			q2->push(x);
			
			swap(q1,q2);
			return x;
		}
		void pop()
		{
			int n=q1->size();
			n--;
			while(n--)
			{
				q2->push(q1->front());
				q1->pop();
			}
			
			q1->pop();
			swap(q1,q2);
			
		}
};

int main()
{

	Stack<int> s1;
	s1.push(1);
	s1.push(2);
	//s1.push(3);
	cout<<s1.top()<<endl;
	s1.pop();
	cout<<s1.top()<<endl;

}
