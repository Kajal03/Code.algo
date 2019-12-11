/*Write a program that works as a simple calculator.

1.It reads a character (ch)
2.If ch is among '+', '-', '*', '/' or '%' it furthur takes two numbers (N1 and N2 as input). It then performs appropriate appropriate operation between numbers and print the number. 3.If ch is 'X' or 'x', the program terminates.
4.If ch is any other character, the program should print 'Invalid operation. Try again.' and seek inputs again (starting from character).

Write code to achieve above functionality. */

#include<iostream>
using namespace std;
int main()
{
	int n1,n2,result;
	char ch;
	cin>>ch;
	while(ch!='X' && ch!='x'){
		
		switch(ch){
			case '+' : 	cin>>n1>>n2;
						cout<<n1+n2<<endl;
						break;
			case '-' :  cin>>n1>>n2;
						cout<<n1-n2<<endl;
						break;
			case '*' :  cin>>n1>>n2;
						cout<<n1*n2<<endl;
						break;
			case '/' :  cin>>n1>>n2;
						if(n2==0){
							cout<<"Invalid..try again"<<endl;
							break;
						}
						cout<<n1/n2<<endl;
						break;
			case '%' :  cin>>n1>>n2;
						if(n2==%){
							cout<<"Invalid operation. Try again"<<endl;
							break;
						}
						cout<<n1%n2<<endl;
						break;
			default :   cout<<"Invalid operator. Try again.."<<endl;
						break;
			}
		cin>>ch;
	}
}