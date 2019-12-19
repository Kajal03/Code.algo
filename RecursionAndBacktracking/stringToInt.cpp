//Convert a string into integer

#include<iostream>
using namespace std;

int convert(char* a, int num){
	if(a[0]=='\0')
		return num;

	num*=10;
	num += a[0] - '0';

	return convert(a+1,num);
	
}

int main()
{
	int a=0;
	char input[100];

	cin>>input;
	//int size = sizeof(input)/sizeof(char);

	a = convert(input, a);

	cout<<a;
}