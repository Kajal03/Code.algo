#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int findSuperDigit(stack<char> n)
{
	if(n.size()==1)
	{
		int a = n.top()-'1'+1;	
		n.pop();	
		return a;
	}


	int a = n.top()-'1'+1;
	n.pop();
	int b = n.top()-'1'+1;
	n.pop();

	a+=b;
	while(a>0)
	{
		b=a%10;
		n.push(b + '1'-1);
		a=a/10;
	}

	return findSuperDigit(n);
	
}


int main()
{
	stack<char>n;
	int i=0,k,b;
	string a;
	cin>>a;
	cin>>k;
	while(a[i]!='\0')
	{
		n.push(a[i]);
		i++;
	}

	int temp = findSuperDigit(n);

	temp*=--k;
	while(temp>0)
	{
		b = temp%10;
		n.push(b + '1'-1);
		temp/=10;

	}
	
	cout<<findSuperDigit(n)<<endl;

}
