#include<iostream>
using namespace std;

class Complex
{
	int real;
	int img;
    public:
	Complex()
	{
		real=0;
		img=0;
	}	
	
	Complex(int r, int i)
	{
		real = r;
		img = i;
	}

	void setReal(int r)
	{
		real=r;
	}
	
	void setImg(int i)
	{
		img = i;
	}

	void print()
	{
		if(img>=0)
			cout<<real<<" + "<<img<<"i"<<endl;
		else
			cout<<real<<" - "<<-img<<"i"<<endl;
	}
	
	void operator+(Complex B)
	{
		real+=B.real;
		img+=B.img;
	}

	void operator[](string s)
	{
		if(s=="real")
			cout<<real<<endl;
		else if(s=="img")
			cout<<img<<"i"<<endl;
	}
	
};


/* This does not allow cascading of operators, so we will make new functions
that allow cascading

void operator>>(istream &is, Complex &B)
{
	int r, i;
	is>>r>>i;
	B.setReal(r);
	B.setImg(i);	
}

void operator<<(ostream &os, Complex B)
{
	B.print();
}

*/

istream& operator>>(istream &is, Complex &B)
{
	int i, r;
	is>>r>>i;
	B.setReal(r);
	B.setImg(i);
	return is;
}

ostream& operator<<(ostream &os, Complex &B)
{
	B.print();
	return os;
}

int main()
{
/*	Complex A;
	A.setReal(5);
	A.setImg(-10);
	A.print();

	Complex B(3,2);
	A+B;
	A.print();
	
	Complex C;
	cin>>C;
	//C.print();
	cout<<C;

	Complex D,E;
	cin>>D>>E;
	//D.print();
	//E.print();
	cout<<D<<E;*/

	Complex F;
	cin>>F;
	F["real"];
	F["img"];

}
