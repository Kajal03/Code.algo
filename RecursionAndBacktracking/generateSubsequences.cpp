#include<iostream>
using namespace std;
#define ll long long

ll count=0;

void findSubsequnces(char* input, char* output, int i, int j)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		count++;
		cout<<output<<" ";
		return;
	}

	findSubsequnces(input,output,i+1,j);	
	output[j]=input[i];
	findSubsequnces(input,output,i+1,j+1);
	

}


int main()
{
	char input[1000],output[1000];
	cin>>input;
	findSubsequnces(input,output,0,0);
	cout<<endl<<count<<endl;
}
