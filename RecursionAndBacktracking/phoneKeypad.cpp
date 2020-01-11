#include<iostream>
using namespace std;

char keypad[][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void mapKeypad(char input[], char output[], int i, int j)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<", ";
		return;
	}

	int digit = input[i] - '0';
	if(digit==0 || digit==1)
		return mapKeypad(input,output,i+1,j);

	for(int k=0;keypad[digit][k]!='\0';k++)
	{
		output[j]=keypad[digit][k];
		mapKeypad(input, output,i+1,j+1);
	}

	mapKeypad(input, output,i+1,j);

}

int main()
{
	char input[100], output[100];
	cin>>input;

	mapKeypad(input,output,0,0); 
}
