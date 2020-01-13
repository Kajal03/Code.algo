#include<iostream>
using namespace std;

template<typename T>
class Queue
{
	T *arr;
	int max_size,current_size;
	int front,rare;
    public:
	Queue(int len=4)
	{
		max_size=len;
		current_size=0;
		arr = new T[len];
		front=0;
		rare=-1;
	}

	bool full()
	{
		return current_size==max_size;
	}

	bool empty()
	{
		return current_size==0;
	}

	void push(T data)
	{
		if(!full())
		{
			rare = (rare+1)%max_size;
			arr[rare]=data;
			current_size++;
		}
	}
	
	T top()
	{
		if(!empty())
		{
			return arr[front];	
		}
	}

	void pop()
	{
		if(!empty())
		{
			front = (front+1)%max_size;
			current_size--;
		}
	}

};

int main()
{
	Queue<int> q1;
	q1.push(3);
	q1.push(2);
	cout<<q1.top();
	q1.pop();
	cout<<q1.top();
	q1.pop();
	//q1.push(3);
	q1.push(7);
	cout<<q1.top();	

}
