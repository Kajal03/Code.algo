#include<iostream>
#include<stack>
using namespace std;

class myStack
{
   int min;
   stack<int> s;
   public:
	void push(int data)
	{
		if(s.empty())
			min = data;
		else if(data<min)
		{
			min = data;			
			data = 2*data - min;
		}	
		s.push(data);
	}

	void pop()
	{
		if(s.top()<min)
		{
			min = 2*min - s.top();
		}
		s.pop();
	}
	
	int findMin()
	{
		return min;
	}
		

};

int main()
{
	myStack s;
	s.push(1);
	cout<<s.findMin()<<endl;
	s.push(4);
	cout<<s.findMin()<<endl;
	s.push(1);
	cout<<s.findMin()<<endl;
	s.pop();
	cout<<s.findMin()<<endl;

}

