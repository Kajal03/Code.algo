#include<iostream>
#include<vector>
using namespace std;

string table[] = { "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wx" ,"yz" };


void Keypad(char input[], char output[], int i, int j, int &count)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<" ";
		count++;
		return;
	}

	int digit = input[i] - '1';

	for(int k=0;table[digit][k]!='\0';k++)
	{
		output[j]=table[digit][k];
		Keypad(input, output,i+1,j+1, count);
	}

}

int main()
{
	char input[100], output[100];
	cin>>input;
	int count=0;
	Keypad(input,output,0,0, count);
	cout<<endl<<count<<endl;
	 
}
