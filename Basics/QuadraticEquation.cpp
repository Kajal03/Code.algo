//Given coefficients of a quadratic equation , you need to print the nature of the roots (real and distinct , real and equal , imaginary).
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,c;
	float root1,root2,D;
	cin>>a>>b>>c;
	D = (b*b) - (4*a*c);
	if(D==0){
		cout<<"Real and Equal\n";
		root1 = -b/(2*a);
		cout<<root1<<" "<<root1;
	}
	else if(D<0){
		cout<<"Imaginary";
	}
	else if(D>0){
		cout<<"Real and Distinct\n";
		root1 = (-b + sqrt(D))/2*a;
		root2 = (-b - sqrt(D))/2*a;
		cout<<root1<<" "<<root2;
	}
}