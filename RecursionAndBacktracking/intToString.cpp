#include<bits/stdc++.h>
using namespace std;

char mapping[27] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

void find(char* input,char* output, int i, int j)
{
	if(input[i]=='\0')
	{
		output[j]='\0';
		cout<<output<<" ";
		return;
	}

	output[j]=mapping[input[i]-'1'+1];
	find(input, output,i+1,j+1);

	if(input[i+1]!='\0' && input[i]!='\0')
	{
		int index= (input[i]-'1'+1)*10 + (input[i+1]-'1'+1);
		if(index<=27)
		{
			output[j]=mapping[index];
			find(input,output,i+2,j+1);
		}
	}
	

}


int main()
{
	
	char output[1000],input[1000];
	cin>>input;
	
	find(input,output,0,0);

}
