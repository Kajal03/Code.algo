#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack
{
	vector<T> v;
    public:
	void push(T data)
	{
		v.push_back(data);
	}

	bool empty()
	{
		return v.size()==0;
	}

	void pop()
	{
		if(!empty())
			v.pop_back();
	}

	T top()
	{
		if(!empty())
			return v[v.size()-1];	
	}
		
};

int main()
{

	Stack<char> a;
	a.push('a');
	a.push('b');
	cout<<a.top();	
	a.pop();
	cout<<a.top();
}
