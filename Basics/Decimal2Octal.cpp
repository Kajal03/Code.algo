//Take N (number in decimal format). Write a function that converts it to octal format. Print the value returned.
#include<iostream>
using namespace std;
int main()
{
	long long int decimal, octal;
	cin>>decimal;
	int i=1,temp;
	octal = 0;
	while(decimal>0){
		octal+=(decimal%8) * i;
		decimal=(decimal/8);
		i*=10;
	}
	cout<<octal;
}