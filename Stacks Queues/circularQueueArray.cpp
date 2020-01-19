#include<iostream>
using namespace std;

class CircularArray
{

int *a;
int current_size,max_size, front, rear;
   public:
	CircularArray(int n)
	{
		a = new int[n];
		front = 0;
		rear = n-1;
		max_size=n;
		current_size=0;
	}

	bool isEmpty()
	{
		return current_size==0;
	}
	
	bool isFull()
	{
		return current_size == max_size;
	}
	
	void enqueque(int data)
	{
		if(!isFull())
		{
			rear = (rear+1)%max_size;
			a[rear]=data;
			current_size++;
		}
	}
	int getFront()
	{
		return a[front];
	}
	void dequeue()
	{
		if(!isEmpty())
		{
			front = (front+1)%max_size;
			current_size--;
		}
	}

};

int main()
{

	int n=6;
	CircularArray Q(6);
	for(int i=0;i<6;i++)
	{
		Q.enqueque(i);
	}
	cout<<Q.getFront()<<endl;
	Q.dequeue();
	cout<<Q.getFront()<<endl;
	Q.dequeue();
	cout<<Q.getFront()<<endl;
	Q.dequeue();
	cout<<Q.getFront()<<endl;
	Q.dequeue();
	cout<<Q.getFront()<<endl;

}
